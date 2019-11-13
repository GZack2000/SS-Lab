#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
 int number;
 char type;
 char name[20];
 struct node *children[10];
 struct node *parent;
 int childcount;
};
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
void main()
{
	int  chd,flag=0,i,x,j;
	char instrn[30],copy[30],cmnd[10],fn[10];
	struct node *pwd;
 	struct node *root = (struct node *)malloc(sizeof(struct node));
 	root->number=0;
 	root->type='d';
 	strcpy(root->name,"root");
	for (i=0;i<10;i++)
	{
	root->children[i]=NULL;
	}
	root->childcount=0;
	printf("\nPWD:\troot\n");
	pwd=root;

	do
	{
			printf("\n\n$");
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
		else if(strcmp(cmnd,"rm")==0)
			chd=3;
		else if(strcmp(cmnd,"pwd")==0)
			chd=4;	
		else if(strcmp(cmnd,"touch")==0)
			chd=5;
		else if(strcmp(cmnd,"exit")==0)
			chd=6;	
		else if(strcmp(cmnd,"ls")==0)
			chd=7;
		else 
		{
			printf("\n\ncmnd:%s\tCommand not recognized!",cmnd,chd);
			continue;		
		}	
		struct node *dir,*f;
		//printf("\nchd:%d",chd);	
		switch(chd)
		{
			case 1:	/* Creating a new directory */
 					dir=(struct node *)malloc(sizeof(struct node));
					dir->number=(pwd->childcount+1);
					dir->type='d';
					strcpy(dir->name,fn);
					for(i=0;i<10;i++)
						dir->children[i]=NULL;
					dir->parent=pwd;
					dir->childcount=0;
					pwd->children[pwd->childcount]=dir;
					pwd->childcount++;
					break;
			case 2://CHanging directory
					flag=0;
					if(strcmp(fn,"..")==0 && pwd->parent!=NULL)
					{
						pwd=pwd->parent;
						printf("\npwd:\t %s",pwd->name);
					}
					else
					{
						i=0;
						while(pwd->children[i]!=NULL)
						{
							printf("\nfn:%s\tname:%s\ttype:%c",fn,pwd->children[i]->name,pwd->children[i]->type);
							if(strcmp(pwd->children[i]->name,fn)==0 && pwd->children[i]->type=='d')
							{
								pwd=pwd->children[i];
								flag=1;
								printf("\npwd:\t%s",pwd->name);
								break;
							}
							i++;
						}
						if(flag==0)
							printf("\nNo such directory exists!!");
					}
					break;
			case 3://Removing a file/directory
					flag=0;
					if(pwd->childcount==0)
						printf("\nEmpty directory!!");
					else
					{
						i=0;
						while(pwd->children[i]!=NULL)
						{
							printf("\nfn:%s\tname:%s\ttype:%c",fn,pwd->children[i]->name,pwd->children[i]->type);
							if(strcmp(pwd->children[i]->name,fn)==0)
							{
								for(j=i;j<9;j++)
									pwd->children[j]=pwd->children[j+1];
								flag=1;
								pwd->childcount--;
								break;
							}
							i++;
							if(flag==0)
								printf("\nNo such file or directory!!");
						}
					}
					break;
			case 4://print pwd
					printf("\npwd:\t%s",pwd->name);
					break;
			case 5://touch
					 f = (struct node *)malloc(sizeof(struct node));
					f->number=pwd->childcount+1;
					f->type='f';
					strcpy(f->name,fn);
					for(i=0;i<10;i++)
						f->children[i]=NULL;
					f->parent=pwd;
					f->childcount=0;
					pwd->children[pwd->childcount]=f;
					pwd->childcount++;
					break;
			case 6:	break;
			case 7://ls
					i=0;
					while(pwd->children[i]!=NULL)
					{
						printf("%s\t",pwd->children[i]->name);
						i++;
					}
					break;
		}
	} while (chd!=6);
	
	

}