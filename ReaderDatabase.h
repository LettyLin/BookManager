#include "Reader.h"
struct ReaderNode
{
	ReaderNode(){ next = NULL; }
	~ReaderNode(){ delete next; }
	Reader reader;
	ReaderNode* next;
};
class ReaderDatabase
{
public:
	void Insert(Reader& _reader);
	ReaderDatabase();
	~ReaderDatabase();
	ReaderNode* getFirst();
	int getCount();
private:
	ReaderNode* first;
	int n;
};

int ReaderDatabase::getCount()
{
	return n;
}
ReaderNode* ReaderDatabase::getFirst()
{
	return first;
}

void ReaderDatabase::Insert(Reader& _reader)
{
	ReaderNode* p = new ReaderNode();
	p->reader = _reader;
	p->next = NULL;
	if (n == 0)
	{
		first = p;
		n++;
	}
	else{
		ReaderNode* q = first;
		for (int i = 0; i < n - 1; i++)
		{
			q = q->next;
		}
		q->next = p;
		n++;
	}
}

ReaderDatabase::ReaderDatabase()
{
	n = 0;
	first = NULL;
}
ReaderDatabase::~ReaderDatabase()
{
	delete first;
}