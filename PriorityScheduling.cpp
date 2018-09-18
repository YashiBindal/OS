#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{   cout<<"\t\t\t SJF for different arrival time"<<endl;
    int n;
    cout<<"Enter no of processes:";
    cout<<endl;
    cin>>n;                 //number of processes in schedular
	int PT[n],BT[n];
	cout<<"PT "<<"BT" <<endl;
    for(int i=0;i<n;i++)    //input priority and BT
    {
      cin>>PT[i];
      cin>>BT[i];
    }
    vector< pair<int,int> > vect;  // linking priority and BT using vector pair
    for (int i=0; i<n; i++)
    vect.push_back( make_pair(PT[i],BT[i]) ); //for sorting as per priority
    sort(vect.begin(), vect.end());  //sort function
    for(int i=0;i<n;i++)
    {
    	cout << vect[i].first << " "
             << vect[i].second << endl;
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
	

