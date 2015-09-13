#include <iostream>
#include <math.h>
using namespace std;

long squares(unsigned long long a, unsigned long long b)
{
	long square_count=0;
	if(a==1)
		square_count=sqrt(b);
	else
	{
		long root_a=sqrt(a);
		square_count=((long)sqrt(b))-((long)sqrt(a));
		if((root_a*root_a)==a)++square_count;
	}
	return square_count;
}

void Run()
{
	//enter value of T for testcase
	int T;
	cin>>T;
	unsigned long long array[T][2];
	//enter value of a && b for T number of testcases
	for(int i=0; i<T; ++i)
		cin>>array[i][0]>>array[i][1];
	for(int j=0; j<T; ++j)
		cout<<squares(array[j][0],array[j][1])<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}