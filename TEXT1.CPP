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
	cout<<"�������ĸ���:";
	cin>>v;
	graph g(v);
	/*edge a;
	cout<<"��������ͨ�ߵĶ˵㣬ֹͣ����ʱȡ����Ϊ��ֵ:";
	a.v=1;a.w=1;
	while(a.v>=0||a.w>=0)
	{
		cin>>a.v>>a.w;
		if(a.v>=0&&a.w>=0)
		g.insert(a);
	}*/
	cout<<"������������ɱߵĴ��¸���:";
	int e;
	cin>>e;
	//rande(g,e);
	randg(g,e);
	io<graph>::show(g);
	cout<<"��Ӧ��Ķ����ֱ�Ϊ:";
	Degree<graph>::print(g);
	cout<<endl<<"����Ϊ"<<g.e();
	cc<graph> gcc(g);
	cout<<endl<<"��ͨ��֧����Ϊ"<<gcc.count()<<endl;
	/*cout<<"�ж����������Ƿ���ͨ,�������������˵�:";
	int i,j;
	cin>>i>>j;
	cout<<"�Ƿ���ͨ:";
	gcc.connect(i,j);
	cout<<endl;*/
	cout<<"��·������,�������������˵�:";
	int i,j;
	cin>>i>>j;
	cout<<endl<<"�Ƿ���ͨ:";
	gcc.connect(i,j);
	cout<<endl<<"·������ΪΪ:";
	spath<graph> spathrr(g,i,j);
	cout<<spathrr.exists();
	cout<<endl;
}