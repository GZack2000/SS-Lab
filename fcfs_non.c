#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int a[],int x, int y)
{
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}
void main()
{
	srand(time(0));
	int n,i,bt[10],wt[10],tt[10],at[10],p[10],pos,j,t=0;
	float avgwt=0,avgtt=0;
	//printf("\nEnter no. of processes:\n");
	//scanf("%d",&n);
	n=rand()%10+1;
	printf("\nNo. of processes: %d",n);
	//printf("\nEnter the burst times and arrival times:\n");
	for(i=0;i<n;i++)
	{
		//printf("\nEnter burst time of p%d:\t",i);
		//scanf("%d",&bt[i]);
		//printf("\nEnter arrival time of p%d:\t",i);
		//scanf("%d",&at[i]);
		p[i]=i+1;
		bt[i]=rand()%10+1;
		at[i]=rand()%10;
	}
	printf("\nProcess\tBurst time\tArrival Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(at[j]<at[pos])
				pos=j;	
		}
		swap(at,i,pos);
		swap(bt,i,pos);
		swap(p,i,pos);
	}
	wt[0]=0;
	t=bt[0]+at[0];
	tt[0]=bt[0];
	avgtt+=tt[0];
	for(i=1;i<n;i++)
	{		
		wt[i]=t-at[i];
		if(wt[i]<0)
		{
			t-=wt[i];
			wt[i]=0;
		}
		t+=bt[i];
		tt[i]=wt[i]+bt[i];
		avgwt+=wt[i];
		avgtt+=tt[i];
	}
	for(i=0;i<n;i++)
	{
		//tt[i]=wt[i]+bt[i];
		//avgtt+=tt[i];
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],wt[i],tt[i]);	
	}
	avgwt/=n;
	avgtt/=n;
	printf("\nAverage waiting time: %.3f\n",avgwt);
	printf("\nAverage turnaround time: %.3f\n",avgtt);
}
