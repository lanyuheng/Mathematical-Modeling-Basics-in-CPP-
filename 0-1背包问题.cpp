#include <iostream>   
using namespace std;   
  
const int N = 4;  
  
template <class Type>    
void Swap(Type &x,Type &y);   
  
template<class Type>  
void Loading(int x[],  Type w[], Type c, int n);  
  
template<class Type>  
void SelectSort(Type w[],int *t,int n);  
  
int main()  
{  
    float c = 70;  
    float w[] = {0,20,10,26,15};//�±��1��ʼ  
    int x[N+1];  
  
    cout<<"�ִ�����Ϊ��"<<c<<endl;  
    cout<<"��װ��Ʒ�������ֱ�Ϊ��"<<endl;  
    for(int i=1; i<=N; i++)  
    {  
        cout<<w[i]<<" ";  
    }  
    cout<<endl;  
    Loading(x,w,c,N);  
  
    cout<<"̰��ѡ����Ϊ:"<<endl;  
    for(int i=1; i<=N; i++)  
    {  
        cout<<x[i]<<" ";  
    }  
    cout<<endl;  
  
    return 0;  
}  
  
template<class Type>  
void Loading(int x[],Type w[], Type c, int n)  
{  
    int *t = new int [n+1];//�洢�������w[]��ԭʼ����  
    SelectSort(w, t, n);  
  
    for(int i=1; i<=n; i++)  
    {  
        x[i] = 0;//��ʼ������x[]  
    }  
    for(int i=1; i<=n && w[t[i]]<=c; i++)  
    {  
        x[t[i]] = 1;  
        c -= w[t[i]];  
    }  
}  
  
template<class Type>  
void SelectSort(Type w[],int *t,int n)  
{  
    Type tempArray[N+1],temp;  
    memcpy(tempArray,w,(n+1)*sizeof(Type));//��w��������ʱ����tempArray��  
    int min;  
  
    for(int i=1;i<=n;i++)  
    {  
        t[i] = i;  
    }  
  
    for(int i=1;i<n;i++)  
    {  
        min=i;  
        for(int j=i+1;j<=n;j++)  
        {  
            if(tempArray[min]>tempArray[j])  
            {  
                min=j;  
            }  
        }  
        Swap(tempArray[i],tempArray[min]);  
        Swap(t[i],t[min]);  
    }  
}  
  
template <class Type>    
void Swap(Type &x,Type &y)  
{  
    Type temp = x;    
    x = y;    
    y = temp;    
}  
