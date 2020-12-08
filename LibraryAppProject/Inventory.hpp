#pragma once
#include "Book.hpp"
#include <iostream>
#include <vector>
#include "CheckInOrOutResult.hpp"


class Inventory
{
private:
    vector<Book> Books;
public:
    
    
    void listAllBooks();
    void listCheckedOutbooks();
    Book getBookByIndex(int index);
    int getNumOfBooks();
    void addBook(Book book);
    void deleteBook(string title);
    int findBookByTitle(string title);
    CheckInOrOutResult checkInOrOutBook(string title, bool checkOut);

};

