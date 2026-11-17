#include<stdio.h>
#include<string.h>
#include "macro.h"

void macro_subs(char *p)
{
    char ch[100];
    char sub[100];
    char *s,*q,*start;
    int i,l1,l2;

    while(*p!='\0')
    {
        if(*p=='#')
        {
	    start=p;
            p++;

            if(strncmp(p,"define",6)==0)
            {
                p=p+6;

                while(*p==' ' || *p=='\t')
                {
                    p++;
                }
                i=0;
                while(*p!=' ' && *p!='\t' && *p!='\n' && *p!='\0')
                {
                    ch[i]=*p;
                    p++;
                    i++;
                }
                ch[i]='\0';
                while(*p==' ' || *p=='\t')
                {
                    p++;
                }
                i=0;
                while(*p!='\n' && *p!='\0')
                {
                    sub[i]=*p;
                    p++;
                    i++;
                }
                sub[i]='\0';
                if(*p=='\n')
                    p++;
		memmove(start,p,strlen(p)+1);
		p=start;
                l1=strlen(ch);
                l2=strlen(sub);
                s=p;
                while((q=strstr(s,ch))!=NULL)
                {
                    if((q==p || !((q[-1]>='A' && q[-1]<='Z') ||
                                  (q[-1]>='a' && q[-1]<='z') ||
                                  (q[-1]>='0' && q[-1]<='9') ||
                                  q[-1]=='_')) &&
                       !((q[l1]>='A' && q[l1]<='Z') ||
                         (q[l1]>='a' && q[l1]<='z') ||
                         (q[l1]>='0' && q[l1]<='9') ||
                         q[l1]=='_'))
                    {
                        if(l2>l1)
                        {
                            memmove(q+l2,
                                    q+l1,
                                    strlen(q+l1)+1);
                        }
                        else if(l2<l1)
                        {
                            memmove(q+l2,
                                    q+l1,
                                    strlen(q+l1)+1);
                        }

                        strncpy(q,sub,l2);
                        s=q+l2;
                    }
                    else
                    {
                        s=q+l1;
                    }
                }

                continue;
            }
        }

        p++;
    }
}

