#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int m,n,i,j;
struct bank
{
	int max[10];
	int pid;
	int alloc[10];
	int need[10];
} p[10];
void input(struct bank *s, int avail[10])
{
	printf("\nEnter available:\t");
	for(i=0;i<n;i++)
	{
		s[i].pid=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("\nEnter max matrix:\t");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
				printf("\nEnter max[%d][%d]:\t",i,j);
			scanf("%d",&s[i].max[j]);
		}
	}
	printf("\nEnter allocation matrix:\t");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			printf("\nEnter allocation[%d][%d]:\t",i,j);
			scanf("%d",&s[i].alloc[j]);
			s[i].need[j]=s[i].max[j]-s[i].alloc[j];
		}
	printf("\nAvailable:");
	for(i=0;i<m;i++)
	{
		printf("%d\t",avail[i]);
	}
}
void display(struct bank *s)
{
	printf("\n\n\nMax:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",s[i].pid);
		for(j=0;j<m;j++)
			printf("%d\t",s[i].max[j]);
	}
	printf("\n\n\nAllocation:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",s[i].pid);
		for(j=0;j<m;j++)
			printf("%d\t",s[i].alloc[j]);
	}
	printf("\n\n\nNeed:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",s[i].pid);
		for(j=0;j<m;j++)
			printf("%d\t",s[i].need[j]);
	}
}

bool safety(struct bank *s, int avail[10])
{
	int work[m],finish[n],count=0,safe[n];
	for(i=0;i<m;i++)
		work[i]=avail[i];
	for(i=0;i<n;i++)
		finish[i]=0;
	do{
		bool exist=false;
		for(i=0;i<n;i++)
		{	
			printf("\nFinish[%d]=%d",i,finish[i]);
			if(finish[i]==0)
			{
				for(j=0;j<m;j++)
				{
					printf("\nNeed[%d]:%d\tWork[%d]:%d",j,s[i].need[j],j,work[j]);
					if(s[i].need[j]>work[j])
						break; 
				}
				if(j==m)
				{
						printf("\nP%d over",i);
					for(j=0;j<m;j++)
					{
							work[j]+=s[i].alloc[j];
					}
					finish[i]=1;
					safe[count]=s[i].pid;
					exist=true;
					count++;
					printf("\n%d processes over",count);
				}
			}
		}
		if(exist=false)
			 return false;
	}while(count<n);
	printf("\nSafe sequence:\t");
	for(i=0;i<n;i++)
		printf("P%d\t",safe[i]);
	return true;
}

void main()
{
	int avail[10];
	printf("\nEnter number of processes:\t");
	scanf("%d",&n);
	printf("\nEnter number of resource types:\t");
	scanf("%d",&m);
	struct bank *ptr=p;
	input(ptr,avail);
	display(ptr);
	if(safety(ptr,avail)==false)
	{
		printf("\nSystem is not in safe state!!\n");
	}
		//request[i]<=need[i] else error
	//request[i]<=available else wait
	//available=available-request
	//resource request alg
//	for(i=0;i<m;i++)
	{
		
	}
//	printf("\nEnter request:\t");
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",&request[i]);
//	}
}

