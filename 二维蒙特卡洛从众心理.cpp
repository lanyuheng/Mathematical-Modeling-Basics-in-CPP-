#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

#define l 100
#define t 10000
#define q 0

void main()
{
	FILE *fp;
	fp=fopen("tu.txt","w");
	int i,i1,k,m,n;
	double p=0,n1=0;
	int a[l][l]={0};
	srand(time(NULL));
	for(k=0;k<l;k++)
	{
		for(i=0;i<l;i++)
		{
			double s=(double)rand()/RAND_MAX;
			if(s<=q)
			a[k][i]=1;
		}
	}
	for(i1=0;i1<t;i1++)
	{
		n=rand()%l;
		m=rand()%l;
		for(k=0;k<3;k++)
		{
			for(i=0;i<3;i++)
			{
				if(a[(n+k+l)%l][(m+l+i)%l]==1)
					n1++;
			}
		}
			if(a[(n+1+l)%l][(m+1+l%l)]==1)
					n1--;
				if(n1==4)
				{
							for(i=0;i<3;i++)
					{
						a[(n+i+l)%l][(m-1+l)%l]=(a[(n+i+l)%l][(m-1+l)%l]+1)%2;
						a[(n+i+l)%l][(m+3+l)%l]=(a[(n+i+l)%l][(m+3+l)%l]+1)%2;
					}
					for(k=0;k<3;k++)
					{	
						a[(n-1+l)%l][(m+i+l)%l]=(a[(n-1+l)%l][(m+i+l)%l]+1)%2;
						a[(n+3+l)%l][(m+i+l)%l]=(a[(n+3+l)%l][(m+i+l)%l]+1)%2;
					}
				}
				else
				{
			
						if(n1>4)
					{
						for(i=0;i<3;i++)
					{
						a[(n+i+l)%l][(m-1+l)%l]=1;
						a[(n+i+l)%l][(m+3+l)%l]=1;
					}
					for(k=0;k<3;k++)
					{	
						a[(n-1+l)%l][(m+i+l)%l]=1;
						a[(n+3+l)%l][(m+i+l)%l]=1;
					}
					}
					else
					{
						for(i=0;i<3;i++)
					{
						a[(n+i+l)%l][(m-1+l)%l]=0;
						a[(n+i+l)%l][(m+3+l)%l]=0;
					}
						for(k=0;k<3;k++)
					{	
						a[(n-1+l)%l][(m+i+l)%l]=0;
						a[(n+3+l)%l][(m+i+l)%l]=0;
					}
					}

				}
	}
	for(k=0;k<l;k++)
	{
		for(i=0;i<l;i++)
		{
			fprintf(fp,"%d\t",a[k][i]);
		}
		fprintf(fp,"\n");
	}
		fclose(fp);
}
