#include<iostream>
#include<stdlib.h>
#include "io.cpp"
#include "cc.cpp"
#include "degree.cpp"
#include "rand.cpp"
#include "spath.cpp"
void main()
{
	int v;
	cout<<"请输入点的个数:";
	cin>>v;
	graph g(v);
	/*edge a;
	cout<<"请输入连通边的端点，停止输入时取两边为负值:";
	a.v=1;a.w=1;
	while(a.v>=0||a.w>=0)
	{
		cin>>a.v>>a.w;
		if(a.v>=0&&a.w>=0)
		g.insert(a);
	}*/
	cout<<"请输入随机生成边的大致个数:";
	int e;
	cin>>e;
	//rande(g,e);
	randg(g,e);
	io<graph>::show(g);
	cout<<"对应点的度数分别为:";
	Degree<graph>::print(g);
	cout<<endl<<"边数为"<<g.e();
	cc<graph> gcc(g);
	cout<<endl<<"连通分支个数为"<<gcc.count()<<endl;
	/*cout<<"判断任意两点是否连通,请依次输入两端点:";
	int i,j;
	cin>>i>>j;
	cout<<"是否连通:";
	gcc.connect(i,j);
	cout<<endl;*/
	cout<<"简单路径搜索,请依次输入两端点:";
	int i,j;
	cin>>i>>j;
	cout<<endl<<"是否连通:";
	gcc.connect(i,j);
	cout<<endl<<"路径依次为为:";
	spath<graph> spathrr(g,i,j);
	cout<<spathrr.exists();
	cout<<endl;
}