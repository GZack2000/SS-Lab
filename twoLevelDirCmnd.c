#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct 
{
	char dname[10],files[10][10];
	int fcount;
}dir[10];
int searchfile(char fn[10],int k)
{
	int flag=0;
	for(int i=0;i<dir[k].fcount;i++)
		if(strcmp(fn,dir[k].files[i])==0)
		{
			flag=1;
			break;
		}
	return flag;
}
int searchdir(char fn[10],int count)
{
	//printf("\nfn:%s  dcount:%d",fn,count);
	for(int i=0;i<count;i++)
		if(strcmp(fn,dir[i].dname)==0)
		{
			//printf("\ni:%d fn:%s dir:%s",i,fn,dir[i].dname);
			return i;
		}
	return -1;
}
int token_count(char x[100])
{
	int c=0;
	char* token=strtok(x," ");
	//printf("\nc:%dtoken:%s\n",c,token);
	while (token != NULL) 
	{   
		//printf("\nc:%dtoken:%s\n",c,token);		
		c++;
	      token = strtok(NULL, " "); 	
	} 
  
    return c; 
}
void filefn(int k)
{
	int  ch,flag=0,i,x,j;
	char instrn[30],copy[30],cmnd[10],fn[10];
	do
	{
		printf("\n\n\n\nEnter command:\ntouch:\t to create a file\nrm:\tto remove a file\ncd:\tto change directory\npwd:\tto show current directory\nls: to list all files\nexit:\tto exit\n\n\n$");
		gets(instrn);
		//printf("\n%s",instrn);
		strcpy(copy,instrn);
		x=token_count(instrn);
		//printf("\nNO. of tokens: %d",x);
		char *p;
		p=strtok(copy," \t");
		strcpy(cmnd,p);
		if(x>1)
		{
			p=strtok(NULL," ");
			//printf("\nNExt token:%s",p);
			strcpy(fn,p);
		}
		else
		{
			strcpy(fn,"");
		}
						//printf("\ncommand entered:%s operand:%s",cmnd,fn);
		if(strcmp(cmnd,"touch")==0)	
			ch=1;
		else if(strcmp(cmnd,"rm")==0)
			ch=2;
		else if(strcmp(cmnd,"cd")==0)
			ch=5;
		else if(strcmp(cmnd,"pwd")==0)
			ch=6;
		else if(strcmp(cmnd,"ls")==0)
			ch=3;
		else if(strcmp(cmnd,"exit")==0)
			ch=4;	
		else 
		{
			printf("\n\n\tCommand not recognized!",ch);
			continue;		
		}	
		//printf("\nch:%d",ch);				
		switch(ch)
		{
			case 1:	//printf("\nEnter name of file: \t");
				//scanf("%s",fn);
				//printf("\nEnter name of file to be created:\t");
				//scanf("%s",fn);
					if(searchfile(fn,k))
						printf("\nFile %s already exists in the directory %s!!",fn,dir[k].dname);
					else
					{				
						strcpy(dir[k].files[dir[k].fcount],fn);					
						dir[k].fcount++;
					}		
				break;

			case 2:	//printf("\nEnter name of directory :\t");
				//scanf("%s",fn);
				//k=searchdir(fn,dcount);
				//printf("\nj:%d",j);
					if(dir[k].fcount==0)
						printf("\nEmpty directory!!!");
					else
					{
						//printf("\nEnter name of file to be deleted:\t");
						//scanf("%s",fn);
						for(i=0;i<dir[k].fcount;i++)
							if(strcmp(fn,dir[k].files[i])==0)
							{
								strcpy(dir[k].files[i],dir[k].files[dir[k].fcount-1]);
								printf("\n\nFile deleted");
								dir[k].fcount--;
								flag=1;
								break;
							}
						
						if(flag==0)
							printf("\nFile %s not found in directory %s!",fn,dir[k].dname);
						else 
							flag=0;
					}
					break;
			case 3: //printf("\nEnter name of directory :\t");
				//scanf("%s",fn);
				//k=searchdir(fn,dcount);
				//printf("\nk:%d",k);
					if(dir[k].fcount==0)
						printf("\nEmpty directory!!!");
					else
					{
						printf("\n\nContents of %s directory are: ",dir[k].dname);	
						for(i=0;i<dir[k].fcount;i++)
							printf("\n-%s",dir[k].files[i]);
					}
				break;		
			case 4: exit(0);
			case 5:	//printf("\nChanging directory");
					if(strcmp(fn,"..")==0)
					{
						printf("\n\nReturning to upper level");
							return;
					}
					break;
			case 6: printf("\nCurrent directory: %s",dir[k].dname);
					break;
			default: printf("\nInvalid choice!!!");
		}
	}while(ch!=4);
}
void main()
{
	int  chd,ch,flag=0,i,x,dcount=0,k,cd=0;
	char instrn[30],copy[30],cmnd[10],fn[10];
	//dir.fcount=0;
	//printf("\n1.Create Directory\t2.Create File\n3.Search File\t4.Delete File\n5.Display all directories\t6.Display all files\n7.Exit\n\nEnter operation to be performed :\t");
	//scanf("%d",&ch);
	do
	{
		printf("\n\n\n\nEnter command:\nmkdir <name>:\t to create a directory\ncd <name/..>:\tto change directory\nls: to list all directories\nexit:\tto exit\n\n\n$");
		gets(instrn);
		//printf("\n%s",instrn);
		strcpy(copy,instrn);
		x=token_count(instrn);
		//printf("\nNO. of tokens: %d",x);
		char *p;
		p=strtok(copy," \t");
		strcpy(cmnd,p);
		if(x>1)
		{
			p=strtok(NULL," ");
			//printf("\nNExt token:%s",p);
			strcpy(fn,p);
		}
		else
		{
			strcpy(fn,"");
		}
						//printf("\ncommand entered:\t%s operand:%s",cmnd,fn);

		if(strcmp(cmnd,"mkdir")==0)	
			chd=1;
		else if(strcmp(cmnd,"cd")==0)
			chd=2;
		else if(strcmp(cmnd,"exit")==0)
			chd=4;	
		else if(strcmp(cmnd,"ls")==0)
			chd=3;
		else 
		{
			printf("\n\ncmnd:%s\tCommand not recognized!",cmnd,chd);
			continue;		
		}	
		//printf("\nchd:%d",chd);	
		switch(chd)
		{
			case 1:	//printf("\nEnter name of directory :\t");
				//scanf("%s",fn);
				//scanf("%s",fn);
				//printf("\nfn:%s",fn);
				if(k=searchdir(fn,dcount)==-1)
				{
					dir[dcount].fcount=0;
					strcpy(dir[dcount].dname,fn);
					dcount++;
					printf("\nDirectory %s created\ndir count: %d",fn,dcount);
				}
				else
					printf("\nDirectory already exists!!!");
				break; 
			case 2:	//printf("\nEnter name of directory :\t");
				//scanf("%s",fn);
				if(dcount==0)
					printf("\nNo directories exist!!!!");
				else
				{
					//printf("\nChanging directory");
						k=searchdir(fn,dcount);
						//printf("\nk:%d",k);
						if(k!=-1)
							filefn(k);	
						else printf("\n\nDirectory not found");		
				}
				break;
			/*case 3: printf("\nEnter name of directory :\t");
				scanf("%s",fn);
				k=searchdir(fn,dcount);
				printf("\nk:%d",k);
				if(k!=-1)
				{	
					printf("\nk:%d  dir:%s  fn:%s fcount:%d",k,dir[k].dname,fn,dir[k].fcount);
					if(dir[k].fcount==0)
						printf("\nEmpty directory!!!");
					else 
					{	printf("\nEnter name of file to be searched:\t");
						scanf("%s",fn);
						if(searchfile(fn,k))
							printf("\nFile %s found in directory %s!",fn,dir[k].dname);
						else 
							printf("\nFile %s not found in directory %s",fn,dir[k].dname);
					}
				}
				else printf("\n\nDirectory not found");	
				flag=0;
				break;*/
			case 3:// printf("\nls entered");
					if(dcount==0)
					printf("\nNo directories exist!!!!");
					else
					{	
						printf("\n\nDirectory list:");
						for(i=0;i<dcount;i++)
							printf("\n%s",dir[i].dname);		
					}		
					break;		
			case 4: break;exit(0);
			default: printf("\nInvalid choice!!!");
		}
	}while(chd!=4);
}

