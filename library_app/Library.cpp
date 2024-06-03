#include "Library.h"
#include <iostream>
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

void Library::addNewBook(Book book) {
	int index, hashKey;
	hashKey = hashFunc(book.getId());

	// Collision resolution - linear probing
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		index = hashFunc(hashKey + i);
		if (library[index].getId() == -1)
		{
			library[index] = book;
			return;
		}
	}
}

void Library::viewAllBooks() {
	cout << "Index		BookID			Title			Author			Publisher		Number of pages" << endl;
	for (int i = 0; i < LIBRARY_SIZE; i++)
	{
		if (library[i].getId() != -1) {
			int bookId = library[i].getId();
			string title = library[i].getTitle();
			string author = library[i].getAuthor();
			string publisher = library[i].getPublisher();
			int noOfPages = library[i].getNoOfPages();	
			cout << i<<"		"<< bookId <<"			"<< title<<"			"<< author <<"			"<< publisher <<"			"<< noOfPages << endl;
		}
	}
}

Library::~Library() {
	delete[] library;
}