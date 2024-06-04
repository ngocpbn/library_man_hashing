
// LIBRARY MANAGEMENT APP USING LINEAR PROBING TECHNIQUE
#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

Library myLibrary;
void option1Addbook();
void option3DeleteBook();
void option4ViewBookDetail();

int main()
{
    Book book1(11, "Gone", "Malcom", "Penguin", 190);
    myLibrary.addNewBook(book1);

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
            option1Addbook();
            break;
        case 2:
            break;
        case 3:
            option3DeleteBook();
            break;
        case 4:

            break;
        case 5: 
            myLibrary.viewAllBooks();
            break;
        default:
            cout << "Invalid option. Please try again.";
            break;
        }
    }

    
    Book book2(99, "Gone", "Malcom", "Penguin", 190);
    Book book3(111, "Gone", "Malcom", "Penguin", 190);
    Book book4(99, "Hello", "Malcom Gladwell", "Penguin", 190);
    //cout << book1.getTitle();
    Book bookList[100] = {};

    
    
    myLibrary.addNewBook(book3);
    myLibrary.addNewBook(book2);
    //myLibrary.viewAllBooks();
    myLibrary.viewAllBooksShort();
    myLibrary.deleteABook(13);
    myLibrary.viewAllBooks();
    
    return 0;
}

int validateInputBookID(bool option1 = false) {
    int bookId;
    bool idExists = false;
    do
    {
        cout << "Book ID: ";
        cin >> bookId;
        if (myLibrary.idExist(bookId))
        {
            if (option1)
            {
                cout << "This ID is not available. Please try another ID." << endl;
            }
            else
            {
                cout << "Invalid book ID. Please try again." << endl;
            }
            idExists = true;
        }
        else
        {
            idExists = false;
        }
    } while (idExists);
    return bookId;
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

    cout << "Book title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Author(s): ";
    getline(cin, author);

    cout << "Publisher: ";
    getline(cin, publisher);

    cout << "Number of pages: ";
    cin >> noOfPages;
    cin.ignore();

    Book newBook(bookId, title, author, publisher, noOfPages);
    int result = myLibrary.addNewBook(newBook);
    if (result == 1)
    {
        cout << "New book added successfully!" << endl;
    }
    else
    {
        cout << "Failed to add new book!" << endl;
    }
    cout << endl;
}

void option3DeleteBook() {
    int bookId;
    myLibrary.viewAllBooksShort();
    cout << "Enter the ID of the book you want to delete." << endl;

    bool idExists = false;
    do
    {
        cout << "Book ID: ";
        cin >> bookId;
        if (myLibrary.idExist(bookId) == false)
        {
            cout << "Invalid book ID. Please try again." << endl;
        }
        else
        {
            idExists = true;
        }
    } while (!idExists);

    int result = myLibrary.deleteABook(bookId);
    if (result == 1)
    {
        cout << "Book deleted successfully!" << endl;
    }
    else
    {
        cout << "Failed to delete book!" << endl;
    }
    cout << endl;
}

void option4ViewBookDetail() {
    myLibrary.viewAllBooksShort();
    cout << "Enter the ID of the book you want to see in detail." << endl;
    cout << "Book ID: ";

}