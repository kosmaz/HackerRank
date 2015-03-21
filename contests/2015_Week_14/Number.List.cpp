#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int shashank(vector<int>& data,int K)
{
	int maxx=0;
	for(int sub_size=(int)data.size()-2; sub_size>=3; --sub_size)
	{
		for(int j=0; (j+sub_size)<(int)data.size(); ++j)
			if(K<*max_element(data.begin()+j,data.begin()+j+sub_size+1))
				++maxx;
	}
	return maxx;
}

void Run()
{
	int T;
	cin>>T;
	int answer[T];
	for(int i=0; i<T; ++i)
	{
		int N,k,max=0,maxx=0;
		cin>>N>>k;
		vector<int> data;
		for(int j=0; j<N; ++j)
		{
			int temp;
			cin>>temp;
			if(temp>k)++maxx;
			if(max<temp)max=temp;
			data.push_back(temp);
		}
		if(max>k)++maxx;
		answer[i]=maxx+shashank(data,k);
	}
	for(int k=0; k<T; ++k)
		cout<<answer[k]<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}
