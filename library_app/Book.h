#pragma once
#include <string>
using namespace std;
class Book
{
private:
	int id;
	string title;
	string author;
	string publisher;
	int noOfPages;
public:
	Book();
	Book(int id, string title, string author, string publisher, int noOfPages);
	int getId();
	string getTitle();
	string getAuthor();
	string getPublisher();
	int getNoOfPages();
	~Book();
};

