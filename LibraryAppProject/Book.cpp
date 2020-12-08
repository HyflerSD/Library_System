#include "Book.hpp"

#include <iostream>


// Create sample book constructor
Book::Book(){};

Book::Book(string title, string author)
{
//  Initialize Values
    Book::CheckedOut = false;
    Book::bookTitle = title;
    Book::Author = author;
    
}


//Set checked out value
void Book::checkInOrOut(bool checkOut)
{
    CheckedOut = checkOut;
}

void Book::displayBook()
{
    cout <<bookId<< "\t" << bookTitle << "\t" << Author << endl; 
}

bool Book::isCheckedOut()
{
    return CheckedOut;
}
