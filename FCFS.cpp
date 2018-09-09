#include<iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{   int n;
    cin>>n;
	int AT[n],BT[n]; 
    for(int i=0;i<n;i++)
    {
            cin>>AT[i];
          	cin>>BT[i];
    }
    vector< pair<int,int> > vect;  // linking AT and BT using vector pair
    for (int i=0; i<n; i++)
    vect.push_back( make_pair(AT[i],BT[i]) );
       
	sort(vect.begin(), vect.end());  //for sorting AT
 
    int CT[n],TAT[n],WT[n];
    CT[0]=BT[0];
    for(int i=0;i<n;i++)
    {   
    	CT[i]=CT[i-1]+BT[i];       //caculating burst time
     }
	
	for(int i=0;i<n;i++)
	{
		TAT[i]=CT[i]-AT[i];  //calculating Turn around time
		WT[i]=TAT[i]-BT[i];  //calculating waiting time
	}
	for(int i=0;i<n;i++)  //To print value of CT,TAT,WT
	{
		cout<<CT[i]<<" "<<TAT[i]<<" "<<WT[i]<<endl;
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
