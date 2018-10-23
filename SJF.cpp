#include<iostream>
#include <bits/stdc++.h>

using namespace std;
bool compare(const pair<int,int>&i, const pair<int,int>&j){
	if(i.first==j.first && i.second<j.second)
	return i.second<j.second;
	else
	return i.first<j.first;
}
int main()
{    cout<<"\t\t\t\t SJF for different arrival time"<<endl;
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
    
    /*for(int i=0;i<n;i++)       printing sorted pair as per SJF
     {
     	cout<<vect[i].first<<"  "<<vect[i].second<<endl;
	 }*/
	
	int CT[n],TAT[n],WT[n];
    for(int i=0;i<n;i++)
    {   
        if(i==0)
        {
        	CT[0]=vect[0].second;
        	TAT[0]=CT[0]-vect[0].first;
        	WT[0]=TAT[0]-vect[0].second;
		}
        else
        {
    	CT[i]=CT[i-1]+vect[i].second;   //calculating completion time
		TAT[i]=CT[i]-vect[i].first;   //calculating Turn around time
		WT[i]=TAT[i]-vect[i].second;  //caculating Wating time
		}
		while(WT[i]<0)      //to check negative wating time(happens when CPU is ideal i.e. no process is available for a arrival time) 
		{
            WT[i]=WT[i]+1;
			CT[i]=CT[i]+1;   
			TAT[i]=TAT[i]+1;
		}
	
     }
     
	cout<<" AT "<<"| BT "<<"| CT "<<"| TAT "<<"| WT"<<endl;
	for(int i=0;i<n;i++)  //To print value of CT,TAT,WT
	{
		cout<<" "<<vect[i].first<<"    "<<vect[i].second<<"    "<<CT[i]<<"    "<<TAT[i]<<"    "<<WT[i]<<endl;
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
