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
    srand(time(0));
	//printf("\nEnter available:\t");
	for(i=0;i<n;i++)
	{
		s[i].pid=(rand()%(999-100+1))+100;
	}
	for(i=0;i<m;i++)
	{
		//scanf("%d",&avail[i]);
        avail[i]=rand()%6;
	}
//	printf("\nEnter max matrix:\t");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//	printf("\nEnter max[%d][%d]:\t",i,j);
			//scanf("%d",&s[i].max[j]);
            s[i].max[j]=rand()%6;
		}
	}
	//printf("\nEnter allocation matrix:\t");
    int x;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			//printf("\nEnter allocation[%d][%d]:\t",i,j);
			//scanf("%d",&s[i].alloc[j]);
            x=s[i].max[j];
            if(x==0)
                s[i].alloc[j]=0;
            else
                s[i].alloc[j]=rand()%x;
			s[i].need[j]=s[i].max[j]-s[i].alloc[j];//calculating need
		}
}
void display(struct bank *s,int avail[10])
{
	printf("\nAvailable:");
	for(i=0;i<m;i++)
	{
		printf("%d\t",avail[i]);
	}
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
		work[i]=avail[i];//setting work=available
	for(i=0;i<n;i++)
		finish[i]=0;//setting finish as false
	do{
		bool exist=false;//to see if i exists
		for(i=0;i<n;i++)
		{	
			//("\nFinish[%d]=%d",i,finish[i]);
			if(finish[i]==0)
			{
				for(j=0;j<m;j++)
				{
					//printf("\nNeed[%d]:%d\tWork[%d]:%d",j,s[i].need[j],j,work[j]);
					if(s[i].need[j]>work[j])
						break; 
				}
				if(j==m)
				{
						printf("\nP%d over",s[i].pid);
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
		printf("\ni exists? %d",exist);
		if(exist==false)
			 return false;
	}while(count<n);
	printf("\nSafe sequence:\t");
	for(i=0;i<n;i++)
		printf("P%d\t",safe[i]);
	printf("\n");
	return true;
}
void res_req(struct bank *s, int request[10],int pno,int avail[10])
{
	for(i=0;i<m;i++)
	{
		if(request[i]>s[pno].need[i])
			break;
	}
	if(i!=m)
		printf("\nProcess has exceeded maximum claim!!\nResource cannot be granted\n");
	else
	{
		printf("\nRequest within need");
		for(i=0;i<m;i++)
		{
			if(request[i]>avail[i])
				break;
		}
		if(i!=m)
			printf("\nProcess must wait\nResources not available\n");
		else
		{
			printf("\nYes the request can be granted\nChecking for safe state...");
			for(i=0;i<m;i++)
			{
				avail[i]-=request[i];
				s[pno].alloc[i]+=request[i];
				s[pno].need[i]-=request[i];
			}
			display(s,avail);
			if(safety(s,avail)==false)
				printf("\nUnsafe state if this request is granted!\n");
			else
			{
				printf("\nRequest granted leaves system in safe state\n");
			}
			
		}
		
	}
	

}

void main()
{
	int avail[10];
	//printf("\nEnter number of processes:\t");
    //scanf("%d",&n);
    n=rand()%5+1;
	//printf("\nEnter number of resource types:\t");
	//scanf("%d",&m);
    m=rand()%4+1;
	struct bank *ptr=p;
	input(ptr,avail);
	display(ptr,avail);
	if(safety(ptr,avail)==false)
	{
		printf("\nSystem is not in safe state!!\n");
	}
	else
	{
		int pno,request[m];
		//printf("\nEnter process no that requests:\t");
		//scanf("%d",&pno);
        pno=rand()%n;
		//printf("\nEnter request:\t");
		printf("\nP%d requests :\t",ptr[pno].pid);
        for(i=0;i<m;i++)
		{
				//scanf("%d",&request[i]);
                request[i]=rand()%6;
                printf("%d",request[i]);
		}
		res_req(ptr,request,pno,avail);
	}		
	
	
	
}

