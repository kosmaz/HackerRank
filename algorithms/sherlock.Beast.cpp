#include <iostream>
using namespace std;

void maxDigit(long n)
{
	int key[n];
	for(long u=0;u<n;++u)key[u]=0;
	long _3=n/5;
	long _3remains=n%5;
	long _5=n/3;
	long _5remains=n%3;
	switch(_5remains)
	{
		case 0:
		for(long i=0;i<n;++i)key[i]=5;
		break;
		case 1:
		{
			if(_3remains==0 && _3==2)for(long m=0;m<n;++m)key[m]=3;
			else if(_5>=1 && _3>=1 && n!=7)
			{
				long _5limit=n-10;
				for(long o=0;o<_5limit;++o)key[o]=5;
				for(long p=_5limit;p<n;++p)key[p]=3;
			}
			else{cout<<-1<<endl; return;}
		}
		break;
		case 2:
		{
			if(_5>0)
			{
				long _5limit=n-5;
				if(_5limit==0)
					for(long j=0;j<n;++j)key[j]=3;
				else if((_5limit%3)==0)
				{
					for(long k=0;k<_5limit;++k)key[k]=5;
					for(long l=_5limit;l<n;++l)key[l]=3;
				}
				else{cout<<-1<<endl; return;}
			}
			else{cout<<-1<<endl; return;}
		}
		break;
	}
	for(long q=0;q<n;++q)cout<<key[q];
	cout<<endl;
	return;
}

void Run()
{
	//enter number of test cases
  int T;
  cin>>T;
  long array[T];
  //enter T number of N digits
  for(int i=0; i<T; ++i)cin>>array[i];
  for(int j=0; j<T; ++j)maxDigit(array[j]);
  return;
}

int main()
{
	Run();
	return 0;
}