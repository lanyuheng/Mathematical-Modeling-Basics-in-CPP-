#include<bits/stdc++.h>  
using namespace std;  
int p1,p2,p3,p4,p5,p6,sum;  
main()  
{  
    while(scanf("%d%d%d%d%d%d",&p1,&p2,&p3,&p4,&p5,&p6)&&p1+p2+p3+p4+p5+p6)  
    {  
        sum=0;  
        sum=p6+p5+p4;  
        p1-=min(p1,p5*11);  
        if(p2<p4*5)  
            p1-=min(p1,(p4*5-p2)*4);  
        p2-=min(p2,p4*5);  
        p5=p4=0;  
        sum+=ceil(p3/4.0);  
        p3%=4;  
        if(p3==1)  
        {  
            if(p2<5) p1-=min(p1,(5-p2)*4);  
            p1-=min(p1,7);  
            p2-=min(p2,5);  
        }  
        if(p3==2)  
        {  
            if(p2<3) p1-=min(p1,(3-p2)*4);  
            p1-=min(p1,6);  
            p2-=min(p2,3);  
        }  
        if(p3==3)  
        {  
            if(!p2) p1-=min(p1,4);  
            p1-=min(p1,5);  
            p2-=min(p2,1);  
        }  
        sum+=ceil(p2/9.0);  
        p2%=9;  
        if(p2) p1-=min(p1,4*(9-p2));  
        sum+=ceil(p1/36.0);  
        printf("%d\n",sum);  
    }  
}  
