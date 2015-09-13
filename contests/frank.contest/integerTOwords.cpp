#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

char numbers[]={'1','2','3','4','5','6','7','8','9'};
string words[][2]={"one","","two","twenty","three","thirty","four","forty","five","fifty","six","sixty","seven","seventy","eight","eighty","nine","ninety"};
string level[]={"thousand","million","billion","trillion"};
string tens[]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};

void capslock(string& sentence)
{
	sentence[0]=toupper(sentence[0]);
	for(unsigned i=0; i<sentence.size(); ++i)
	{
		if(sentence[i]==',' && sentence[i+1]==' ')
		{
			sentence[i+2]=toupper(sentence[i+2]);
			continue;
		}
		if(sentence[i]==' ')sentence[i+1]=toupper(sentence[i+1]);
	}
	return;
}

string sub_decoder(string& sub_number)
{
	string sub_word;
	switch(sub_number.size())
	{
		case 1:
		{
			if(sub_number[0]=='0')sub_word="zero";
			else
			for(int i=0; i<9; ++i)
				if(sub_number[0]==numbers[i])sub_word=words[i][0];
		}
		break;
		case 2:
		{
			if(sub_number[0]=='1')
			{
				if(sub_number[1]=='0')sub_word="ten";
				else
				for(int i=0; i<9; ++i)
					if(sub_number[1]==numbers[i])sub_word=tens[i];
			}
			else
			{
				for(int j=0; j<9; ++j)
					if(sub_number[0]==numbers[j])
					{	
						sub_word=words[j][1];
						sub_word+=" ";
					}
				for(int k=0; k<9; ++k)
					if(sub_number[1]==numbers[k])sub_word+=words[k][0];
			}
		}
		break;
		case 3:
		{
			for(int i=0; i<9; ++i)
				if(sub_number[0]==numbers[i])
				{
					sub_word=words[i][0]; sub_word+=" hundred";
				}
			if(sub_number[1]=='1')
			{
				sub_word+=" ";
				if(sub_number[2]=='0')sub_word+="ten";
				else
					for(int l=0; l<9; ++l)
						if(sub_number[2]==numbers[l])sub_word+=tens[l];
			}
			else
			{
				for(int j=0; j<9; ++j)
					if(sub_number[1]==numbers[j])
					{
						if(sub_number[0]!='0')sub_word+=" ";
					   sub_word+=words[j][1];
					}
				for(int k=0; k<9; ++k)
					if(sub_number[2]==numbers[k])
					{
						sub_word+=" "; 
						if(sub_number[1]=='0')sub_word+=" "; 
						sub_word+=words[k][0];
					}
			}
		}	
		break;
	}
	return sub_word;
}

string decode_number_to_words(string number)
{
	string word;
	if(number.size()<=3)word=sub_decoder(number);
	else
	{
		int start=0;
		switch(number.size()/3)
		{
			case 2:start=(number.size()%3==0)? 0:1; break;
			case 3:start=(number.size()%3==0)? 1:2; break;
			case 4:start=(number.size()%3==0)? 2:3; break;
			case 5:start=(number.size()%3==0)? 3:3; break;
		}
		unsigned i=0;
		for(;;)
		{
			string tmp;
			if(i==0 && (number.size()%3!=0))
			{
				string tmp_2(number.begin(),number.begin()+number.size()%3);
				tmp=move(tmp_2);
				i+=number.size()%3;
			}
			else
			{
				for(unsigned j=i; j<i+3; ++j)tmp.push_back(number.at(j));
				i+=3;	
			}
			tmp=sub_decoder(tmp);
			if(tmp.size()==0)
			{
				if(start<0)break;
				--start;
			}
			else
			{
				word+=tmp;
				if(start<0)break;
				word+=" "; word+=level[start]; word+=", ";
				--start;
			}
		}
	}
	if(word.at(word.size()-1)==' ' && word.at(word.size()-2)==',')
	{
		word.pop_back(); word.pop_back();
	}
	capslock(word);
	return word;
}

void Run()
{
	for(;;){
	cout<<"enter number:>";
	cin.clear();
	long long number;
	cin>>number;
	ostringstream tmp;
	tmp<<number;
	cout<<decode_number_to_words(tmp.str())<<endl;}
	return;
}

int main()
{
	Run();
	return 0;
}