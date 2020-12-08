#pragma once
#include <iostream>
using namespace std;

//
class Book
{
private:
    
    string bookTitle;
    string Author;
    bool CheckedOut;
    
public:
    
    
//  
    int bookId;
    Book();
    Book(string title, string author);
    void checkInOrOut(bool checkOut);
    void displayBook();
    bool isCheckedOut();
    
    //No values in function will be changed
    bool operator == (const Book &book) const
    {
        // check If title and user input in title matches 
        if(bookTitle.compare(book.bookTitle) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

