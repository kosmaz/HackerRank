#include <iostream>
using namespace std;

int Largest_Vehicle(int i,int j,int N[])
{
	int vehicle=3;
	for(int k=i;k<=j;++k)
	{
		if(N[k]<vehicle)vehicle=N[k];
	}
	return vehicle;
}

void Run()
{
	//enter the length of the freeway and number of testcases
	int N,T;
	cin>>N>>T;
	int nLength[N];
	//enter the segment widths
	for(int i=0; i<N; ++i)cin>>nLength[i];
	int index[T][2];
	for(int k=0;k<T;++k)
	//enter the entrance and exit index
	cin>>index[k][0]>>index[k][1];
	
	for(int l=0;l<T;++l)
		cout<<Largest_Vehicle(index[l][0],index[l][1],nLength)<<endl;
		return;
}

int main()
{
	Run();
	return 0;
}