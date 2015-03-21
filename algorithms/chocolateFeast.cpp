#include <iostream>
using namespace std;

int chocolates(int n, int c, int m)
{
	int ate=0;
	int bought=n/c;
	ate+=bought;
	if(bought==m)++ate;
	while(bought>m)
	{
		int remaining=bought%m;
		bought/=m;
		ate+=bought;
		bought+=remaining;
		if(bought==m)++ate;
	}
	return ate;
}

void Run()
{
	//enter value of T for number of test cases
	int T;
	cin>>T;
	struct three{int N,C,M;}data[T];
	//enter N, C, M data
	for(int i=0;i<T;++i) 
		cin>>data[i].N>>data[i].C>>data[i].M;
	for(int j=0;j<T;++j)
	  cout<<chocolates(data[j].N,data[j].C,data[j].M)<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}