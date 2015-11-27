#include "BookDatabase.h"
BookDatabase::~BookDatabase()
{
	if (BookDatabase::bookdatabase)
	{
		delete BookDatabase::bookdatabase;
	}
	delete first;
}

BookDatabase* BookDatabase::bookdatabase = new BookDatabase();
BookDatabase* BookDatabase::GetBookdatabase()
{
	return BookDatabase::bookdatabase;
}

BookDatabase::BookDatabase()
{
	n = 0;
	first = NULL;
}


void BookDatabase::Insert(Book& _book)
{
	Node* p = new Node;
	p->book = _book;
	p->next = NULL;
	if (n == 0)
	{
		first = p;
		n++;
	}
	else{
		Node* q = first;
		for (int i = 0; i < n-1; i++)
		{
			q = q->next;
		}
		q->next = p;
		n++;
	}
}