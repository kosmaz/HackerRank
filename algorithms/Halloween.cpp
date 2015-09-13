#include <iostream>
using namespace std;

long cuts(int k)
{
	long cuts=0;
  long kLimit=10000000;
  long even_odd=k%2;
	if(0==even_odd)
	{
		long operand=k/2;
		if(k==kLimit)
		 cuts=(operand+1)*(operand+1);
		else
		cuts=operand*operand;
	}
	else
	{
		long operand=k/2;
		long difference=k-operand;
		if(k==kLimit-1)
			cuts=operand*(difference+1);
		else
			cuts=operand*difference;
	}
	return cuts;
}

void Run()
{
	//enter number of test cases
	int T;
	cin>>T;
	int array[T];
	//enter the T number of cuts
	for(int i=0; i<T; ++i)cin>>array[i];
	for(int j=0; j<T; ++j)cout<<cuts(array[j])<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}