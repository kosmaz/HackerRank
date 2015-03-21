import java.util.*;

public final class Main
{
	public static void main(String args[])
	{
		NumberList list=new NumberList();
		list.Run();
		return;
	}
}

final class NumberList 
{
	
	public void Run()
	{
		int T;
		Scanner in=new Scanner(System.in);
		T=in.nextInt();
		int answer[]=new int[T];
		
		for(int i=0; i<T; ++i)
		{
			int N,K,max=0,maxx=0;
			N=in.nextInt();
			K=in.nextInt();
			Vector<Integer> v=new Vector<Integer>();
			for(int j=0; j<N; ++j)
			{
				int temp;
				temp=in.nextInt();
				if(temp>K)++maxx;
				if(max<temp)max=temp;
				v.add(new Integer(temp));
			}
			if(max>K)++maxx;
			answer[i]=maxx+shashank(v,K);
		}
		for(int k=0; k<T; ++k)
			System.out.println(answer[k]);
	}
	
	private int shashank(Vector<Integer> v, int K)
	{
		int maxx=0;
		for(int sub_size=v.size()-2; sub_size>=1; --sub_size)
		{
			for(int j=0; (j+sub_size)<v.size(); ++j)
			{
				List<Integer> list=v.subList(j,j+sub_size+1);
				int temp=list.get(list.size()-1).intValue();
				if(K<temp)++maxx;
			}
		}
		return maxx;
	}
}
