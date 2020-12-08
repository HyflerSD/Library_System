#include "Inventory.hpp"



//returns size of vector to pull books id
int Inventory::getNumOfBooks()
{
    return Inventory::Books.size();
}

//Get the book by it's imdex value
Book Inventory::getBookByIndex(int index)
{
    return Inventory::Books[index];
}

//Add book function 
void Inventory::addBook(Book book)
{
    //Last item in vector should always be highest id
    Book lastBook = Books.back();
    book.bookId = (lastBook.bookId + 1);
    //add books to vector ... next book id will be one greater than current last book id
    Inventory::Books.push_back(book);
}

//Delete book function 
void Inventory::deleteBook(string title)
{
    
    ///Traverse (iterate through) vector to find matching title
    vector<Book>::iterator it = find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));
    
    if ( it != Inventory::Books.end())
    {
        //erase book at iterator
        Inventory::Books.erase(it);
    }
}

//Find book function
int Inventory::findBookByTitle(string title)
{
    //Traverse (iterate through) vector to find matching title
    vector<Book>::iterator it = find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));
    
    if ( it == Inventory::Books.end())
    {
        return -1;
    }
    // Find where iterator is offset from the beginning
    int index = it - Inventory::Books.begin();
    return index;
}

//Function to check if book is checkeck out of inventory, will return bool
CheckInOrOutResult Inventory::checkInOrOutBook(string title, bool checkOut)
{
    
   int bookExistsIndex =  findBookByTitle(title);
   // Check if book exists
   if(bookExistsIndex < 0)
   {
       return CheckInOrOutResult::BookNotFound;
   }
   // If book is checked out display already checked out
   else if(checkOut == Books[bookExistsIndex].isCheckedOut())
   {
       if (checkOut)
       {
           return CheckInOrOutResult::CheckoutAlready;
       }
   // If book is checked in display already checked in    
       else
       {
           return CheckInOrOutResult::AlreadyCheckedIn;
       }
   }
    Books[bookExistsIndex].checkInOrOut(checkOut);
    return CheckInOrOutResult::Success;
}

void Inventory::listAllBooks()
// Goes through collection of books in inventory and displays each book in the book class
{
    cout << "\nID\tTitle\tAuthor\t" << endl;
    //display each book
                for(int i = 0; i < getNumOfBooks(); i++)
                {
                    Books[i].displayBook();
                }
                cout << endl;
            return;
}

void Inventory::listCheckedOutbooks()
// Goes through collection of books in inventory and displays each book in the book class
{
    cout << "\nID\tTitle\tAuthor\t" << endl;
    //display each book
                for(int i = 0; i < getNumOfBooks(); i++)
                {
                    //gets book object based on index
                    if(getBookByIndex(i).isCheckedOut())
                    {
                        Books[i].displayBook();
                        cout <<"testing listcheckedoutbooks";
                    }
                }
//                cout <<"testing listcheckedoutbooks2";
                cout << endl;
}