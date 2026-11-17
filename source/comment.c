#include<stdio.h>
#include<string.h>
#include "comment.h"

char *remove_cmds(char *p)
{
	char *q;
	char *start=p;
	while(*p!='\0')
	{
		if((*p=='/')&&(*(p+1)=='/'))
		{
			q=strchr(p,'\n');
			if(q!=NULL)
			{
				memmove(p,q,strlen(q)+1);
			}
			else
			{
		 		*p='\0';
			}
		}
		else if(((*p)=='/')&&(*(p+1)=='*'))
		{
			q=strstr(p+2,"*/");
			if(q!=NULL)
			{
				q=q+2;
				memmove(p,q,strlen(q)+1);
			}
			else
			{
				*p='\0';
			}
		}
		p++;
		}
	return start;
}

