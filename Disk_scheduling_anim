#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

int main()
{
    // load graphic mode and drive
    int gd=DETECT,gm=0;
    initgraph(&gd,&gm," ");
    int n,v=0;
    cout<<"Queue Size=";
    cin>>n;
    cout<<"Head Postion=";
    cin>>v;
    int a[10001];
    cout<<"Pages="<<endl;
    for(int j=0;j<n;j++)
    {
	cin>>a[j];
	a[j]=a[j]+100;
    }
    int xmax=getmaxx();
    line(50,100,xmax-50,100);
    line(v+100,100,a[0],150);
    outtextxy(a[0],150,"Changing..");
    int k=150;
    sleep(2);
    for(int i=0;i<n-1;i++)
    {
	line(a[i],k,a[i+1],k+50);
	outtextxy(a[i+1],k+50,"Changing..");
	k+=50;
	sleep(2);
    }
    getch();
}
