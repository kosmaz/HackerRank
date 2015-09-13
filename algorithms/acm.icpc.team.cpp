#include <iostream>
using namespace std;

int max(bool array[],int m)
{
	int count=0;
	for(int i=0; i<m; ++i)if(array[i]==true)++count;
	return count;
}

void Run()
{
	//enter the value of N and M
	int N,M;
	cin>>N>>M;
	bool data[N][M];
	//enter topics studied for N number of persons
	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<M; ++j)
		{
			char ch;
			cin>>ch;
			if(ch=='0')data[i][j]=false;
			else data[i][j]=true;
		}
	}
	int max_topic=0;
	int team=0;
	for(int i=0; i<N; ++i)
	{
		for(int j=i+1; j<N; ++j)
		{
			bool temp[M];
			for(int k=0; k<M; ++k)
				temp[k]=data[i][k]|data[j][k];
			int int_temp=max(temp,M);
			if(int_temp>max_topic)
			{
				max_topic=int_temp;
				team=1;
			}
			else if(int_temp==max_topic)++team;
			else continue;
		}
	}
	cout<<max_topic<<endl;
	cout<<team<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}