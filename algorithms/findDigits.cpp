#include <iostream>
using namespace std;

int digits(unsigned long long variable)
{
	int num_digits=0;
	unsigned long long reduce=variable;
	int digit=reduce%10;
	reduce=variable/10;
	while(reduce!=0)
	{
		if(digit==0)goto pt0;
		if(((variable%digit)==0) || digit==1)++num_digits;
		pt0:
		digit=reduce%10;
		reduce=reduce/10;
		if(reduce==0 && (digit==1 || (variable%digit==0)))++num_digits;
	}
	return num_digits;
}

void Run()
{
	//enter the value of T for testcases
	int T;
	cin>>T;
	unsigned long long data[T];
	//enter value of N for T number of testcases
	for(int i=0; i<T; ++i)cin>>data[i];
	for(int j=0; j<T; ++j)cout<<digits(data[j])<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}