#include <iostream>
#include "Book.hpp"
#include "User.hpp"
#include "Inventory.hpp"
#include <string>
#include <fstream>
using namespace std;

//Define inventory as global variable with _ attached to signify that it's global
Inventory _inventory;

void AddBook()
{
                cout << "Enter book Title:"; 
                string title;
                getline(cin, title);
                cout << "Enter book Author:"; 
                string author;
                // get full title of book with get line0
                getline(cin, author);
                
                Book newBook(title, author);
                // This adds the new book to the inventory
                _inventory.addBook(newBook);
}
    
void ListBooks()
{
    _inventory.listAllBooks();
}


//Check if requested book is available 
void CheckInOrOutBook(bool checkOut)
{
    string CheckinOrOut;
    if(checkOut)
    {
        CheckinOrOut = "out";
    }
    else
    {
        CheckinOrOut = "in";
    }
                cout << "Please enter a Book Title to check " + CheckinOrOut + ": ";
                string title;
                getline(cin, title);
                
               CheckInOrOutResult result =  _inventory.checkInOrOutBook(title, checkOut);
                //Check cases and returns appropriate prompt
                if(result == CheckInOrOutResult::BookNotFound)
                {
                    cout << "Book not found";
                }
                else if (result == CheckInOrOutResult::Success)
                {
                    cout << "Book checked" + CheckinOrOut + "." << endl;
                }
                else if(result == CheckInOrOutResult::AlreadyCheckedIn || 
                result == CheckInOrOutResult::CheckoutAlready)
                {
                    cout << "This book has already been" + CheckinOrOut + "." << endl;
                }
                else
                {
                    cout << "Check in or out process  failed" << endl;
                }
            
}

void DeleteBook()
{
                cout << "Enter book Title:"; 
                string title;
                getline(cin, title);
                
                // This deletes the new book to the inventory
                _inventory.deleteBook(title);
            }



vector<User> _users;
User _loggedInUser;

void loadUserData()
{
    ifstream inputFile("user_data.txt");
    string userLine;
    getline(inputFile, userLine);
}
int getRoleValue(Role role)
{
    //Convert Role to int value
    int roleValue = -1;
    if(role == Role::Administrator)
    {
        roleValue = 0;
    }
    else if(role == Role::Staff)
    {
        roleValue = 1;
    }
    else if(role == Role::Student)
    {
        roleValue = 2;
    }
    return roleValue;
}
//Create new account function
void CreateNewAccount()
{
    User newUser;
//    cout << "First Name: ";
//    string fName;
//    getline(cin, fName);
//    cout << "Last Name: ";
//    string lName;
//    getline(cin, lName);
    cout << "Create User Name: ";
    getline(cin, newUser.userName);
    
    cout << "What is your role?: " << endl;
    cout << "1.Administrator: " << endl;
    cout << "2.Staff: " << endl;
    cout << "3.Student: " << endl;
    
    int roleOption;
    cin >> roleOption;
    cin.ignore();
    //Based on option, grant role to new user
    if(roleOption == 1)
    {
        newUser.Role = Role::Administrator;
    }
    else if (roleOption == 2)
    {
        newUser.Role = Role::Staff;
    }
    else
    {
        newUser.Role = Role::Student;
    }
    //Push new user into _user vector
    _users.push_back(newUser);
    
    //Append whatever is added to the file.stops from overriding 
    ofstream outFile("user_data.txt", ios_base::app);
    // Get user name and role value of the user
    outFile << newUser.userName << " | " << getRoleValue(newUser.Role) << endl;
    outFile.close();
}

//User login function with options
void UserLogin()
{
    
    cout << "Pick an option: ";
    cout << "1. Login: ";
    cout << "2. Create New Account: ";
    
    int option;
    cin >> option;
    cin.ignore();
    
    if(option == 2)
    {
        CreateNewAccount();
    }
 
 while (true){
    cout << "Please Enter Your User Name: ";
    string userName;
    getline(cin, userName);
    
    
    User user;
    user.userName = userName;
    //find and compare existing username inside vector
    vector<User>::iterator it = find(_users.begin(), _users.end(), user);
    
    //If user is found
    if(it != _users.end())
    {
        //find where the user object is located
        _loggedInUser = _users[it - _users.begin()];
        break;
        }
    
    }
}
void DisplayMenu()
{   
    cout << endl;
    cout << "Pick an option: ";
     if (_loggedInUser.Role == Role::Administrator
     || _loggedInUser.Role == Role::Staff)
     {
         cout << "\n1. Add Book" << endl;
         cout << "\n5. Delete book from Inventory " << endl;
         cout << "\n6. Display Checked out books " << endl;
     }
     
        cout << "\n2. List available books"
             << "\n3. Checkout book"
             << "\n4. Return book "
             << "\n0. Exit" << endl;
             
}


void DisplayCheckedOutBook()
{
    _inventory.listCheckedOutbooks();
}

int main(){
    
    while (true)
    {
        loadUserData();
        UserLogin();
        DisplayMenu();
        
        int userInput;
        cin >> userInput;
        cin.ignore();
        switch(userInput)
        {
            case 0:
                cout << "Goodbye" << endl;
                return 0;
                break;
    
            case 1:// Add a book
                AddBook();
            break;
            
            case 2: // List all available books
                ListBooks();
                break;
        
            case 3: // checkout book
                CheckInOrOutBook(true);
            break;
            
            case 4: // return book
                CheckInOrOutBook(false);
            break;
            
            case 5: // Delete Book
                DeleteBook();
            break;
            case 6:
                DisplayCheckedOutBook();
            break;
            \
            default:
                cout << "Sorry invalid selection , please try again" << endl;
            break;
            
            
        }
        
    }
}





//void CheckOutBook()
//{
//                cout << "Please enter a Book Title: ";
//                string title;
//                getline(cin, title);
//                // Will return an index value
//                int bookExistsIndex = _inventory.findBookByTitle(title);
//                // If index is greater than or equla to 0 book exists
//                if(bookExistsIndex >= 0)
//                {
//                    //reference locatin of book using pointer, get exact location in memory
//                    Book* bookExists = &_inventory.Books[bookExistsIndex];
//                    
//                    // check if book is checked out before checking it in
//                    if(bookExists->CheckedOut) // get object at the pointer
//                    {
//                        cout << "This book has been checked out already, please try another title.\n";
//                        return;
//                    }
//                    _inventory.checkOutBook(bookExists);
//                    cout << "Enjoy your new book, remember late our fee is $500 per day after" << endl;
//                }
//                else
//                {
//                    cout << "Sorry " << title << " does not exist in this Inventory\n" << endl;
//                }
//            }

//void ReturnBook()
//{
//                
//                cout << "Which Book are you returning: ";
//                string title;
//                getline(cin, title);
//                int bookExistsIndex = _inventory.findBookByTitle(title);
//    
//                // If book does exists and is checkedout 
//                if(bookExistsIndex >= 0)
//                {
//                    Book* bookExists = &_inventory.Books[bookExistsIndex]; 
//                    // check if book is checked in before checking it in
//                    if(!bookExists->CheckedOut)
//                    {
//                        cout << "This book has been returned in already";
//                        return;
//                    }
//                    _inventory.returnBook(bookExists);
//                    cout << "You just returned: " <<  title << endl;
//                }
//                else
//                {
//                    cout << "Sorry" << title << "does not exist in this Inventory" << endl;
//                }
//            }
