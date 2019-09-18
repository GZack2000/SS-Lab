#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	srand(time(0));
	int n,max,tr[20],init,i,j,seek=0,current,next=-1,count,flag=0;
	int r,oneseek;
	double avg;
	char dir;
	oneseek=rand()%3+1;
	r=rand()%2;
	printf("\nInitial Direction:\t");
	if(r==0)
	{
		printf("Left");	
		dir='l';
	}
	else
	{
		printf("Right");			
		dir='r';
	}		
	printf("\nSeek time for each track:\t%dms",oneseek);
	//printf("\nEnter l for left r for right:\t");
	//scanf("%c",&dir);
	//printf("\nEnter number of requests:\t");
	//scanf("%d",&n);
	n=rand()%5+2;
	printf("\nNo. of requests:\t%d",n);
	max=rand()%(200-100+1)+100;
	printf("\nMaximum range of disk:\t%d",max);	
	//printf("\nEnter initial head position:\t");
	//scanf("%d",&init);
	init=rand()%(max+1);
	printf("\nInitial head position:\t%d",init);	
	printf("\n\nRequests:\t");
	for(i=0;i<n;i++)
	{	
		//scanf("%d",&tr[i]);
		tr[i]=rand()%max+1;
		printf("%d\t",tr[i]);
		
	}	
	for(i=0;i<n;i++)
	{
		current=i;
		for(j=i+1;j<n;j++)
		{
			if(tr[j]<tr[current])
				current=j;	
		}
		int temp=tr[current];
		tr[current]=tr[i];
		tr[i]=temp;
	}
	current=init;
	printf("\n\nSequence is:\t%d\t",current);
	do{

		switch(dir)
		{
			case 'l':	
					for(i=n-1;i>=0;i--)
						if(tr[i]<current)
							{next=i;break;}
					if(next==-1)
					{
						printf("0\t");
						seek+=current;
						current=0;
						dir='r';
					}	
					break;
			case 'r':	
					for(i=0;i<n;i++)
						if(tr[i]>current)
							{next=i;break;}
					if(next==-1)
					{
						printf("%d\t",max);
						seek+=abs(current-max);
						current=max;
						dir='l';
					}
					break;
		}
	}while(next==-1);
	count=n;
	//printf("\ncount:%d",count);
	while(count>0)
	{
		//printf("\ncount:%d",count);
		switch(dir)
		{
		 case 'l':	//printf("\nGoing left");
				for(j=next;j>=0;j--)
				{
					count--;
					printf("%d\t",tr[j]);
					seek+=abs(tr[j]-current);
					current=tr[j];
					if(count==0)
					{
						flag=1;break;
					}
				}
				if(flag==0)
				{
					seek+=current;
					current=0;
					printf("%d\t",current);
					dir='r';
					next++;	
				}			
				break;
		 case 'r':	//printf("\nGoing right");	
				for(j=next;j<n;j++)
				{
					count--;
					printf("%d\t",tr[j]);
					seek+=abs(tr[j]-current);
					current=tr[j];
					if(count==0)
					{
						flag=1;break;
					}
				}
				if(flag==0)
				{
					seek+=abs(current-max);
					current=max;
					printf("%d\t",current);
					dir='l';
					next--;
				}
				break;
		default:printf("\nInvalid choice");
		}
	}
	printf("\nTotal head movement:\t%d\n",seek);	
	avg=oneseek*seek/(1.0*n);
	printf("\nAverage seek time:\t%.2f\n",avg);
}
