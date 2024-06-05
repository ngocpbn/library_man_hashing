
// LIBRARY MANAGEMENT APP USING LINEAR PROBING TECHNIQUE
#include <iostream>
#include <limits>
#include "Book.h"
#include "Library.h"
using namespace std;

Library myLibrary;
void option1Addbook();
void option2EditBook();
void option3DeleteBook();
void option4ViewBookDetail();

int main()
{

    Book book1(11, "Gone with the wind", "Margaret Mitchell", "Penguin", 123);
    Book book2(99, "Outliers", "Malcom Gladwell", "Penguin", 150);
    Book book3(111, "Thinking, fast & slow", "Daniel Kahneman", "Penguin", 195);
    Book book4(678, "The Little Prince", "Antoine de Saint-Exupery", "Penguin", 186);

    myLibrary.addNewBook(book1);
    myLibrary.addNewBook(book2);
    myLibrary.addNewBook(book3);
    myLibrary.addNewBook(book4);

    bool running = true;
    cout << "####################################################################################"<<endl;
    cout << "__      __ _   _  _    _  _____   _____   _       _  _                              " << endl;
    cout << "\\ \\    / /| \\ | || |  | ||_   _| / ____| | |     (_)| |                             " << endl;
    cout << " \\ \\  / / |  \\| || |  | |  | |  | (___   | |      _ | |__   _ __  __ _  _ __  _   _ " <<  endl;
    cout << "  \\ \\/ /  | . ` || |  | |  | |   \\___ \\  | |     | || '_ \\ | '__|/ _` || '__|| | | |" << endl;
    cout << "   \\  /   | |\\  || |__| | _| |_  ____) | | |____ | || |_) || |  | (_| || |   | |_| |" << endl;
    cout << "    \\/    |_| \\_| \\____/ |_____||_____/  |______||_||_.__/ |_|   \\__,_||_|    \\__, |" << endl;
    cout << "                                                                               __/ |" << endl;
    cout << "                                                                              |___/ " << endl;
    cout << "####################################################################################" << endl;
    cout << endl << endl << endl;
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
            option2EditBook();
            break;
        case 3:
            option3DeleteBook();
            break;
        case 4:
            option4ViewBookDetail();
            break;
        case 5: 
            myLibrary.viewAllBooks();
            cout << endl;
            break;
        default:
            cout << "Invalid option. Please try again."<<endl;
            break;
        }
    }
    
    return 0;
}

// ONLY LET USERS CONTINUE IF THE ID EXISTS IN THE TABLE
int validateInputBookID(bool option1 = false) {
    int bookId;
    bool idExists = false;
    do
    {
        cout << "Book ID: ";
        cin >> bookId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        idExists = myLibrary.idExist(bookId);
        if (idExists == false)
        {
            cout << "There's no book with this ID. Please try again." << endl;
        }
    } while (!idExists);
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        idExists = myLibrary.idExist(bookId);
        if (idExists)
        {
            cout << "This ID is not available. Please try another ID." << endl;
        }
    } while (idExists);

    cout << "Book title: ";
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

void option2EditBook() {
    myLibrary.viewAllBooks();
    cout << "Enter the ID of the book you want to edit." << endl;
    int bookId = validateInputBookID();

    string title;
    string author;
    string publisher;
    int noOfPages;
    cout << "Book title: ";
    getline(cin, title);

    cout << "Author(s): ";
    getline(cin, author);

    cout << "Publisher: ";
    getline(cin, publisher);

    cout << "Number of pages: ";
    cin >> noOfPages;
    cin.ignore();

    int index = myLibrary.findBookIndex(bookId);
    if (index == -1)
    {
        cout << "Something went wrong. Please try again." << endl;
    }
    else
    {
        myLibrary.editABook(index, Book(bookId, title, author, publisher, noOfPages));
        cout << "Book edited sucessfully." << endl;
    }

    cout << endl;
}

void option3DeleteBook() {
    myLibrary.viewAllBooksShort();
    cout << "Enter the ID of the book you want to delete." << endl;
    int bookId = validateInputBookID();

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
    int bookId = validateInputBookID();
    myLibrary.viewBookDetail(bookId);
    cout << endl;
}