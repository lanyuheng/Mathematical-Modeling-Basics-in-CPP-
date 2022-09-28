#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

#define l 1000
#define t 1000
#define vmax 100
#define p 80

struct car
	{
		int v;
		int a;//&a=exist
	};

void main()
{
	int i,j;
	FILE *fp;
	fp=fopen("tu.txt","w");
	car road1[l]={0,0};
	srand(time(NULL));
	for(i=0;i<l;i++)
	{
		road1[i].v=rand()%(vmax+1);
	double m=(double)rand()/RAND_MAX;
		if(m<=0.7)
		road1[i].a=1;
	}
	car road2[l]={0,0};
	for(i=0;i<l;i++)
	{
		fprintf(fp,"%d\t",road1[i].a);
	}
	fprintf(fp,"\n");
	srand(time(NULL));
	for(i=1;i<t;i++)
	{
		for(j=0;j<l;j++)
		{
			road2[j]=road1[j];
		}
		for(j=0;j<l;j++)
		{
			if(road2[j].a==1)
			{
				if(road2[j].v<vmax)
			road2[j].v=road2[j].v+1;
			int d,x1,x2,k;
			x1=j;
			x2=((j+1)+l)%l;
			while(road2[x2].a==0)
			{x2=(x2+1+l)%l;
			}
			if(x2-x1>0)
			d=x2-x1-1;
			else
				d=x2+l-x1-1;
			if(road2[j].v>d)
				road2[j].v=d;
			k=rand()%100;
			if(k>=p&&(!(road2[j].v))==0)
				road2[j].v=road2[j].v-1;
			k=(j+road2[j].v)%l;
			road1[j].a=0;
			road1[k].a=1;
			road1[k].v=road2[j].v;
			}
		}
		for(j=0;j<l;j++)
		{
			fprintf(fp,"%d\t",road1[j].a);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

			








				






	

