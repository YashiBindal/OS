#include <bits/stdc++.h>
using namespace std;

int main()
{   
     cout<<"\t\t\t\tFIRST COME FIRST SERVE FOR ZERO ARRIVAL TIME\n";
    int n;
    cout<<"Enter no. of processes:";
    cin>>n;                 //number of processes in schedular
	int BT[n]; 
	cout<<"Enter Burst time:\n";
    for(int i=0;i<n;i++)    //input BT(Arrival time is 0 for all processes)
    {
      cin>>BT[i];
    }
    int CT[n],TAT[n],WT[n];
    
    for(int i=0;i<n;i++)
    {   
        if(i==0)
        {
        	CT[0]=BT[0];
        	TAT[0]=CT[0];
        	WT[0]=TAT[0]-BT[0];
		}
        else
        {
    	CT[i]=CT[i-1]+BT[i];   //calculating completion time
		TAT[i]=CT[i];         //calculating Turn around time
		WT[i]=TAT[i]-BT[i];  //caculating Wating time
		}
     }
	cout<<"CT  TAT  WT"<<endl ;
	for(int i=0;i<n;i++)  //To print value of CT,TAT,WT
	{
		cout<<CT[i]<<"   "<<TAT[i]<<"   "<<WT[i]<<endl;
	}
	float sum1=0,sum2=0;
	for(int i=0;i<n;i++) //To find average of TAT,WT
	{
		sum1=sum1+TAT[i];
		sum2=sum2+WT[i];
	}
	cout<<"Average TAT:"<<sum1/n<<endl;
	cout<<"Average WT:"<<sum2/n;
    return 0;    
}
