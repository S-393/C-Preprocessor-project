#include<stdio.h>
#include<string.h>
#include "include.h"
void header_inclusion(char *scr,char *dest)
{
        char *p,*q;
        char fname[1000];
        FILE *fp;
        int i;
        char ch;

        p=scr;
        dest[0]='\0';

        while(*p!='\0')
        {
                if(strncmp(p,"#include",8)==0)
                {
                        p=p+8;

                        while(*p==' ' || *p=='\t')
                                p++;

                        if((*p=='"') || (*p=='<'))
                        {
                                if(*p=='<')
                                        ch='>';
                                else
                                        ch='"';

                                p++;
                                q=p;

                                while(*q!=ch && *q!='\0')
                                        q++;

                                i=0;

                                while(p<q)
                                {
                                        fname[i]=*p;
                                        i++;
                                        p++;
                                }

                                fname[i]='\0';

                                fp=fopen(fname,"r");

                                if(fp==NULL)
                                {
                                        printf("file not found %s\n",fname);
                                        return;
                                }

                                while(fgets(dest+strlen(dest),1000,fp)!=NULL);

                                fclose(fp);

                                while(*p!='\n' && *p!='\0')
                                        p++;

                                if(*p=='\n')
                                        p++;

                                continue;
                        }
                }

                i=strlen(dest);
                dest[i]=*p;
                dest[i+1]='\0';

                p++;
        }
}
