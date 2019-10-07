#ifndef menudepod_h
#define menudepod_h

#include <math.h>

#include "list.h"

using namespace std;

class depod{
	private:
		lista<int> *listOfInt;
		lista<string> *listOfString;
		lista<string> *listOfTemp;
	public:
		int getInt_count()
		{
			return listOfInt->get_count();
		}
		int getElse_count()
		{
			return listOfString->get_count();
		}
		int getTemp_count()
		{
			return listOfTemp->get_count();
		}
		depod()
		{
			listOfInt = new lista<int>();
			listOfString = new lista<string>();
			listOfTemp = new lista<string>();
		}
		~depod()
		{
			delete listOfInt;
			delete listOfString;
			delete listOfTemp;
			
		}
		bool isInt(string x)
		{
			for(int i=0;i<x.length();i++)
			{
				char test=x[i];
				if(!((int)test-48<10)) return 0;
			}
			return 1;
		}
		int stringToInt(string *x)
		{
			int sum=0;
			for(int i=0;i<x->length();i++)
			{
				char stringPiece=x->c_str()[i];
				int pieceint=stringPiece-48;
				sum+=pieceint*pow(10,i);
			}
			return sum;
		}
		int nextInt()
		{
			int *temp=listOfInt->popFront();
			int temp2=*temp;
			delete temp;
			return temp2;
		}
		string nextElse()
		{
			string *temp=listOfString->popFront();
			string temp2=*temp;
			delete temp;
			return temp2;
		}
		string* nextTemp()
		{
			return listOfTemp->popFront();
		}
		void explode (string in, char wall=' ')
		{
			string x;
			istringstream inputStream(in);
			while(getline(inputStream, x,wall))
			{
				if(x!=""&&x!=" ")
				{
					listOfTemp->addFront(new string(x));
				}
			}
		}
		void input(string in)
		{
			this->explode(in);
			while(listOfTemp->get_count()>0)
			{
				if(isInt(*listOfTemp->getFront()))
				{
					listOfInt->addFront(new int(stringToInt(listOfTemp->popFront())));
				}
				else
				{
					listOfString->addFront(listOfTemp->popFront());
				}
			}
		}
};

#endif
