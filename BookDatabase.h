#include <iostream>
#include <fstream>
#include "Book.h"
using namespace std;
struct Node
{
	Node(){ next = NULL; }
	~Node(){ delete next; }
	Book book;
	Node* next;
};

class BookDatabase
{
private:
	BookDatabase();
	int n;
	Node* first;
	static BookDatabase* bookdatabase;
public:
	~BookDatabase();
	void Insert(Book& _book);
	static BookDatabase* GetBookdatabase();
	Node* getFirst(){ return first; }
};
