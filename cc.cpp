#include<iostream>
#include<vector>
using namespace std;

template <class graph>
class cc
{
	private:
		const graph &g;
		int ccnt;
		vector <int> id;
		void ccr(int w)
		{
			id[w]=ccnt;
			typename graph::adjiterator a(g,w);
			for (int v=a.beg();!a.end();v=a.nxt())
				if(id[v]==-1)
					ccr(v);
		}
	public:
		cc(const graph &g):g(g),ccnt(0),id(g.v(),-1)
		{
			for(int v=0;v<g.v();v++)
				if(id[v]==-1)
				{ccr(v);ccnt++;}
		}
		int count() const {return ccnt;}
		void connect(int s, int t)
		{
			if(id[s]==id[t])
			cout<<"ÊÇ";
			else cout<<"·ñ";
		}
};