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
	int addNewBook(Book book);
	void viewBookDetail(int bookId);
	void viewAllBooks();
	void viewAllBooksShort();
	int findBookIndex(int bookId);
	int editABook(int index,Book book);
	int deleteABook(int bookId);
	bool idExist(int id);
	/// <summary>
	/// maybe add sort too? no. nobody sorts hash table :)
	/// </summary>

	~Library();
};

