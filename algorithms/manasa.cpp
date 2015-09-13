#include <iostream>
using namespace std;

void lastStone(int n, int a, int b)
{
	if(a>b){int temp=b; b=a; a=temp;}
	if(a==b){cout<<a*(n-1); return;}
	for(int i=0,j=n-1; i<n; ++i,--j)cout<<(a*j)+(b*i)<<' ';
	return;
}

void Run()
{
	//enter value of T for number of test cases
	int T;
	cin>>T;
	struct three{int n,a,b;}data[T];
	//enter n, a, b data
	for(int i=0;i<T;++i) 
		cin>>data[i].n>>data[i].a>>data[i].b;
	for(int j=0;j<T;++j)
	{
		lastStone(data[j].n,data[j].a,data[j].b);
	  cout<<endl;
  }
  return;
}

int main()
{
	Run();
	return 0;
}