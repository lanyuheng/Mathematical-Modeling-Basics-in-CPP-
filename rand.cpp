#include<iostream>
#include "graph.cpp"

using namespace std;
static void rande(graph &g,int e)
{
	for(int i=0;i<e;i++)
	{
		int v=int(g.v()*rand()/(1+RAND_MAX));
		int w=int(g.v()*rand()/(1+RAND_MAX));
		g.insert(edge(v,w));
	}
}
static void randg(graph &g,double e)
{
	double p=2*e/(g.v()*(g.v()-1));
	for( int i=0;i<g.v();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(rand()<p*RAND_MAX)
			g.insert(edge(i,j));
		}
	}
}