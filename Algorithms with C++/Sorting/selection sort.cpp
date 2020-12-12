#include <fstream>
#include <stdlib.h>
#include <iostream>
#define MAX 10000
using namespace std;
// selection sort : finds minimum value from remaining array.. then replaces it with index element..
// array = 5 4 3 2 1 || At 1st loop it will pick minimum value 1.. and swap with index 0.. || 1 4 3 2 5..
// in 2nd loop search for minimum will begin from index 1..At 2nd loop it will pick minimum value from remaining :2.. 
//and swap with index 1.. ||1 2 3 4 5

void swap(int*a, int*b) // simple swap function: takes two pointer as argument
{
	int tm;				
	tm=*a; *a=*b; *b=tm;
}
int * find_min(int*arr,int s) // returns pointer to minimum element
{
	int min = arr[0];
	int *min_index_p;
	for(int i = 1; i<s; i++)
	{
		if(arr[i]<min)
		{
		min = arr[i];
		min_index_p=&arr[i];
		}
	}
	return min_index_p;
}
void selection_sort(int * array,int s)
{
	int * k;
	for(int i =0; i<s-1; i++)
	{
		k = find_min((array+i),s-i);  //k contains pointer to minimum element
		swap (k,array+i);
	}
	
}
//driver 
int main()
{
	int *arr= new int[MAX];
	ifstream ifs("RandomNumber_10000.txt");    // reads numbers from this text file
	for(int i = 0; i<MAX; i++)
	{
		ifs>>arr[i];
	}
	ifs.close();
	selection_sort(arr,MAX);
	ofstream ofs("Sorted by selection sort.txt", ios::trunc);    // writes sorted list to this text file
	for(int i = 0; i<MAX; i++)
	{
		ofs<<arr[i];
		ofs<<endl;
	}
	cout<<"File created"<<endl;
}
