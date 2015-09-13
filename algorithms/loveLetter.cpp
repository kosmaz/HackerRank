#include <string>
#include <iostream>
using namespace std;

string reverse_string(const string& word)
{
	string reversed;
	for(int i=word.size()-1,j=0; i>=0; --i,++j)
		reversed.insert(j,1,word[i]);
	return reversed;
}

string split_string(string& word)
{
	string second_half;
	int even_odd=word.size()%2;
	if(even_odd==0)
	{
		for(int i=word.size()-1,j=0; i>=(word.size()/2);--i,++j)
			second_half.insert(j,1,word[i]);
		word.erase((word.size()/2));
	}
	else
	{
		for(int i=word.size()-1,j=0; i>=(word.size()/2)+1;--i,++j)
			second_half.insert(j,1,word[i]);
		word.erase((word.size()/2)+1);
	}
	return second_half;
}

int palindrome(string word)
{
	int operations=0;
	if(0==word.compare(reverse_string(word)))return operations;
	string side_2=split_string(word);
	for(int i=0; i<side_2.size(); ++i)
	{
		int difference=side_2[i]-word[i];
		if(0>difference)
		{
			difference=word[i]-side_2[i];
			operations+=difference;
		}
		else operations+=difference;
	}
	return operations;
}

void Run()
{
	//enter the number of test
	int T;
	cin>>T;
	string words[T];
	//enter strings to be changed to palindromes
	cin.ignore();
	for(int i=0; i<T; ++i)getline(cin,words[i]);
	
	for(int j=0; j<T; ++j)
		cout<<palindrome(words[j])<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}