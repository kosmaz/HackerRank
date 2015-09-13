#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Run()
{
	int N;
	cin>>N;
	vector<int> data;
	for(int i=0; i<N; ++i)
	{
		int temp;
		cin>>temp;
		data.push_back(temp);
	}
	sort(data.begin(),data.end());
	int lonely=0;
	for(int i=0; i<N; ++i)
	{
		if(data[i]==data[i+1])
		{
			++i;
			continue;
		}
		else lonely=data[i];
	}
	cout<<lonely<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}