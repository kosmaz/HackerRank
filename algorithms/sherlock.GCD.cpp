#include <iostream>
#include <string>
using namespace std;

string subset(long array[],int N)
{
	int least=array[0];
	for(int i=0;i<N;++i)
	{
		if(array[i]==1)return "YES";
		if(array[i]<least)least=array[i];
	}
	int count=0;
	for(int j=0;j<N;++j)
		if((array[j]%least)!=0)++count;
	if(count!=0)
	{
		int _2count,_3count,_5count,_7count;
		_2count=_3count=_5count=_7count=0;
		for(int k=0;k<N;++k)
		{
			if((array[k]%2)==0)++_2count; if((array[k]%3)==0)++_3count;
	  	if((array[k]%5)==0)++_5count;	if((array[k]%7)==0)++_7count;
		}
		if((_2count==N) || (_3count==N) || (_5count==N) || (_7count==N))
			return "NO";
		return "YES";
	}
	else return "NO";
}

void Run()
{
	//enter value of T number of testcases
	int T;
	cin>>T;
	string answer[T];
	for(int i=0; i<T; ++i)
	{
		//enter the N length of array
		int N;
		cin>>N;
		long array[N];
		for(int j=0; j<N; ++j)cin>>array[j];
		answer[i]=subset(array,N);
	}
	for(int k=0; k<T; ++k)cout<<answer[k]<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}
