#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

#define n 100
#define t 10000

void main()
{
	FILE *fp;
	fp=fopen("tu.txt","w");
	int i,i1,j,k;
	double p=0,n1=0;
	int a[n]={0};
	srand(time(NULL));
	for(k=0;k<n;k++)
	{
		double m=(double)rand()/RAND_MAX;
		if(m<=0.5)
			a[k]=1;
	}
	for(i=0;i<t;i++)
	{
		for(i1=0;i1<n;i1++)
			{
				if(a[i1]==1)
					n1++;
			}
			p=n1/n;
			n1=0;
			j=rand()%n;
			if(a[j]==a[((j+1)+n)%n])
			{
				a[((j-1)+n)%n]=a[j];
				a[(j+2)%n]=a[j];
			}
			else
			{
				a[((j-1)+n)%n]=a[((j+1)+n)%n];
				a[((j+2)+n)%n]=a[j];
			}
			fprintf(fp,"%f\t",p);
	}			
				fclose(fp);
}







	
		


