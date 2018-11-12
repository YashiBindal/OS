#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"no of pages: ";
	int n,fault=0,flg,x,idx=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int pf;
	cin>>pf;
	int pagef[pf];
	for(int i=0;i<pf;i++) pagef[i]=-1;
	for(int k=0;k<pf;k++) cout<<pagef[k]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++){
		if(idx>pf-1) idx=0;
		x=arr[i];
		flg=0;
		cout<<x<<endl;
		for(int l=0;l<pf;l++){
			if(pagef[l]==x){
				flg=1;
				break;
			}
			else continue;
		}
		if(flg==1){
			cout<<"HIT"<<endl;
			for(int k=0;k<pf;k++) cout<<pagef[k]<<" ";
			cout<<endl;
			continue;
		}
		else{
			pagef[idx]=x;
			cout<<"FAULT"<<endl;
			for(int k=0;k<pf;k++) cout<<pagef[k]<<" ";
			cout<<endl;
			idx++;
			fault++;
		}
	}
	
}
