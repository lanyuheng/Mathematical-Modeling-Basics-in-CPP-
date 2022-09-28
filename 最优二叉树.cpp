#include <iostream>  
#include <vector>  
#include <algorithm>  
 
using namespace std; 
 
typedef struct Node { 
    int val;     
    Node *left, *right, *parent;  //���ҽڵ�͸��ڵ�ָ��  
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
 

vector<Node> nodes;        //��Žڵ������  
vector<int> pnodes;        //��Žڵ��ŵ�����  
int sum = 0;               //��ʼ����С��Ȩ·����  
bool sortpnode(int a, int b)    //���սڵ��Ŷ�Ӧ�ڵ��ֵ�Ա�Ž�������  
{ 
    return nodes[a].val < nodes[b].val; 
} 
 
void output(Node *tree)      //���õݹ����huffman��ʵ�����  
{ 
    Node *ptr; 
                                            //����ǰ�ڵ�Ϊ�գ��˳�  
    if (tree == NULL) 
        return; 
                                           //���������ǰ���ڵ��ֵ  
    cout << tree->val << "-> Left: " << (tree->left ? tree->left->val : -1) << ", Right: " << (tree->right ? tree->right->val : -1) << endl; 
                                          //�����Ӳ�Ϊ�գ���ͨ���ݹ����������  
    if (tree->left)  
        output(tree->left); 
                                        //�������ѱ���������������Ϊ�գ���ͨ���ݹ����������  
    if (tree->right) 
        output(tree->right); 
                                      //����ǰ�ڵ�����Һ��Ӷ�Ϊ�գ���˵���ýڵ���Ҷ�ӽڵ�  
                                     //��ʱ���������Ȩ·�������  
    if (!tree->left && !tree->right) 
    { 
                                   //���㵽���ڵ�ĳ���  
        int level = 0; 
        ptr = tree->parent; 
        while(ptr != NULL) 
        { 
            level++; 
            ptr = ptr->parent; 
        }        
                                  //��Ҷ����ȳ���  
        sum += level * tree->val;         
        cout << "��ȣ�" << level << ", �ڵ�ֵ��" << tree->val << "����Ȩ·����=" << sum << endl;        
    } 
} 
 
int main() 
{ 
    int values[] = {1, 2, 3, 4, 5, 30, 5, 8},  
        n = sizeof(values)/sizeof(int);  
    int cnt = n; 
    Node *tnode; 
                               //ֱ����nodes�з���(2 + n) * n / 2  
    nodes.resize(2 * n - 1); 
                               //Ϊpnodes����n��Ԫ�أ���ÿ��Ԫ�ء������ڵ���Ϊ-1  
    pnodes.resize(n, -1); 
                              //Ϊ�ڵ㸳ֵ  
    for(int i = 0; i < n; i++) 
    {        
        nodes[i].val = values[i];        
        pnodes[i] = i; 
    } 
                              //ѭ��  
    while(pnodes.size() > 1) 
    { 
                              //���սڵ���������ڵ��ֵ�Խڵ�������  
        sort(pnodes.begin(), pnodes.end(), sortpnode); 
                               //0--n-1Ϊ�Ѵ���ڵ㣬cnt��Ŷ�Ӧ��Ϊ������ڵ�  
        tnode = &nodes[cnt]; 
                               //Ϊ�����ڵ㸳ֵ��ָ�����Һ��Ӽ����ڵ�  
        tnode->val = nodes[pnodes[0]].val + nodes[pnodes[1]].val; 
        tnode->left = &nodes[pnodes[0]]; 
        tnode->right = &nodes[pnodes[1]]; 
        tnode->parent = NULL; 
                               //�������ڵ��ż���pnodes����  
        pnodes.insert(pnodes.begin(), cnt); 
                              //���ú��ӽڵ�ĸ��ڵ��ַ  
        nodes[pnodes[1]].parent = &nodes[cnt]; 
        nodes[pnodes[2]].parent = &nodes[cnt]; 
                              //��pnodes��ɾ���Ѵ���Ľڵ���  
        pnodes.erase(pnodes.begin() + 1); 
        pnodes.erase(pnodes.begin() + 1); 
                              //������һ�������ڵ�ı��  
        cnt++; 
    } 
                               //nodes[cnt-1]Ϊ���ĸ��ڵ�  
                                 //�����  
    output(&nodes[cnt-1]); 
                                 //���huffman������С��Ȩ·������  
    cout << "��С��Ȩ·����Ϊ��" << sum << endl; 
    return 0; 
} 
