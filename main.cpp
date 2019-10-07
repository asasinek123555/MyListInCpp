#include <iostream>
#include <iomanip>

#include "menudepod.h"

//aa bb cc 33 dd 22 qq 11

using namespace std;

int main()
{
	string data;
	getline(cin,data);
	depod test;
	test.input(data);
	while(test.getInt_count())
	{
		cout<<test.nextInt()<<" ";
	}
	cout<<endl;
	while(test.getElse_count())
	{
		cout<<test.nextElse()<<" ";
	}
	cout<<endl;
	return 0;
}
