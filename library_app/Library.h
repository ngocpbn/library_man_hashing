#pragma once
#include <string>
#include "Book.h"

#define LIBRARY_SIZE 100
using namespace std;

/// <summary>
/// IMPLEMENT LIBRARY MANAGEMENT USING HASHING TECHNIQUE
/// </summary>
class Library
{
private:
	Book * library = new Book[LIBRARY_SIZE];		// The hash table
public:
	Library();
	//library(Book )

	// Takes book ID as key and return its index in the libray hash table
	int hashFunc(int bookId);	
	void addNewBook(Book book);
	void viewBookDetail(int bookId);
	void viewAllBooks();
	void findBookPosition(int bookId);

	~Library();
};

