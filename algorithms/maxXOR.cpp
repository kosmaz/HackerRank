#include <iostream>
using namespace std;

int maxXOR(int l, int r)
{
	int max=0;
	for(int i=l; i<=r; ++i)
	{
		int a=i;
		for(int j=a; j<=r; ++j)
		{
			int b=j;
			int temp=a^b;
			if(temp>max)max=temp;
		}
	}
	return max;
}

void Run()
{
	//enter value of L
	int L;
	cin>>L;
	//enter value of R
	int R;
	cin>>R;
	cout<<maxXOR(L,R)<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}