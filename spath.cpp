#include<iostream>
#include<vector>
using namespace std;

template <class graph>
class spath
{
	const graph &g;
	vector <bool> visited;
	bool found;
	bool searchr(int v,int w,int d)
	{
		if(v==w)
			return (d==0);
		visited[v]=true;
		typename graph::adjiterator a(g,v);
		for(int t=a.beg();!a.end();t=a.nxt())
			if(!visited[t])
				if(searchr(t,w,d-1)) 
				{
					cout<<t<<"-";
					return true;
				}
				visited[v]=false;
				return false;
	}
	public:
		spath(const graph &g,int v,int w):
		  g(g),visited(g.v(),false)
		  {
			  found=searchr(v,w,g.v()-1);
		  }
		  bool exists() const
		  {
			  return found;
		  }
};