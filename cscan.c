#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	srand(time(0));
	int n, tr[20],init,i,j,seek=0,current,next=-1,count,max,r,oneseek;
	char dir;
	double avg;
	//printf("\nEnter l for left r for right:\t");
	//scanf("%c",&dir);
	r=rand()%2;
	oneseek=rand()%3+1;
	if(r==0)
	{
		printf("\nDirection:\tLeft");	
		dir='l';
	}
	else
	{
		printf("\nDirection:\tRight");			
		dir='r';
	}	
	printf("\nSeek time for each track:\t%dms",oneseek);
	//printf("\nEnter number of requests:\t");
	//scanf("%d",&n);
	n=rand()%5+2;
	printf("\nNo. of requests:\t%d",n);
    	//printf("\nEnter range of disk:\t");
    	//scanf("%d",&max);
	max=rand()%(200-100+1)+100;
	printf("\nMaximum range of disk:\t%d",max);	
	//printf("\nEnter initial head postition:\t");
	//scanf("%d",&init);
	init=rand()%(max+1);
	printf("\nInitial head position:\t%d",init);	
	printf("\n\nRequests:\t");
	for(i=0;i<n;i++)
	{	
		//scanf("%d",&tr[i]);
		tr[i]=rand()%max;
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
	printf("\n\nSequence is:\t%d\t",init);
	switch(dir)
	{
		case 'l':	
				for(i=n-1;i>=0;i--)
					if(tr[i]<current)
						{next=i;break;}
				if(next==-1)//case that all requests are >current
				{
					printf("0\t%d\t",max);
					seek+=current;
					next=n-1;
					current=max;
				}
				break;
		case 'r':
				for(i=0;i<n;i++)
					if(tr[i]>current)
						{next=i;break;}
				if(next==-1)//case that all requests are <current
				{
					printf("%d\t0\t",max);
					seek+=abs(current-max);
					current=0;
					next=0;
				}
				break;
	}


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
						break;
                }
                    if(tr[0]!=0 && count!=0)//to avoid printing duplicate
                    {
                        //printf("tr%d",tr[0]);
                        seek+=current;
                        printf("0\t");
                        if(tr[n-1]!=max)
                            printf("%d\t",max);
                        current=max;
                    }
                    next=n-1;
					
				break;
		 case 'r':	//printf("\nGoing right");	
				for(j=next;j<n;j++)
				{
					count--;
					printf("%d\t",tr[j]);
					seek+=abs(tr[j]-current);
					current=tr[j];
					if(count==0)
                        break;
				}
				if(tr[n-1]!=max && count!=0)//to avoid printing duplicate
				{
					seek+=abs(current-max);
					printf("%d\t",max);
                    if(tr[0]!=0)
                        printf("0\t");
                    current=0;
				}
                next=0;

				break;
		default:printf("\nInvalid choice");
		}
	}
	printf("\nTotal head movement:\t%d\n",seek);	
	avg=oneseek*seek/(1.0*n);
	printf("\nAverage seek time:\t%.2f\n",avg);
}

