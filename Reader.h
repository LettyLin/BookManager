#include "BookDatabase.h"
#include <iostream>
#include <string>
using std::string;
using namespace std;

class Reader
{
public:
	void BorrowBook(int _id);
	void ReturnBook(int _id);
	void setId(int _id);
	void setPassword(string _password);
	int getId();
	string getPassword();
	Reader* operator=(Reader& _reader);
private:
	int id;
	string password;
};

Reader* Reader::operator=(Reader & _reader)
{
	id = _reader.id;
	password = _reader.password;
	return this;
}
void Reader::setId(int _id)
{
	id = _id;
}
void Reader::setPassword(string _password)
{
	password = _password;
}
int Reader::getId(){
	return id;
}
string Reader::getPassword()
{
	return password;
}
void Reader::BorrowBook(int _id)
{
	BookDatabase* bookdatabase = BookDatabase::GetBookdatabase();
	Node *p = bookdatabase->getFirst();
	while (p->book.getId() != _id)
	{
		p = p->next;
	}
	if (!p)
	{
		cout << "dont have the book" << endl;
	}
	else{
		p->book.setIfBorrowed(0);
		cout << "Done!" << endl;
	}
}

void Reader::ReturnBook(int _id)
{
	BookDatabase* bookdatabase = BookDatabase::GetBookdatabase();
	Node *p = bookdatabase->getFirst();
	while (p->book.getId() != _id)
	{
		p = p->next;
	}
	if (!p)
	{
		cout << "Dont have the book" << endl;
	}
	else{
		p->book.setIfBorrowed(1);
		cout << "Done" << endl;
	}
}