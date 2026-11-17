#include<stdio.h>
#include<stdlib.h>
#include "comment.h"
#include "include.h"
#include "macro.h"

int main(int argc,char *argv[])
{
	FILE *fp,*out;
	char *p;
	char *dest;
	char outfile[1000];
	int i=0;
	long long int size;
	if(argc!=2)
	{
		printf("invalid number of arguments");
		exit(0);
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("%s is not found ",argv[1]);
		exit(0);
	}
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	rewind(fp);
	p=malloc(size+1);
	if(p==NULL)
	{
		printf("failed memory allocation");
		fclose(fp);
		exit(0);
	}
	fclose(fp);
	dest=malloc(100000);
	if(dest==NULL)
	{
		printf("failed memory allocation");
		free(p);
		exit(0);
	}
	remove_cmds(p);
	header_inclusion(p,dest);
	macro_subs(dest);
	while(argv[1][i]!='\0' && argv[1][i]!='.')
	{
	        outfile[i]=argv[1][i];
	        i++;
	}
	outfile[i]='.';
	outfile[i+1]='i';
	outfile[i+2]='\0';
	out=fopen(outfile,"w");

	if(out==NULL)
	{
        printf("failed to create output file");
        free(dest);
        exit(0);
	}

	fputs(dest,out);
	fclose(out);

	printf("%s",dest);

	free(p);
	free(dest);
}

