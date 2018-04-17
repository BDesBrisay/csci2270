#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


int main()
{
	int_array arraytest;
	init(arraytest);
	if(arraytest.count==0)
	{
		cout<<"Empty array created"<<endl;
	}
	else
	{
		cout<<"Error in array creation"<<endl;
	}
	clear(arraytest);
	if(arraytest.count==0)
	{
		cout<<"Array cleared of data"<<endl;
	}
	else
	{
		cout<<"Error in clear function"<<endl;
	}
	for(unsigned int i=0;i<25;i+=2)
	{
		if(arraytest.count < arraytest.DEFAULT_CAPACITY)
		{
			add(arraytest,i);
			print(arraytest);
		}
		else
		{
			add(arraytest,i);
			print(arraytest);
		}
	}
	for(unsigned int i=1;i<25;i+=2)
	{
		if(arraytest.count < arraytest.DEFAULT_CAPACITY)
		{
			add(arraytest,i);
			print(arraytest);
		}
		else
		{
			add(arraytest,i);
			print(arraytest);
		}
	}
	if(arraytest.capacity == 2*arraytest.DEFAULT_CAPACITY)
	{
		cout<<"Resize function works properly"<<endl;
	}
	else
	{
		cout<<"Resize not working properly"<<endl;
	}
	if(contains(arraytest,6))
	{
		cout<<"Number 6 present in Array"<<endl;
	}
	else
	{
		cout<<"Number 6 not in Array Contains not working properly"<<endl;
	}
	if(contains(arraytest,30))
	{
		cout<<"Number 30 present in Array Contains not working properly"<<endl;
	}
	else
	{
		cout<<"Number 30 not in Array"<<endl;
	}
	if(remove(arraytest,23) && arraytest.count == 24)
	{
		cout<<"Number 23 removed from Array"<<endl;
	}
	else
	{
		cout<<"Number 23 not in Array error in remove"<<endl;
	}
	if(remove(arraytest,24) && arraytest.count == 23)
	{
		cout<<"Number 24 removed from Array"<<endl;
	}
	else
	{
		cout<<"Number 24 not in Array error in remove"<<endl;
	}
	if(remove(arraytest,0) && arraytest.count == 22)
	{
		cout<<"Number 0 removed from Array"<<endl;
	}
	else
	{
		cout<<"Number 0 not in Array error in remove"<<endl;
	}
	if(remove(arraytest,35))
	{
		cout<<"Error in remove function"<<endl;
	}
	else
	{
		cout<<"Number not in Array"<<endl;
	}
	destr(arraytest);
	if(*arraytest.data == 0)
	{
		cout<<"Array destroyed"<<endl;
	}
	else
	{
		cout<<"Error in destroy"<<endl;
	}
	return 0;
}
