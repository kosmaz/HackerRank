#include <iostream>
#include <string>
#include <vector>
using namespace std;

string fibonacci(unsigned long long n)
{
	unsigned long long fib_1=0;
	unsigned long long fib_2=1;
	unsigned long long fib=0;
	while(fib<=n)
	{
		fib=fib_1+fib_2;
		if(fib==n)return "IsFibo";
		fib_1=fib_2; fib_2=fib;
	}
	return "IsNotFibo";
}

void Run()
{
	//enter the value of T for number of testcases
	unsigned long T;
	cin>>T;
	vector<unsigned long long> data;
	//enter value of N for T number of testcases
	for(unsigned long i=0; i<T; ++i)
	{
		unsigned long long temp;
		cin>>temp;
		data.push_back(temp);
	}
	for(unsigned long j=0; j<T; ++j)
		cout<<fibonacci(data[j])<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}