#include <iostream>
#include <string>
using namespace std;

string anagram(string& palindrome)
{
	//ascii 97-122
	int odd=0;
	int count[26];
	for(unsigned i=0;i<26;++i)count[i]=0;
	for(unsigned j=0;j<palindrome.size();++j)++count[palindrome[j]-97];
	for(unsigned k=0;k<26;++k)if((count[k]%2)!=0)++odd;
	if(odd>1)return "NO";
	else return "YES";
}

void Run()
{
	//enter string
	string key;
	getline(cin,key);
	cout<<anagram(key)<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}