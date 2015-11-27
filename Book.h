#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using std::string;
class Book
{
public:
	Book();
	void setId(int _id);
	void setName(string _name);
	void setWriter(string _writer);
	void setPublishTime(long _publishTime);
	void setIfBorrowed(int i);
	int getIfBorrowed();
	int getId();
	string getName();
	string getWriter();
	long getPublishTime();
	Book* operator=(Book& _book);
private:
	int id;
	string name;
	string writer;
	long publishTime;
	int ifBorrowed;//1 not borrowed, 0 borrow
};
#endif



