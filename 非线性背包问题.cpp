#include <iostream>   
using namespace std;   
  
const int N = 3;  
  
void Knapsack(int n,float M,float v[],float w[],float x[]);  
  
int main()  
{  
    float M = 50;//背包所能容纳的重量  
    //这里给定的物品按单位价值减序排序  
    float w[] = {0,10,20,30};//下标从1开始  
    float v[] = {0,60,100,120};  
  
    float x[N+1];  
  
    cout<<"背包所能容纳的重量为："<<M<<endl;  
    cout<<"待装物品的重量和价值分别为："<<endl;  
    for(int i=1; i<=N; i++)  
    {  
        cout<<"["<<i<<"]:("<<w[i]<<","<<v[i]<<")"<<endl;  
    }  
      
    Knapsack(N,M,v,w,x);  
  
    cout<<"选择装下的物品比例如下："<<endl;  
    for(int i=1; i<=N; i++)  
    {  
        cout<<"["<<i<<"]:"<<x[i]<<endl;  
    }  
  
    return 0;  
}  
  
void Knapsack(int n,float M,float v[],float w[],float x[])  
{  
    //Sort(n,v,w);//这里假定w[],v[]已按要求排好序  
    int i;  
    for (i=1;i<=n;i++)  
    {  
        x[i]=0;//初始化数组x[]  
    }  
  
    float c=M;  
    for (i=1;i<=n;i++)//物品整件被装下,x[i]=1  
    {  
        if (w[i]>c)  
        {  
            break;  
        }  
        x[i]=1;  
        c-=w[i];  
    }  
  
    //物品i只有部分被装下  
    if (i<=n)  
    {  
        x[i]=c/w[i];  
    }  
}  
