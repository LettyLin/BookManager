#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ReaderDatabase.h"
using namespace std;

void main()
{
	BookDatabase* bd = BookDatabase::GetBookdatabase();
	ifstream inFile;
	inFile.open("books.txt");
	if (!inFile.is_open())
	{
		cout << "cannot open the file." << endl;
		exit(EXIT_FAILURE);
	}
	string temp;
	string s1, s2, s3, s4;
	while (getline(inFile, temp))
	{
		istringstream is(temp);
		is >> s1 >> s2 >> s3 >> s4;

		Book p;
		p.setId(atoi(s1.c_str()));
		p.setName(s2);
		p.setWriter(s3);
		p.setPublishTime(atoi(s4.c_str()));
		p.setIfBorrowed(1);

		bd->Insert(p);
	}
	
	ReaderDatabase* readerdatabase = new ReaderDatabase();
	ifstream inFile0;
	inFile0.open("students.txt");
	if (!inFile0.is_open())
	{
		cout << "cannot open the file." << endl;
		exit(EXIT_FAILURE);
	}
	string temp0;
	string s5,s6;
	while (getline(inFile0, temp0))
	{
		istringstream is(temp0);
		is >> s5 >> s6;

		Reader r;
		r.setId(atoi(s5.c_str()));
		r.setPassword(s6);

		readerdatabase->Insert(r);
	}
	while (true)
	{
		cout << "----Welcome to book manager----" << endl;
		int id;
		string password;
		while (true){
			cout << "Please input id: ";
			cin >> id;
			cout << "Please input password: ";
			cin >> password;
			ReaderNode* rn = readerdatabase->getFirst();
			for (int i = 0; i < readerdatabase->getCount(); i++)
			{
				if ((rn->reader.getId() == id) && (strcmp(rn->reader.getPassword().c_str(), password.c_str()) == 0))
				{
					break;
				}
				rn = rn->next;
			}
			if (rn == NULL)
			{
				cout << "wrong input!" << endl;
				continue;
			}
			else{
				cout << "log in successfully!" << endl;
				break;
			}
		}

		Reader* reader = new Reader();
		reader->setId(id);
		reader->setPassword(password);
		while (true)
		{
			cout << "1.borrow book\n2.return book\n3.show books\n4.quit" << endl;
			int choose;
			cin >> choose;
			if (choose == 1)
			{
				cout << "Please input the book's id: ";
				int id;
				cin >> id;
				reader->BorrowBook(id);
				continue;
			}
			if (choose == 2)
			{
				cout << "Please input the book's id: ";
				int id;
				cin >> id;
				reader->ReturnBook(id);
				continue;
			}
			if (choose == 3)
			{
				Node* p = bd->getFirst();
				while (p != NULL)
				{
					if (p->book.getIfBorrowed() == 1)
					{
						cout << p->book.getId() << " " <<
							p->book.getName() << " " << p->book.getWriter() << 
							" " << p->book.getPublishTime() << endl;
					}
					p = p->next;
				}
				continue;
			}
			if (choose == 4)
			{
				break;
			}
			if (choose > 4 || choose < 1)
			{
				cout << "wrong input" << endl;
				continue;
			}
		}
	}
}