#include<iostream>
#include<vector>
using namespace std;

template <class graph> 
class Degree
{
	public:
		static int print(const graph &g);
};
template <class graph>
int Degree<graph>::print(const graph &g)
{
	for(int v=0;v<g.v();v++)
	{
		int degree=0;
		typename graph::adjiterator a(g,v);
		for(int w=a.beg();!a.end();w=a.nxt())
			degree ++;
		cout<<degree<<" ";
	}
	return 1;
}
