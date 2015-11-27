#include "Book.h"
Book* Book::operator=(Book& _book)
{
	id = _book.id;
	name = _book.name;
	writer = _book.writer;
	publishTime = _book.publishTime;
	ifBorrowed = _book.ifBorrowed;
	return this;
}

Book::Book()
{
	id = -1;
	name = " ";
	writer = " ";
	publishTime = 0;
	ifBorrowed = 1;
}
void Book::setId(int _id){ id = _id; }
void Book::setName(string _name){ name = _name; }
void Book::setWriter(string _writer){ writer = _writer; }
void Book::setPublishTime(long _publishTime){ publishTime = _publishTime; }
void Book::setIfBorrowed(int i){ ifBorrowed = i; }
int Book::getIfBorrowed(){ return ifBorrowed; }
int Book::getId(){ return id; }
string Book::getName(){ return name; }
string Book::getWriter(){ return writer; }
long Book::getPublishTime(){ return publishTime; }