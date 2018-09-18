#include<iostream>
#include <bits/stdc++.h>

using namespace std;
bool compare(const pair<int,int>&i, const pair<int,int>&j){
	if(i.first==j.first && i.second>j.second)
	return j.first<i.first;
	else
	return i.first<j.first;
}
int main()
{    cout<<"\t\t\t\t FCFS for different arrival time"<<endl;
    int n;
    cout<<"Enter number of processes:"<<endl;
    cin>>n;                 //number of processes in schedular
	int AT[n],BT[n]; 
	cout<<"Enter arrival time and burst time"<<endl;
    for(int i=0;i<n;i++)    //input AT and BT
    {
      cin>>AT[i];
      cin>>BT[i];
    }
    vector< pair<int,int> > vect;  // linking AT and BT using vector pair
    for (int i=0; i<n; i++)
    vect.push_back( make_pair(AT[i],BT[i]) );
    sort(vect.begin(), vect.end(),compare);  //for sorting AT
	int CT[n],TAT[n],WT[n];
    for(int i=0;i<n;i++)
    {   
        if(i==0)
        {
        	CT[0]=BT[0];
        	TAT[0]=CT[0]-AT[0];
        	WT[0]=TAT[0]-BT[0];
		}
        else
        {
    	CT[i]=CT[i-1]+BT[i];   //calculating completion time
		TAT[i]=CT[i]-AT[i];   //calculating Turn around time
		WT[i]=TAT[i]-BT[i];  //caculating Wating time
		}
		while(WT[i]<0)      //to check negative wating time(happens when CPU is ideal i.e. no process is available for a arrival time) 
		{
            WT[i]=WT[i]+1;
			CT[i]=CT[i]+1;   
			TAT[i]=TAT[i]+1;
		}
	
     }
	 cout<<" CT "<<"| TAT "<<"| WT"<<endl;
	for(int i=0;i<n;i++)  //To print value of CT,TAT,WT
	{
		cout<<" "<<CT[i]<<"     "<<TAT[i]<<"     "<<WT[i]<<endl;
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
