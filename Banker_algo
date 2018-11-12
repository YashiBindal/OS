#include<iostream>
using namespace std;
int main()
{
	int nop;
	cin>>nop;
	int nor;
	cin>>nor;
	int allocation[nop][nor];
	int max[nop][nor];
	int need[nop][nor];
	int available[nor];
	char finish[nop];
	int deadlock=0;
	for(int i=0;i<nop;i++)
	{
		for(int j=0;j<nor;j++)
		{
			cin>>allocation[i][j];		
		}
	}
	for(int i=0;i<nop;i++)
	{
		for(int j=0;j<nor;j++)
		{
			cin>>max[i][j];		
			need[i][j] = max[i][j]- allocation[i][j];
		}
	}
	for(int j=0;j<nor;j++)
	cin>>available[j];
	for(int j=0;j<nop;j++)
	finish[j]='F';
	int t=0;
	int checker=0;
	while(t<nop)
	{
		for(int i=0;i<nop;i++)
		{
			for(int j=0;j<nor;j++)
			{
				if(available[j]>=need[i][j] && finish[i]=='F')
				checker=1;
				else
				checker=0;
			}
			if(checker==1)
			{
				finish[i] = 'T';
				for(int k=0;k<nor;k++)
				available[k] = available[k] + allocation[i][k];
			}
		}
		t++;
	}
	int i=0;
	for(i=0;i<nop;i++)
	{
		if(finish[i]=='F')deadlock=1;
	}
	if(deadlock==1)
	{
		cout<<"Not deadlock free. Unsafe state!";
	}
	else
	{
		cout<<"Deadlock free. Safe state!";
	}
	return 0;
}
