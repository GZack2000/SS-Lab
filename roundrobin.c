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
	int n,i,bt[10],wt[10],tt[10],at[10],rem[10],p[10],j,tslice,time,count,pos;
	float avgwt=0,avgtt=0;
	//printf("\nEnter no. of processes:\n");
	//scanf("%d",&n);
	n=rand()%5+1;
	printf("\nNo. of processes: %d",n);
	//printf("\nEnter the burst times and arrival times:\n");
	for(i=0;i<n;i++)
	{
		//printf("\nEnter burst time and arrival of p%d:\t",i+1);
		//scanf("%d%d",&bt[i],&at[i]);
		bt[i]=rand()%9+1;
		at[i]=rand()%10;
		rem[i]=bt[i];
	}
	//printf("\nEnter time quantum:\t");
	//scanf("%d",&tslice);
	tslice=rand()%5+2;	
	printf("\nTime quantum:%d",tslice);
	//printing randomly generated inputs
	printf("\nProcess\tBurst time\tArrival Time");	
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t\t%d\t\t%d",i+1,bt[i],at[i]);
	}
	count=n;
	//sorting according to arrival time
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(at[j]<at[pos])
				pos=j;	
		}
		swap(bt,i,pos);
		swap(at,i,pos);
		swap(rem,i,pos);
		swap(p,i,pos);
	}
	//printf("\ncount:%d",count);
	
	printf("\nProcess\tBurst time\tArrival Time\tCompletion time\tWaiting Time\tTurnaround Time\n");
	for(i=0,time=at[0];count>0;)
	{
		//printf("\ncount in loop:%d",count);
		//printf("\nTime:%d\trem[%d]:%d  at[%d]\tcount:%d",time,i,rem[i],at[i],count);
		if(at[i]<=time) //if this process has arrived
		{
			//Last iteration of this process
			if(rem[i]<=tslice && rem[i]>0)
			{
				//printf("\nlast iter");
				time+=rem[i];
				rem[i]=0;
				count--;
				//printf("\nP%d over",i);
				//printf("\nCompletion Time of P%d:%d",i+1,time);
				tt[i]=time-at[i];
				avgtt+=tt[i];
				wt[i]=tt[i]-bt[i];
				avgwt+=wt[i];
				printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],at[i],time,wt[i],tt[i]);
			}
			else if(rem[i]>0)
			{
				//NOT last iteration
				rem[i]-=tslice;
				time+=tslice;
			}
		}
		else //if not arrived increment time
			time++;
		if(i==n-1)
			i=0;//for circular traversal
		else
			i++;
	}
	avgwt/=n;
	avgtt/=n;
	printf("\nAverage waiting time: %.3f\n",avgwt);
	printf("\nAverage turnaround time: %.3f\n",avgtt);
}
