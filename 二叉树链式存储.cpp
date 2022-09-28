#include<iostream.h>

class bintree;   //��������bintree��ǰ������
class node{
	friend class bintree;    //�����������bintreeΪ��Ԫ
public:
	node():lchild(0),rchild(0),fumu(0){}
	node(int val)                              //���ι��캯��
	{
		data=val;
		lchild=0;
		rchild=0;
		fumu=0;
	}
	node(int val,node *p,node *lptr=0, node *rptr=0)                        
	{        
		data=val;
		lchild=lptr;
		rchild=rptr;
		fumu=p;
	}
	int getdata(){return data;}         //���ؽ������
	node *left(){return lchild;}        //��������Ůָ��
	node *right(){return rchild;}       //��������Ůָ��
	node *fumu(){return fumu;}      //���ظ�ĸָ��
private:
	node *lchild,*rchild;
	node *fumu;
	int data;
};

class bintree{
public:
	bintree():root(0){}
	                                               //����һ�ſն�����
	~bintree(){destroy(root);}                     //��������
	void insertnode(int val){           //�����������ֵΪval�Ľ��
		insertnode(root,val,h);           
	}
	void preorder(){preorder(root);}    //�������������
	void inorder(){inorder(root);}      //�������������
	void postorder(){postorder(root);}  //�������������
	void lvorder(){lvorder(root);}      //�������������
private:
	node *root;                                  //�����ָ��
	void insertnode(node *&t,int val,node *p);   //��tָ��Ķ������а������������½ڵ�
	void preorder(node *t);                      //�������tָ��Ķ�����
	void inorder(node *t);                       //�������tָ��Ķ�����
	void postorder(node *t);                     //��������tָ��Ķ�����
	void lvorder(node *t);                       //�������tָ��Ķ�����
	void destroy(node *t);                       //ɾ��������
};

void bintree::insertnode(node *&t,int val,node *p){
	if(t==0) {
		if(p==0) t=new node(val);
		else t=new node(val,p);
	}
	else if(val<t->data) insertnode(t->lchild,val,t);
	else insertnode(t->rchild,val,t);
}
void bintree::preorder(node *t){
	if(t!=0){
		cout<<t->data<<" ";              //���ʸ����
		preorder(t->lchild);             //�������������
		preorder(t->rchild);             //�������������
	}
}
void bintree::inorder(node *t){          
	if(t!=0){            
		inorder(t->lchild);               //�������������
		cout<<t->data<<" ";               //���ʸ����
		inorder(t->rchild);               //�������������
	}
}
void bintree::postorder(node *t){
	if(t!=0){
		postorder(t->lchild);              //�������������
		postorder(t->rchild);              //�������������
		cout<<t->data<<" ";                //���ʸ����
	}
}
void bintree::lvorder(node *t){
	if(
void bintree::destroy(node *t){
	if(t!=0){
		destroy(t->lchild);                 //��������������������
		destroy(t->rchild);                 //��������������������
		delete t;                           //ɾ�������
	}
}

void main(){
	bintree btree;
	int x;
	cout<<"������10��������"<<endl;
	for(int i=0;i<10;i++){
		cin>>x;
		btree.insertnode(x);
	}
	cout<<"����������У�"<<endl;
	btree.preorder();
	cout<<endl<<"�����������:"<<endl;
	btree.inorder();
	cout<<endl<<"������������:"<<endl;
	btree.postorder();
	cout<<endl;
}