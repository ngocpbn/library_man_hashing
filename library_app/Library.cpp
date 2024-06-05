#include "Library.h"
#include <iostream>
#include <iomanip>
#include <string>

Library::Library() {
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		Book book(-1,"","","",-1);
		library[i] = book;
	}
}

int Library::hashFunc(int bookId) {
	return bookId % LIBRARY_SIZE;
}

int Library::findBookIndex(int bookId) {
	int index, hashKey = hashFunc(bookId);

	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		index = hashFunc(hashKey + i);
		if (library[index].getId() == bookId)
		{
			return index;
		}
		else if (library[index].getId() == -1)
		{
			return -1;
		}
	
	}

	return -1;
}

int Library::addNewBook(Book book) {
	int index, hashKey;
	hashKey = hashFunc(book.getId());

	// Collision resolution - linear probing
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		index = hashFunc(hashKey + i);
		if (library[index].getId() == -1)
		{
			library[index] = book;
			return 1;
		}
	}
	return -1; // failed to insert book
}

void Library::viewBookDetail(int bookId) {
	int index = findBookIndex(bookId);
	if (index == -1)
	{
		cout << "No book in library has ID " << bookId << ". Please try again." << endl;
		return;
	}
	Book book = library[index];

	cout << left << setw(8) << "Index"
		<< setw(8) << "BookID"
		<< setw(25) << "Title"
		<< setw(25) << "Author"
		<< setw(20) << "Publisher"
		<< setw(15) << "Number of pages"
		<< endl;

	string title = book.getTitle();
	string author = book.getAuthor();
	string publisher = book.getPublisher();
	int noOfPages = book.getNoOfPages();
	
	cout << left << setw(8) << index
		<< setw(8) << bookId
		<< setw(25) << title
		<< setw(25) << author
		<< setw(20) << publisher
		<< setw(15) << noOfPages
		<< endl;

}

void Library::viewAllBooks() {
	
	cout << left << setw(8) << "Index"
		<< setw(8) << "BookID"
		<< setw(25) << "Title"
		<< setw(25) << "Author"
		<< setw(20) << "Publisher"
		<< setw(15) << "Number of pages"
		<< endl;
	
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		if (library[i].getId() != -1) {
			int bookId = library[i].getId();
			string title = library[i].getTitle();
			string author = library[i].getAuthor();
			string publisher = library[i].getPublisher();
			int noOfPages = library[i].getNoOfPages();	

			cout << left << setw(8) << i
				<< setw(8) << bookId
				<< setw(25) << title
				<< setw(25) << author
				<< setw(20) << publisher
				<< setw(15) << noOfPages
				<< endl;
		}
	}
}

void Library::viewAllBooksShort() {
	cout << "BookID			Title" << endl;
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		if (library[i].getId() != -1) {
			int bookId = library[i].getId();
			string title = library[i].getTitle();
			cout << bookId << "			" << title << endl;
		}
	}
}

int Library::editABook(int index,Book book) {
	library[index] = book;
	return 1; // edit book successfully
}

int Library::deleteABook(int bookId) {
	int index = findBookIndex(bookId);
	if (index == -1)
	{
		cout << "No book in library has ID " << bookId << ". Please try again." << endl;
		return -1;
	}
	Book book(-1, "", "", "", -1);
	library[index] = book;
	return 1;	// delete book sucessfully
}

bool Library::idExist(int id) {
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		if (library[i].getId() == id) {
			return true;
		}
	}
	return false;
}

Library::~Library() {
	delete[] library;
}