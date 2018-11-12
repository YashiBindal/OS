#include<iostream>
#include<algorithm>
using namespace std;
int chk(int pg[10001],int frame)
{  int f=0;
	for(int i=0;i<frame;i++)
	{
		if(pg[i]==-1)
		 {
		  return i;
		  break;
	     }
		else f=1;
	}
	if(f)return 0;
}
int main()
{  
	int frame;
	cout<<"Page Frames:";
	cin>>frame;
	cout<<"Enter Reference String Size:";
	int s;
	cin>>s;
	int ref[s];
	for(int i=0;i<s;i++)cin>>ref[i];
	int pg[frame],hit=0,miss=0;
	int f=0,c=0,used[frame];
	for(int i=0;i<frame;i++)pg[i]=-1;
	for(int i = 0;i<s;i++)
	{  c++;
	   int flg=0;
	   for(int j=0;i<frame;j++)
		{
		  if(pg[j]==ref[i])
		  {
		     used[j]=c;
		     hit++;
		     flg=1;
			 break;	
		  }	
	    }
	    if(flg==0)
	    { cout<<flg;  
		int index=chk(pg,frame);
		   if(index!=0)
	    	{
	    	   pg[index]=ref[i];
	    	   used[index]=c;
	    	   //cout<<"pg[index]"<<pg[index]<<"used[index]"<<used[index];
			}
			else
			{
				int min=abs(used-std::min_element(used,used+frame));
			    //cout<<"min"<<min;
				pg[min]=ref[i];
			    used[min]=c;
			}
			miss++;
		}
	}
	cout<<"hit:"<<hit<<"\nmiss:"<<miss;
	return 0;
}
