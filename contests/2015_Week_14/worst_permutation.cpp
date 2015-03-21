#include <iostream>
#include <vector>
#include <map>
using namespace std;

void swap(vector<int>& data,int pos_1,int pos_2)
{
	int temp=data.at(pos_1);
	data.at(pos_1)=data.at(pos_2);
	data.at(pos_2)=temp;
	return;
}

void Run()
{
	int N,K;
	cin>>N>>K;
	vector<int> data;
	map<int,int> ref;
	for(int i=0; i<N; ++i)
	{
		int temp;
		cin>>temp;
		ref.insert(pair<int,int>(temp,i));
		data.push_back(temp);
	}
	
	int level=0;
	int swaps=0;
	for(map<int,int>::reverse_iterator rit=ref.rbegin(); rit!=ref.rend(); ++rit)
	{
		if(swaps==K)break;
		if(level==rit->second)
		{
			++level;
			continue;
		}
		int temp=data.at(level);
		swap(data,level,rit->second);
		ref.at(temp)=rit->second;
		rit->second=level;
		++level;
		++swaps;
	}
	for(int i=0; i<N; ++i)
		cout<<data.at(i)<<" ";
	return;
}

int  main()
{
	Run();
	return 0;
}