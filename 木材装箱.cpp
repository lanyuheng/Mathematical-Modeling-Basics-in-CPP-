#include <iostream>  
#include <stdio.h>  
#include <graphics.h>  
#include <conio.h>  
#include <math.h>  
//#include <stdlib.h>  
using namespace std;  
  
#define MAXNUM 100  
#define pi 3.141592653589  
  
int columnum,count;  
float H,W;  
  
  
struct Circle_wood //圆柱形木头的数据结构  
{  
    double x,y,r;  
    int sel;      //判断是否和别人相交  
}cr[MAXNUM];  
  
double dis(Circle_wood a,double x,double y) //两个圆圆心距  
{  
    return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));  
}  
  
int sort(Circle_wood *wood,int n)//按圆柱半径由大到小排序    
{  
    Circle_wood a;  
    int j;  
    for(int i=0;i<columnum;i++)  
    {   
        a=wood[i];  
        j=i-1;  
        while(j>=0 && wood[j].r<a.r)  
        {  
            wood[j+1]=wood[j];  
            j=j-1;  
        }  
        wood[j+1]=a;  
    }  
      
    return 0;  
}  
  
int put(int now,double tx,double ty)//判断在位置(tx,ty)是否可以放下  
{  
    if(tx<cr[now].r || tx+cr[now].r>W || ty<cr[now].r || ty+cr[now].r>H)  
        return 0; //不能放下，越界  
    for(int i=0;i<now;i++)  
        if(cr[i].sel)//判断是否和别人相交  
            if(dis(cr[i],tx,ty)<(cr[i].r+cr[now].r-0.01)) //相交  
                return 0;  
    return 1;  
}  
  
void check(int now)//为第now个木头找位置  
{   
    double t,dx,dy;  
    for(int i=0;i<now;i++)  
    if(cr[i].sel)//对每个已插入的木头  
    {  
        t=cr[i].r+cr[now].r;  
        for(int j=0;j<=360; j++)//对每个角度进行检查  
        {   
            dx=cr[i].x+t*cos(-pi/2.0 + j*pi/180.0);  
            dy=cr[i].y+t*sin(-pi/2.0 + j*pi/180.0);  
            if(put(now,dx,dy)==1)//找到合适位置了  
            {   
                count++;  
                cr[now].x=dx;  
                cr[now].y=dy;  
                cr[now].sel=1;  
                return ;  
            }  
        }  
    }  
}  
  
