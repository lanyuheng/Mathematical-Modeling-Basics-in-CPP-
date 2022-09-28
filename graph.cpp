#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

struct edge
{
	int v,w;
	edge(int v=-1,int w=-1):v(v),w(w) {}
};
class graph
{
	int vn,en;
	bool digraph;
	vector<vector<bool> > adj;
public:
	graph(int v,bool digraph=false):
	  adj(v),vn(v),en(0),digraph(digraph)
	  {
		  for(int i=0;i<v;i++)
			  adj[i].assign(v,false);
	  }
	  int v() const{return vn;}
	  int e() const{return en;}
	  bool directed() const{return digraph;}
	  void insert(edge e)
	  {
		  int v=e.v,w=e.w;
		  if(adj[v][w]==false)
			  en++;
		  adj[v][w]=true;
		  if(!digraph)
			  adj[w][v]=true;
	  }
	  void removw(edge e)
	  {
		  int v=e.v,w=e.w;
		  if(adj[v][w]==true)
			  en--;
		  adj[v][w]=false;
		  if(!digraph)
			  adj[w][v]=false;
	  }
	  bool edge(int v,int w) const
	  {
		  return adj[v][w];
	  }
	  class adjiterator;
	  friend class adjiterator;
};
class graph::adjiterator
{
	const graph &g;
	int i,v;
public:
	adjiterator(const graph &g,int v):
	  g(g),v(v),i(-1) {}
	  int beg()
	  {
		  i=-1;return nxt();}
	  int beg2()
	  {
		  i=-1;return nxt2();}
	  int nxt()
	  {
		  for (i++;i<g.v();i++)
			  if(g.adj[v][i]==true)
				  return i;
			  return -1;
	  }
	  int nxt2()
	  {
		  for (i++;i<g.v();i++)
		  {
			  if(g.adj[v][i]==true)
				  return 1;
			  else
				  return 0;
		  }
	  }
	  bool end()
	  {
		  return i>=g.v();
	  }
};
