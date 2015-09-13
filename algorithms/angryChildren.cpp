#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long unfairness(vector<unsigned long long> data,
															 unsigned long k)
{
	unsigned long long unfair=0;
	sort(data.begin(),data.end());
	unfair=data[k-1]-data[0];
	for(unsigned long i=0,j=k-1;j<data.size(); ++i,++j)
	{
		unsigned long long temp=data[j]-data[i];
		if(temp<unfair)unfair=temp;
	}
	return unfair;
}

void Run()
{
	//enter the value of N && K
	unsigned long N,K;
	cin>>N>>K;
	vector<unsigned long long> data;
	//enter the number of candies for N number of packets
	for(unsigned long i=0; i<N; ++i)
	{
		unsigned long long temp;
		cin>>temp;
		data.push_back(temp);
	}
	cout<<unfairness(data,K)<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}