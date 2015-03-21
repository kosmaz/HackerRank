#include <iostream>
#include <vector>
using namespace std;

int bot_energy(vector<int>& data,float average)
{
	int least_energy;
	bool state_1=false;
	bool state_2=false;
	int energy_1=average-1;
	int energy_2=average;
	unsigned count=0;
	for(unsigned i=0; i<data.size(); ++i)
	{
		if(state_1==false)
		{
			if(energy_1>data[i])energy_1+=(energy_1-data[i]);
			else if(energy_1<data[i])energy_1-=(data[i]-energy_1);
			else energy_1+=0;
			if(energy_1<0)state_1=true;
		}
		if(state_2==false)
		{
			if(energy_2>data[i])energy_2+=(energy_2-data[i]);
			else if(energy_2<data[i])energy_2-=(data[i]-energy_2);
			else energy_2+=0;
			if(energy_2<0)state_2=true;
		}
		else break;
		++count;
	}
	if(state_1==false && count==data.size())least_energy=average-1;
	else if(state_2==false)least_energy=average;
	else if(state_2==true)least_energy=average+1;
	return least_energy;
}

void Run()
{
	//enter value of N
	int N;
	cin>>N;
	float total=0;
	vector<int> data;
	for(int i=0; i<N; ++i)
	{
		int temp;
		cin>>temp;
		total+=temp;
		data.push_back(temp);
	}
	cout<<bot_energy(data,total/=N);
	return;	
}

int main()
{
	Run();
	return 0;
}