void Gdy()//确定坐标并实现木材的定位  
{  
    count=0;int i;  
    for(i=0;i<columnum;i++) //初始化  
        cr[i].sel=0;   
    for(i=0;i<columnum;i++)  
    {  
        if(count==0 && cr[i].r <= H/2 &&cr[i].r <=W/2)//第一个能放进的  
        {  
            cr[i].x=cr[i].r;  
            cr[i].y=cr[i].r;  
            cr[i].sel=1;  
            count++;  
        }  
        else  
            check(i); //检查其他木头  
    }  
      
}  
  
  
void draw()//画图  
{  
    int t=0;  
    int k,j;  
    char *S[MAXNUM]={"0 ","1 ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","11","12","13","14","15","16","17","18","19","20",  
    "21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45"};  
    /* 
    int *S[20]; 
    for(k=0,j=0;k<columnum;k++) 
    { 
        if(cr[k].sel==1) 
        {  
           *S[j]=(int)cr[k].r; 
           j++; 
        } 
    } 
    */  
    HBRUSH hbrush_old;  
    HDC    hdc     = GetWindowDC( GetDesktopWindow() );  
    HPEN   hpen1   = CreatePen( PS_SOLID, 1, RGB(255,200,200) );// 创建浅色1像素宽度的实线画笔   
    HPEN   hpen2   = CreatePen( PS_DASH, 5, RGB(0,255,0) ); // 创建绿色5像素宽度的破折画笔  
    HBRUSH hbrush1 = CreateSolidBrush( RGB(60,60,60) ); // 创建一个实体蓝色画刷   
    HBRUSH hbrush2 = CreateSolidBrush( RGB(255,255,255) ); //紫色   
    //HBRUSH hbrush3 = CreateSolidBrush( RGB(0,255,64) );//绿色  
    //HBRUSH hbrush4 = CreateSolidBrush( RGB(128,255,0) );  
    //HBRUSH hbrush5 = CreateSolidBrush( RGB(255,0,128) );//紫色  
  
    HPEN   hpen_old= (HPEN)SelectObject( hdc, hpen1 );  
    hbrush_old     = (HBRUSH)SelectObject( hdc, hbrush1);  
    Rectangle(hdc,200,400,200+(int)(W*20),400-(int)(H*20));   
    for(int i=0;i<columnum;i++)  
    {  
        if(i%4==0)  
            hbrush_old = (HBRUSH)SelectObject( hdc, hbrush2);  
        else if(i%4==1)  
            hbrush_old = (HBRUSH)SelectObject( hdc, hbrush2);  
        else if(i%4==2)   
            hbrush_old = (HBRUSH)SelectObject( hdc, hbrush2);  
        else  
            hbrush_old = (HBRUSH)SelectObject( hdc, hbrush2);  
        if(cr[i].sel)  
        {  
            t=i;  
  
            Ellipse( hdc,(int)(200+20*(cr[i].x-cr[i].r)), (int)(400-20*(cr[i].y+cr[i].r)), (int)(200+20*(cr[i].x+cr[i].r)), (int)(400-20*(cr[i].y-cr[i].r)) );//画圆  
            TextOut( hdc,(int)(200+20*cr[i].x),(int)(400-20*cr[i].y),S[i+1],2); //i,signed i+1; 并用数字标记  
            //TextOut( hdc,(int)(200+20*cr[i].x),(int)(400-20*cr[i].y),cr[i].r,2); //i,signed i+1; 并用数字标记  
        }  
        Sleep(750);  
    }  
    TextOut( hdc,(int)(200+20*cr[t].x),(int)(400-20*cr[t].y),S[t+1],2); //最后一个圆柱形木头放入  
}  
  
  
int main()//主函数  
{  
    FILE *fp;  
    char filename[20];  
    long start; //用以计算程序运行时间  
    double area =0;  
    int i;  
  
    //printf(" 请输入数据文件:"); //读入圆柱形木头数据  
    //scanf("%s",filename);  
      
    if((fp=fopen("123.txt","r"))==NULL)  
    {  
        printf(" 输入文件不存在!\n ");//文件不存在则退出  
        exit(0);  
    }  
    start=GetTickCount();  
    //fscanf(fp,"%d",&columnum);  
    cout<<"请输入圆柱个数：";  
    cin>>columnum;  
    cout<<"集装箱的宽：";  
    cin>>W;  
    cout<<"集装箱的高：";  
    cin>>H;  
    //cout<<"集装箱的长：";  
    //cin>>L;  
    for(i=0;i<columnum;i++)   
        fscanf(fp,"%lf",&cr[i].r);   
    sort(cr,columnum); //先进行对木头的排序  
    Gdy(); //这个是本程序的主体函数  
    for(i=0;i<columnum;i++) //计算一个木头所占有的面积  
        if(cr[i].sel)   
            area += pi*cr[i].r*cr[i].r;   
    draw(); //画出图形  
    //printf(" %ld\n",columnum);  
    //printf("%lf\n%lf\n%lf\n",W,H);  
    for(i=0;i<columnum && cr[i].sel==1;i++)  
    {  
        cout<<"可装入的圆柱序号为"<<i<<endl;  
    }  
    printf(" 装入货物的面积为:%lf\n",area);  
    printf(" 集装箱利用率为:%lf%%\n",area/(W*H)*100);//计算集装箱利用率  
    printf(" 程序运行时间为:%f秒\n ",(GetTickCount()-start)/1000.0); //计算程序运行时间  
    getchar();  
    getchar();  
    return 0;  
}  
