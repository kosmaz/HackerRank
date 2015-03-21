#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string lexicograph(string word)
{
	for(int j=word.size()-1; j>0; --j)
	{
		string temp=word;
		char t=temp[j]; temp[j]=temp[j-1]; temp[j-1]=t;
		if(temp.compare(word)>0)
		{
			if(j==word.size()-1)return temp;
			char letter=word[j-1];
			int least=word[j];
			word[j-1]=word[j]; word[j]=letter;
			for(int i=j+1; i<word.size(); ++i)
				if((word[i]>letter)&&(word[i]<least))
				{
					least=word[i]; char t=word[i]; 
					word[i]=word[j-1]; word[j-1]=t;
				}
			sort(word.begin()+j,word.end());
			return word;
		}
	}
	return "no answer";
}

void Run()
{
	//enter the number of testcases t
	unsigned long t;
	cin>>t; 
	string words[t];
	//enter the words for t number of testcases
	for(unsigned long i=0; i<t; ++i)cin>>words[i];
	for(unsigned long j=0; j<t; ++j)cout<<lexicograph(words[j])<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}