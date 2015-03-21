#include <iostream>
#include <vector>
using namespace std;

struct three{unsigned long a,b,k;};

unsigned long long averageOperations(vector<three> data,
																			unsigned long long N,
																				unsigned long long M)
{
	long double average=0;
	for(unsigned long long i=0; i<M; ++i)
	{
		unsigned long diff=data[i].b-data[i].a;
		++diff;
		average+=(long double)(data[i].k*diff);
	}
	return ((unsigned long long)(average/=N));
}

void Run()
{
	//enter values of N && M
	unsigned long long N,M;
	cin>>N>>M;
	//enter value of a,b && k for M operations
	vector<three> data;
	for(unsigned long long i=0; i<M; ++i)
	{
		three temp;
		cin>>temp.a>>temp.b>>temp.k;
		data.push_back(temp);
	}
	cout<<averageOperations(data,N,M)<<endl;
}

int main()
{
	Run();
	return 0;
}