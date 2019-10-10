#include<stdio.h>
#include<string.h>
struct 
{
	char dname[10],files[10][10];
	int fcount;
}dir[10];

int searchfile(char str[10],int k)
{
	int flag=0;
	for(int i=0;i<dir[k].fcount;i++)
		if(strcmp(str,dir[k].files[i])==0)
		{
			flag=1;
			break;
		}
	return flag;
}
int searchdir(char str[10],int count)
{
	printf("\nstr:%s  dcount:%d",str,count);
	for(int i=0;i<count;i++)
		if(strcmp(str,dir[i].dname)==0)
		{
			printf("\ni:%d str:%s dir:%s",i,str,dir[i].dname);
			return i;
		}
	return -1;
}
void main()
{
	int  ch,flag=0,i,dcount=0,k;
	char str[10];
	//dir.fcount=0;
	printf("\n1.Create Directory\t2.Create File\n3.Search File\t4.Delete File\n5.Display all directories\t6.Display all files\n7.Exit\n\nEnter operation to be performed :\t");
	scanf("%d",&ch);
	while(ch!=7)
	{
		switch(ch)
		{
			case 1:	printf("\nEnter name of directory :\t");
				scanf("%s",str);
				if(k=searchdir(str,dcount)==-1)
				{
					dir[dcount].fcount=0;
					strcpy(dir[dcount].dname,str);
					dcount++;
					printf("\nDirectory %s created",str);
				}
				else
					printf("\nDirectory already exists!!!");
				break;
			case 2:	printf("\nEnter name of directory :\t");
				scanf("%s",str);
				k=searchdir(str,dcount);
				printf("\nk:%d",k);
				if(k!=-1)
				{
					printf("\nEnter name of file to be created:\t");
					scanf("%s",str);
					if(searchfile(str,k))
						printf("\nFile %s already exists in the directory %s!!",str,dir[k].dname);
					else
					{				
						strcpy(dir[k].files[dir[k].fcount],str);					
						dir[k].fcount++;
					}		
				}
				else printf("\n\nDirectory not found");		
				break;
			case 3: printf("\nEnter name of directory :\t");
				scanf("%s",str);
				k=searchdir(str,dcount);
				printf("\nk:%d",k);
				if(k!=-1)
				{	
					printf("\nk:%d  dir:%s  str:%s fcount:%d",k,dir[k].dname,str,dir[k].fcount);
					if(dir[k].fcount==0)
						printf("\nEmpty directory!!!");
					else 
					{	printf("\nEnter name of file to be searched:\t");
						scanf("%s",str);
						if(searchfile(str,k))
							printf("\nFile %s found in directory %s!",str,dir[k].dname);
						else 
							printf("\nFile %s not found in directory %s",str,dir[k].dname);
					}
				}
				else printf("\n\nDirectory not found");	
				flag=0;
				break;
			case 4: printf("\nEnter name of directory :\t");
				scanf("%s",str);
				k=searchdir(str,dcount);
				printf("\nk:%d",k);
				if(k!=-1)
				{
					if(dir[k].fcount==0)
						printf("\nEmpty directory!!!");
					else
					{
						printf("\nEnter name of file to be deleted:\t");
						scanf("%s",str);
						for(i=0;i<dir[k].fcount;i++)
						if(strcmp(str,dir[k].files[i])==0)
						{
							strcpy(dir[k].files[i],dir[k].files[dir[k].fcount-1]);
							printf("\n\nFile deleted");
							dir[k].fcount--;
							flag=1;
							break;
						}
						if(flag==0)
							printf("\nFile %s found in directory %s!",str,dir[k].dname);
						else flag=0;
					}
				}
				else printf("\n\nDirectory not found");		
				break;
			case 5:	if(dcount==0)
					printf("\nNo directories exist!!!!");
				else
				{	
					printf("\n\nDirectory list:");
					for(i=0;i<dcount;i++)
						printf("\n%s",dir[i].dname);		
				}		
				break;	
			case 6:	printf("\nEnter name of directory :\t");
				scanf("%s",str);
				k=searchdir(str,dcount);
				printf("\nk:%d",k);
				if(k!=-1)
				{
					if(dir[k].fcount==0)
						printf("\nEmpty directory!!!");
					else
					{
						printf("\n\nContents of %s directory are: ",dir[k].dname);	
						for(i=0;i<dir[k].fcount;i++)
							printf("\n-%s",dir[k].files[i]);
					}
				}
				else printf("\n\nDirectory not found");		
				break;			
			case 7: break;
			default: printf("\nInvalid choice!!!");
		}
		printf("\n\n\n\n\n\n\n\n1.Create Directory\t2.Create File\n3.Search File\t4.Delete File\n5.Display all directories\t6.Display all files\n7.Exit\n\nEnter operation to be performed :\t");
		scanf("%d",&ch);
	}
}

