#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int operations(vector<int>& _1list, vector<int>& _2list)
{
	int operations=0;
	while(_1list.size()!=0)
	{
		unsigned pos=0;
		for(unsigned i=0; i<_2list.size(); ++i)
		{
			int check=_2list.at(0);
			for(unsigned j=pos; j<_1list.size(); ++j)
			{
				if(check==_1list.at(j))
				{
					_1list.erase(_1list.begin()+j);
					_2list.erase(_2list.begin()+i);
					pos=j;
				}
			}
			if(pos==_1list.size()-1)
			{
				++operations;
				break;
			}
			else ++pos;
		}
	}	
	return operations;
}

void Run()
{
	int N;
	cin>>N;
	
	vector<int> first_list;
	vector<int> second_list;
	
	for(int i=0; i<N; ++i)
	{
		int temp;
		cin>>temp;
		first_list.push_back(temp);
	}
	
	for(int j=0; j<N; ++j)
	{
		int temp;
		cin>>temp;
		second_list.push_back(temp);
	}
	sort(second_list.begin(),second_list.end());
	cout<<operations(first_list,second_list);
	
	return;
}

int main()
{
	Run();
	return 0;
}
