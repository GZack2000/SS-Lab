#include<stdio.h>

void display( int m,int n,int a[m][n])
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
void main()
{
	int i,j,available[10],max[10][10],alloc[10][10],need[10][10],n,m;
	printf("\nEnter number of processes:\t");
	scanf("%d",&n);
	printf("\nEnter number of resource types:\t");
	scanf("%d",&m);
	int work[m],finish[n],request[m];
	//request[i]<=need[i] else error
	//request[i]<=available else wait
	//available=available-request
	//
	printf("\nEnter available:\t");
	for(i=0;i<m;i++)
	{
		scanf("%d",&available[i]);
	}
	printf("\nEnter max matrix:\t");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	printf("\nEnter allocation matrix:\t");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	printf("\nEnter request:\t");
	for(i=0;i<n;i++)
	{
		scanf("%d",&request[i]);
	}
	printf("\nAvailable:\n");
	
	for(i=0;i<m;i++)
	{
		request
	}
}

