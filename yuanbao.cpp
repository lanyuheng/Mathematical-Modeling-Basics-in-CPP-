#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define l 100
#define t 100
void main()
{
    FILE *fp;
	fp=fopen("tu.txt","w");
	int i,j;
	int a[100]={0};
	srand(time(NULL));
	for(i=0;i<100;i++)
		a[i]=rand()%2;
	int b[100]={0};

	int rule[8]={1,0,1,1,1,0,0,0};
	
	for(i=0;i<l;i++)
	{
		fprintf(fp,"%d\t",a[i]);
	}
	fprintf(fp,"\n");
		for(i=1;i<t;i++)
		{
			for(j=0;j<l;j++)
			{
				b[j]=a[j];
			}
			for(j=0;j<l;j++)
			{
				if( b[((j-1)+l)%l]==0&&b[j]==0&&b[(j+1)%l]==0)
					a[j]=rule[0];
				else if( b[((j-1)+l)%l]==0&&b[j]==0&&b[(j+1)%l]==1)
					a[j]=rule[1];
				else if( b[((j-1)+l)%l]==0&&b[j]==1&&b[(j+1)%l]==0)
					a[j]=rule[2];
				else if (b[((j-1)+l)%l]==0&&b[j]==1&&b[(j+1)%l]==1)
					a[j]=rule[3];
				else if( b[((j-1)+l)%l]==1&&b[j]==0&&b[(j+1)%l]==0)
					a[j]=rule[4];
				else if( b[((j-1)+l)%l]==1&&b[j]==0&&b[(j+1)%l]==1)
					a[j]=rule[5];
				else if (b[((j-1)+l)%l]==1&&b[j]==1&&b[(j+1)%l]==0)
					a[j]=rule[6];
				else
					a[j]=rule[7];
			}
			for(j=0;j<l;j++)
			{
				fprintf(fp,"%d\t",a[j]);
			}
				fprintf(fp,"\n");
			
	}
	fclose(fp);
}

