#include <iostream>
#include <string>
using namespace std;

int gemStones(int N, string array[])
{
	//ascii 97-122
	int count[26];
	int sub_count[26];
	for(int m=0; m<26;++m)count[m]=sub_count[m]=0;
	int gemstones=0;	
	for(int i=0; i<N; ++i)
	{
		for(int j=0;j<array[i].size();++j)++sub_count[array[i].at(j)-97];
		for(int l=0;l<26;++l)if(sub_count[l]!=0)++count[l];
		for(int n=0;n<26;++n)sub_count[n]=0;
	}
	for(int k=0;k<26;++k)if(count[k]==N)++gemstones;
	return gemstones;
}

void Run()
{
	//enter N number of rocks
	int N;
	cin>>N;
	string array[N];
	cin.ignore();
	for(int i=0; i<N; ++i)getline(cin,array[i]);
	cout<<gemStones(N,array);
	return;
}

int main()
{
	Run();
	return 0;
}