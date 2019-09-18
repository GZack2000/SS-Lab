
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	srand(time(0));
	int n, tr[20],i,seek=0,current,oneseek;
	double avg=0;
	oneseek=rand()%3+1;
    //printf("\nEnter number of requests:\t");
   // scanf("%d",&n);
	n=rand()%8+2;
	printf("\nNo. of requests:\t%d",n);
	printf("\nSeek time for each track:\t%dms",oneseek);
   // printf("\nEnter initial head postition:\t");
    //scanf("%d",&current);
	current=rand()%200;
	printf("\nInitial head position:\t%d",current);
    	printf("\n\nRequests:\t");
    	for(i=0;i<n;i++)
    	{	
  	//scanf("%d",&tr[i]);
		tr[i]=rand()%200;
		printf("%d\t",tr[i]);
 	   }      	
    	printf("\n\nSequence:\t%d\t",current);
    	for(i=0;i<n;i++)
   	{
      		printf("%d\t",tr[i]);
      		seek+=abs(tr[i]-current);
       		current=tr[i];
    	}
    	printf("\nTotal head movement:\t%d",seek);
	avg=oneseek*seek/(1.0*n);
	printf("\nAverage seek time:\t%.2f\n",avg);
}
