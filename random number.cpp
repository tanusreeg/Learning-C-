#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	ofstream of("RandomNumber.txt",ios::trunc);
	for(int i=0; i<10000; i++)
	{
		of<<rand()<<endl;
	}
	of.close();
	cout<<"File created"<<endl;
}
