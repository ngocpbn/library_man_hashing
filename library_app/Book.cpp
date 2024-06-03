#include "Book.h"

Book::Book() {
	this->id = -1;
	this->title = "";
	this->author = "";
	this->publisher = "";
	this->noOfPages = -1;
}

Book::Book(int id, string title, string author, string publisher, int noOfPages) {
	this->id = id;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->noOfPages = noOfPages;
}

int Book::getId() {
	return this->id;
}

string Book::getTitle() {
	return this->title;	
}

string Book::getAuthor() {
	return this->author;
}

string Book::getPublisher() {
	return this->publisher;
}

int Book::getNoOfPages() {
	return this->noOfPages;
		
}

Book::~Book() {}