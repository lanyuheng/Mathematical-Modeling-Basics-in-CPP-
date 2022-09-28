#include <iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define GeneSize 32
#define Nmax 10000
#define N0 1000
#define RepreductionAge 6
#define MutationNum 2
#define tmax 1000

typedef struct _Agent{
	bool Gene[GeneSize];
	int Age;
	int BadGeneNum;
	bool LiveOrDie;
	int type;
}Agent;
Agent Agents[Nmax];
double MutationRate=(double)MutationNum/GeneSize;
int Nt=N0;
int Pointer=0;
void Initialize()
{
	for (int i=0;i<Nmax;i++)
	{
		Agents[i].Age=0;
		Agents[i].BadGeneNum=0;
		for (int j=0;j<GeneSize;j++)
		{
			Agents[i].Gene[j]=(rand()%2==0?0:1);
		}
		Agents[i].LiveOrDie=(i<N0?0:1);
	}
}
void Age(int agent)
{
	if (Agents[agent].Gene[Agents[agent].Age]==1)
		Agents[agent].BadGeneNum++;
	Agents[agent].Age++;
}
void Die(int agent,int T)
{
	double RandNum=(double)rand()/(double)RAND_MAX;
	if (Agents[agent].BadGeneNum>=T||Agents[agent].Age>=GeneSize||RandNum<=(double)Nt/Nmax)
	{
		Agents[agent].LiveOrDie=1;
		Nt-=1;
	}
}
void Repreduction(int agent)
{
	int NewPoint;
	for (int i=Pointer;;i=(i+1)%Nmax)
	{
		if (Agents[i].LiveOrDie==1)
		{
			NewPoint=i;
			Pointer=(i+1)%Nmax;
			break;
		}
	}
	Agents[NewPoint].Age=0;
	Agents[NewPoint].BadGeneNum=0;
	for (int j=0;j<GeneSize;j++)
	{
		double RandNum=(double)rand()/(double)RAND_MAX;
		if (RandNum<MutationRate)
		{
			Agents[NewPoint].Gene[j]=!Agents[agent].Gene[j];
		}
		else
		{
			Agents[NewPoint].Gene[j]=Agents[agent].Gene[j];
		}
	}
	Agents[NewPoint].LiveOrDie=0;
	Nt+=1;
}
int Gdis(Agent a,Agent b)
{
	int i,ans = 0;
	for(i = 0;i < GeneSize;i++)
		if(a.Gene[i] != b.Gene[i])
			ans++;
	return ans;
}
void ChangeType(int gdis)
{
	int choose[Nmax]={0};
	int typeNow = 1,k,i,m,p,q;
	int group[Nmax];
	for(i = 0;i < Nmax;i++)
	{
		if(Agents[i].type && !choose[i] && !Agents[i].LiveOrDie)
		{
			for(p = 0;p < Nmax;p++)
				group[p]=-1;
			p = 0;
			Agents[i].type = typeNow;
			group[p] = i;
			choose[i] = 1;
			for(m = 0;m < Nmax;m++)
			{
				if(Agents[m].type && !choose[m] && !Agents[i].LiveOrDie)
				{
					for(k = 0;k < Nmax;k++)
					{
						if(Agents[k].type && !choose[k] && !Agents[i].LiveOrDie)
						{
							for(q = 0;q <= p;q++)
							{
								if(Gdis(Agents[k],Agents[group[q]]) < gdis)
								{
									group[++p] = k;
									Agents[k].type = typeNow;
									choose[k] = 1;
									break;
								}
							}
						}
					}
				}
			}
			typeNow++;
		}
	}
}
void main()
{

	FILE* fp;
	fp=fopen("./result2.txt","w");
	for(int m=0;m<=GeneSize;m++)
	{
	srand(time(0));
	Initialize();
	int i;
	for (int t=0;t<tmax;t++)
	{
		for (i=0;i<Nmax;i++)
		{
			if (Agents[i].LiveOrDie==0)
			{
				Age(i);
				Die(i,m);
			}
		}
		for (i=0;i<Nmax;i++)
		{
			if (Agents[i].LiveOrDie==0&&Agents[i].Age>=RepreductionAge)
			{
				Repreduction(i);
			}
		}
		cout<<"t="<<t<<",Nt="<<Nt<<endl;
	}
	fprintf(fp,"%d\n",Nt);
	}
	ChangeType(5);			
	fclose(fp);
}