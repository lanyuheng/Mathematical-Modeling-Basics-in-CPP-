#include <iostream>  
#include <vector>  
#include <algorithm>  
 
using namespace std; 
 
typedef struct Node { 
    int val;     
    Node *left, *right, *parent;  //左右节点和父节点指针  
    void set(int value, Node *lft, Node *rgt) {  
        val = value;  
        left = lft;  
        right = rgt;  
        parent = NULL; 
    }; 
    Node() { 
        val = -1; 
        left = right = parent = NULL; 
    } 
} Node; 
 

vector<Node> nodes;        //存放节点的向量  
vector<int> pnodes;        //存放节点编号的向量  
int sum = 0;               //初始化最小带权路径和  
bool sortpnode(int a, int b)    //按照节点编号对应节点的值对编号进行排序  
{ 
    return nodes[a].val < nodes[b].val; 
} 
 
void output(Node *tree)      //利用递归遍历huffman树实现输出  
{ 
    Node *ptr; 
                                            //若当前节点为空，退出  
    if (tree == NULL) 
        return; 
                                           //否则，输出当前根节点的值  
    cout << tree->val << "-> Left: " << (tree->left ? tree->left->val : -1) << ", Right: " << (tree->right ? tree->right->val : -1) << endl; 
                                          //若左孩子不为空，则通过递归遍历左子树  
    if (tree->left)  
        output(tree->left); 
                                        //若左孩子已遍历，且右子树不为空，则通过递归遍历右子树  
    if (tree->right) 
        output(tree->right); 
                                      //若当前节点的左右孩子都为空，则说明该节点是叶子节点  
                                     //此时，计算其带权路径并求和  
    if (!tree->left && !tree->right) 
    { 
                                   //计算到根节点的长度  
        int level = 0; 
        ptr = tree->parent; 
        while(ptr != NULL) 
        { 
            level++; 
            ptr = ptr->parent; 
        }        
                                  //用叶子深度乘以  
        sum += level * tree->val;         
        cout << "深度：" << level << ", 节点值：" << tree->val << "，带权路径和=" << sum << endl;        
    } 
} 
 
int main() 
{ 
    int values[] = {1, 2, 3, 4, 5, 30, 5, 8},  
        n = sizeof(values)/sizeof(int);  
    int cnt = n; 
    Node *tnode; 
                               //直接在nodes中放入(2 + n) * n / 2  
    nodes.resize(2 * n - 1); 
                               //为pnodes设置n个元素，且每个元素——即节点编号为-1  
    pnodes.resize(n, -1); 
                              //为节点赋值  
    for(int i = 0; i < n; i++) 
    {        
        nodes[i].val = values[i];        
        pnodes[i] = i; 
    } 
                              //循环  
    while(pnodes.size() > 1) 
    { 
                              //按照节点编号所对象节点的值对节点编号排序  
        sort(pnodes.begin(), pnodes.end(), sortpnode); 
                               //0--n-1为已处理节点，cnt编号对应的为待处理节点  
        tnode = &nodes[cnt]; 
                               //为派生节点赋值并指定左、右孩子及父节点  
        tnode->val = nodes[pnodes[0]].val + nodes[pnodes[1]].val; 
        tnode->left = &nodes[pnodes[0]]; 
        tnode->right = &nodes[pnodes[1]]; 
        tnode->parent = NULL; 
                               //将派生节点编号加入pnodes向量  
        pnodes.insert(pnodes.begin(), cnt); 
                              //设置孩子节点的父节点地址  
        nodes[pnodes[1]].parent = &nodes[cnt]; 
        nodes[pnodes[2]].parent = &nodes[cnt]; 
                              //从pnodes中删除已处理的节点编号  
        pnodes.erase(pnodes.begin() + 1); 
        pnodes.erase(pnodes.begin() + 1); 
                              //设置下一个派生节点的编号  
        cnt++; 
    } 
                               //nodes[cnt-1]为树的根节点  
                                 //输出树  
    output(&nodes[cnt-1]); 
                                 //输出huffman树的最小带权路径长度  
    cout << "最小带权路径长为：" << sum << endl; 
    return 0; 
} 
