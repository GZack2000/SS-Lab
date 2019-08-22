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
	srand((time(0)));
	int n,i,bt[10],wt[10],tt[10],pr[10],j,p[10],pos,temp;
	float avgwt=0,avgtt=0;
	//printf("\nEnter no. of processes:\n");
	//scanf("%d",&n);
	n=rand()%9+1;
	printf("\nNo. of processes: %d",n);
	//printf("\nEnter the burst times\n");
	for(i=0;i<n;i++)
	{
		//printf("\nEnter burst time and priority of p%d:\t",i);
		//scanf("%d %d",&bt[i],&pr[i]);
		p[i]=i+1;
		pr[i]=rand()%n+1;
		bt[i]=rand()%10+1;
	}
	printf("\nProcess\tBurst time\tPriority\tWaiting Time\tTurnaround Time\n");
	
	
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
				pos=j;	
		}
		swap(pr,i,pos);
		swap(bt,i,pos);
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[j];
		avgwt+=wt[i];
	}
	for(i=0;i<n;i++)
	{
		tt[i]=wt[i]+bt[i];
		avgtt+=tt[i];
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],pr[i],wt[i],tt[i]);	
	}
	avgwt/=n;
	avgtt/=n;
	printf("\nAverage waiting time: %.3f\n",avgwt);
	printf("\nAverage turnaround time: %.3f\n",avgtt);
}
