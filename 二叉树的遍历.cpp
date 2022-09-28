#include<iostream>
using namespace std; 

class bintree;   //��������bintree��ǰ������
class node{
	friend class bintree;    //�����������bintreeΪ��Ԫ
public:
	node():lchild(0),rchild(0){}
	node(int val,node *lptr=0, node *rptr=0)                        
	{        
		data=val;
		lchild=lptr;
		rchild=rptr;
	}
	int getdata(){return data;}         //���ؽ������
	node *left(){return lchild;}        //��������Ůָ��
	node *right(){return rchild;}       //��������Ůָ��
private:
	node *lchild,*rchild;
	int data;
};

class bintree{
public:
	bintree():root(0){}
	                                               //����һ�ſն�����
	~bintree(){destroy(root);}                     //��������
	void insertnode(int val){           //�����������ֵΪval�Ľ��
		insertnode(root,val);           
	}
	void preorder(){preorder(root);}    //�������������
	void inorder(){inorder(root);}      //�������������
	void postorder(){postorder(root);}  //�������������
private:
	node *root;                                  //�����ָ��
	void insertnode(node *&t,int val);   //��tָ��Ķ������а������������½ڵ�
	void preorder(node *t);                      //�������tָ��Ķ�����
	void inorder(node *t);                       //�������tָ��Ķ�����
	void postorder(node *t);                     //��������tָ��Ķ�����
	void destroy(node *t);                       //ɾ��������
};

void bintree::insertnode(node *&t,int val){
	if(t==0)
		t=new node(val);
	else if(val<t->data) insertnode(t->lchild,val);
	else insertnode(t->rchild,val);
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
void bintree::destroy(node *t){
	if(t!=0){
		destroy(t->lchild);                 //��������������������
		destroy(t->rchild);                 //��������������������
		delete t;                           //ɾ�������
	}
}

int main(){
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
