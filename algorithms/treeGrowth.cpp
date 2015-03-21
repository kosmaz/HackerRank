#include <iostream>
using namespace std;

int height(int cycle)
{
 if(cycle==0)return 1;
 		int cycle_count=1;
    int growth=1;
   while(cycle_count<=cycle)
   {
        int even_odd=cycle_count%2;
        if(even_odd==0)growth+=1;
        else growth*=2;
        ++cycle_count;
    }
    return growth;
}

void Run()
{
		//enter number of test cases
    int T;
    cin>>T;
    int array[T];
    //enter T number of K cycles
    for(int i=0; i<T; ++i)cin>>array[i];
  	for(int j=0; j<T; ++j)cout<<height(array[j])<<endl;
    return;
}

int main()
{
   Run();
   return 0;
}