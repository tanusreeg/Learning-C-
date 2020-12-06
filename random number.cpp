#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	srand(time(0)); // to make numbers truely random
	ofstream of("RandomNumber.txt",ios::trunc); //ofstream is a class.. where of is an object of that class
	for(int i=0; i<10000; i++)
	{
		of<<rand()<<endl;
	}
	of.close();
	cout<<"File created"<<endl;
}
