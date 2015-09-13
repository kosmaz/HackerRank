#include <iostream>
using namespace std;

void Run()
{
	//enter value of N && M
	int N,M;
	cin>>N>>M;
  long A[N]; int B[M]; int C[M];
	//enter elements of array A, B && C
	for(auto& i:A)cin>>i;
	for(auto& j:B)cin>>j;
	for(auto& k:C)cin>>k;
	int l=1; int times=0;
		for(int m=0; m<N; ++m)
			if(((m+1)%B[l])==0)
			{
				A[m]*=C[l];	A[m]%1000000007; ++l;
			 if(l==M){l=1; ++times;}
			}
	for(auto& o:A){for(int p=0;p<times;++p)o*=C[p]; o%1000000007;}
	for(auto n:A)cout<<n<<' ';cout<<endl;
	return;
}

int main()
{
	Run();
	return 0;
}