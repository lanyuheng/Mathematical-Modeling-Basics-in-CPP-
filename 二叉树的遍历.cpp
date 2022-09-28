#include<iostream>
using namespace std; 

class bintree;   //二叉树类bintree的前视声明
class node{
	friend class bintree;    //定义二叉树类bintree为友元
public:
	node():lchild(0),rchild(0){}
	node(int val,node *lptr=0, node *rptr=0)                        
	{        
		data=val;
		lchild=lptr;
		rchild=rptr;
	}
	int getdata(){return data;}         //返回结点数据
	node *left(){return lchild;}        //返回左子女指针
	node *right(){return rchild;}       //返回右子女指针
private:
	node *lchild,*rchild;
	int data;
};

class bintree{
public:
	bintree():root(0){}
	                                               //构造一颗空二叉树
	~bintree(){destroy(root);}                     //析构函数
	void insertnode(int val){           //向二叉树插入值为val的结点
		insertnode(root,val);           
	}
	void preorder(){preorder(root);}    //先序遍历二叉树
	void inorder(){inorder(root);}      //中序遍历二叉树
	void postorder(){postorder(root);}  //后序遍历二叉树
private:
	node *root;                                  //根结点指针
	void insertnode(node *&t,int val);   //向t指向的二叉树中按排序树插入新节点
	void preorder(node *t);                      //先序遍历t指向的二叉树
	void inorder(node *t);                       //中序遍历t指向的二叉树
	void postorder(node *t);                     //后续遍历t指向的二叉树
	void destroy(node *t);                       //删除二叉树
};

void bintree::insertnode(node *&t,int val){
	if(t==0)
		t=new node(val);
	else if(val<t->data) insertnode(t->lchild,val);
	else insertnode(t->rchild,val);
}
void bintree::preorder(node *t){
	if(t!=0){
		cout<<t->data<<" ";              //访问根结点
		preorder(t->lchild);             //先序遍历左子树
		preorder(t->rchild);             //先序遍历右子树
	}
}
void bintree::inorder(node *t){          
	if(t!=0){            
		inorder(t->lchild);               //中序遍历左子树
		cout<<t->data<<" ";               //访问根结点
		inorder(t->rchild);               //中序遍历右子树
	}
}
void bintree::postorder(node *t){
	if(t!=0){
		postorder(t->lchild);              //后序遍历左子树
		postorder(t->rchild);              //后序遍历右子树
		cout<<t->data<<" ";                //访问根结点
	}
}
void bintree::destroy(node *t){
	if(t!=0){
		destroy(t->lchild);                 //对左子树调用析构函数
		destroy(t->rchild);                 //对右子树调用析构函数
		delete t;                           //删除根结点
	}
}

int main(){
	bintree btree;
	int x;
	cout<<"请输入10个整数："<<endl;
	for(int i=0;i<10;i++){
		cin>>x;
		btree.insertnode(x);
	}
	cout<<"先序遍历序列："<<endl;
	btree.preorder();
	cout<<endl<<"中序遍历序列:"<<endl;
	btree.inorder();
	cout<<endl<<"后续遍历序列:"<<endl;
	btree.postorder();
	cout<<endl;
}
