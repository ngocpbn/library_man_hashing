
// LIBRARY MANAGEMENT APP USING LINEAR PROBING TECHNIQUE
#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

Library myLibrary;
void option1Addbook();

int main()
{
    bool running = true;

    while (running) {
        cout << "WELCOME TO VNUIS LIBRARY!" << endl;
        cout << endl;
        cout << "1. Add a new book." << endl;
        cout << "2. Edit a book." << endl;
        cout << "3. Delete a book." << endl;
        cout << "4. View a book." << endl;
        cout << "5. View all books." << endl;
        cout << "6. Quit library." << endl;
        cout << endl;
        cout << "Please choose an option: ";

        int option;
        cin >> option;
        
        switch (option)
        {
        case 6:
            cout << "Goodbye! :)" << endl;
            running = false;
            break;
        case 1:
            // write a function for this case
            option1Addbook();
            break;
        default:
            cout << "Invalid option. Please try again.";
            break;
        }
    }

    Book book1(11,"Gone","Malcom", "Penguin", 190);
    Book book2(99, "Gone", "Malcom", "Penguin", 190);
    Book book3(111, "Gone", "Malcom", "Penguin", 190);
    Book book4(99, "Hello", "Malcom Gladwell", "Penguin", 190);
    //cout << book1.getTitle();
    Book bookList[100] = {};

    
    myLibrary.addNewBook(book1);
    myLibrary.addNewBook(book3);
    myLibrary.addNewBook(book2);
    //myLibrary.viewAllBooks();
    myLibrary.viewAllBooksShort();
    myLibrary.deleteABook(13);
    myLibrary.viewAllBooks();
    
    return 0;
}

void option1Addbook() {
    int bookId;
    string title;
    string author;
    string publisher;
    int noOfPages;
    cout << "Please enter the information for the book." << endl;
    bool idExists = false;
    do
    {
        cout << "Book ID: ";
        cin >> bookId;
        if (myLibrary.idExist(bookId))
        {
            cout << "This ID is not available. Please try another ID." << endl;
            idExists = true;
        }
        else
        {
            idExists = false;
        }
    } while (idExists);


}