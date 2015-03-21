#include <iostream>
#include <vector>
using namespace std;

int least(int array[], int N)
{
	int least=0;
	for(int j=0; j<N; ++j)if(array[j]>least)least=array[j];
	for(int i=0; i<N; ++i)if(array[i]<least && array[i]!=0)least=array[i];
	return least;
}

void Run()
{
	//enter N number of sticks
	int N;
	cin>>N;
	int sticks[N];
	//enter length of N number of sticks
	for(int i=0; i<N; ++i)cin>>sticks[i];
	vector<int> cuts;
	int length=least(sticks,N);
	while(length!=0)
	{
		int each_cut=0;
		for(int i=0;i<N;++i)
		{
			sticks[i]-=length;
			if(sticks[i]<0)sticks[i]-=sticks[i];
			else ++each_cut;
		}
		cuts.push_back(each_cut);
		length=least(sticks,N);
	}
	for(int j=0;j<cuts.size();++j)cout<<cuts[j]<<endl;
}

int main()
{
	Run();
	return 0;
}