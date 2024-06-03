
// LIBRARY MANAGEMENT APP USING LINEAR PROBING TECHNIQUE
#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
    Book book1(11,"Gone","Malcom", "Penguin", 190);
    Book book2(2, "Gone", "Malcom", "Penguin", 190);
    //cout << book1.getTitle();
    Book bookList[100] = {};
    //bookList[1] = book1;
    //bookList[3] = book2;
    ////cout << bookList[0].getId();
    //for (int i = 0; i < 5; i++)
    //{
    //    cout << bookList[i].getId() << endl;
    //}
    
    Library myLibrary;
    myLibrary.addNewBook(book1);
    myLibrary.addNewBook(book1);
    myLibrary.addNewBook(book2);
    myLibrary.viewAllBooks();
    return 0;
}

