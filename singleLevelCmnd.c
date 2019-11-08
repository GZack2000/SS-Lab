#include<stdio.h>
#include<string.h>
struct 
{
	char dname[10],files[10][10];
	int count;
}dir;

int search(char str[10])
{
	int flag=0;
	for(int i=0;i<dir.count;i++)
		if(strcmp(str,dir.files[i])==0)
		{
			flag=1;
			break;
		}
	return flag;
}
void main()
{
	int  ch,flag=0,i;
	char cmnd[10],fn[10];	
	//dir.count=0;
	printf("\nEnter name of directory :\t");
	scanf("%s",dir.dname);
	//printf("\n1.Create File\n2.Search File\n3.Delete File\n4.Display all files\n5.Exit\n\nEnter operation to be performed :\t");
	//scanf("%d",&ch);
	do
	{
		printf("\n\n\n\nEnter command:\ntouch:\t to create a file\nrm:\tto remove a file\nls: to list all files\nexit:\tto exit\n\n\n$");
		scanf("%s",cmnd);
		 printf("\ncommand entered:\t%s",cmnd);
		if(strcmp(cmnd,"touch")==0)	
			ch=1;
		else if(strcmp(cmnd,"rm")==0)
			ch=3;
		else if(strcmp(cmnd,"ls")==0)
			ch=4;
		else if(strcmp(cmnd,"exit")==0)
			ch=5;	
		else 
		{
			printf("\n\nch:%d\tCommand not recognized!",ch);
			continue;		
		}	
		printf("\nch:%d",ch);				
		switch(ch)
		{
			case 1:	//printf("\nEnter name of file: \t");
				//scanf("%s",str);
				scanf("%s",fn);
				if(search(fn))
					printf("\nFile %s already exists in the directory %s!!",fn,dir.dname);
				else
				{				
					strcpy(dir.files[dir.count],fn);					
					dir.count++;
				}				
				break;
		/*	case 2:	scanf("%s",fn); 
				if(dir.count==0)
				{	printf("\nEmpty directory!!!");			
					break;
				}	
				//printf("\nEnter name of file to be deleted:\t");
				//scanf("%s",str);
				if(search(fn))
					printf("\nFile %s found in directory!",fn);
				else 
					printf("\nFile not found in directory");
				flag=0;
				break;*/
			case 3:	scanf("%s",fn);
				if(dir.count==0)
				{
					printf("\nEmpty directory!!!");
					break;
				}
				//printf("\nEnter name of file to be deleted:\t");
				for(i=0;i<dir.count;i++)
				if(strcmp(fn,dir.files[i])==0)
				{
					strcpy(dir.files[i],dir.files[dir.count-1]);
					printf("\n\nFile deleted");
					dir.count--;
					flag=1;
					break;
				}
				if(flag==0)
					printf("\nFile not found in directory!");
				else flag=0;
				break;
			case 4: if(dir.count==0)
				{
					printf("\nEmpty directory!!!");
					break;
				}
				printf("\n\nContents of %s directory are: ",dir.dname);	
				for(i=0;i<dir.count;i++)
					printf("\n-%s",dir.files[i]);
				break;
			case 5: break;
			default: printf("\nInvalid choice!!!");
		}
	}while(ch!=5);
}

