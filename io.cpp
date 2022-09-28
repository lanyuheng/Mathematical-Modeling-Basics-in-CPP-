#include<iostream>
using namespace std;

template <class graph>
class io
{
	public:
		static void show(const graph &);
		//static void scanez(graph &);
		//static void scan(graph &);
};
template <class graph>
void io<graph>::show(const graph &g)
{
	cout<<"对应边相连为:"<<endl;
	for(int s=0;s<g.v();s++)
	{
		cout.width(2);
		cout<<s<<":";
		typename graph::adjiterator a(g,s);
		for (int t=a.beg();!a.end();t=a.nxt())
		{
			cout.width(2);
			cout<<t<<" ";
		}
		cout<<endl;
	}
	cout<<"邻接矩阵为:"<<endl;
	for(int s2=0;s2<g.v();s2++)
	{
		typename graph::adjiterator a2(g,s2);
		for (int k=a2.beg2();!a2.end();k=a2.nxt2())
		{
			cout.width(2);
			cout<<k<<" ";
		}
		cout<<endl;
	}
}