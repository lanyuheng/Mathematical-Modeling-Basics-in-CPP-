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
  
  
struct Circle_wood //Բ����ľͷ�����ݽṹ  
{  
    double x,y,r;  
    int sel;      //�ж��Ƿ�ͱ����ཻ  
}cr[MAXNUM];  
  
double dis(Circle_wood a,double x,double y) //����ԲԲ�ľ�  
{  
    return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));  
}  
  
int sort(Circle_wood *wood,int n)//��Բ���뾶�ɴ�С����    
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
  
int put(int now,double tx,double ty)//�ж���λ��(tx,ty)�Ƿ���Է���  
{  
    if(tx<cr[now].r || tx+cr[now].r>W || ty<cr[now].r || ty+cr[now].r>H)  
        return 0; //���ܷ��£�Խ��  
    for(int i=0;i<now;i++)  
        if(cr[i].sel)//�ж��Ƿ�ͱ����ཻ  
            if(dis(cr[i],tx,ty)<(cr[i].r+cr[now].r-0.01)) //�ཻ  
                return 0;  
    return 1;  
}  
  
void check(int now)//Ϊ��now��ľͷ��λ��  
{   
    double t,dx,dy;  
    for(int i=0;i<now;i++)  
    if(cr[i].sel)//��ÿ���Ѳ����ľͷ  
    {  
        t=cr[i].r+cr[now].r;  
        for(int j=0;j<=360; j++)//��ÿ���ǶȽ��м��  
        {   
            dx=cr[i].x+t*cos(-pi/2.0 + j*pi/180.0);  
            dy=cr[i].y+t*sin(-pi/2.0 + j*pi/180.0);  
            if(put(now,dx,dy)==1)//�ҵ�����λ����  
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
  
void Gdy()//ȷ�����겢ʵ��ľ�ĵĶ�λ  
{  
    count=0;int i;  
    for(i=0;i<columnum;i++) //��ʼ��  
        cr[i].sel=0;   
    for(i=0;i<columnum;i++)  
    {  
        if(count==0 && cr[i].r <= H/2 &&cr[i].r <=W/2)//��һ���ܷŽ���  
        {  
            cr[i].x=cr[i].r;  
            cr[i].y=cr[i].r;  
            cr[i].sel=1;  
            count++;  
        }  
        else  
            check(i); //�������ľͷ  
    }  
      
}  
  
  
void draw()//��ͼ  
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
    HPEN   hpen1   = CreatePen( PS_SOLID, 1, RGB(255,200,200) );// ����ǳɫ1���ؿ�ȵ�ʵ�߻���   
    HPEN   hpen2   = CreatePen( PS_DASH, 5, RGB(0,255,0) ); // ������ɫ5���ؿ�ȵ����ۻ���  
    HBRUSH hbrush1 = CreateSolidBrush( RGB(60,60,60) ); // ����һ��ʵ����ɫ��ˢ   
    HBRUSH hbrush2 = CreateSolidBrush( RGB(255,255,255) ); //��ɫ   
    //HBRUSH hbrush3 = CreateSolidBrush( RGB(0,255,64) );//��ɫ  
    //HBRUSH hbrush4 = CreateSolidBrush( RGB(128,255,0) );  
    //HBRUSH hbrush5 = CreateSolidBrush( RGB(255,0,128) );//��ɫ  
  
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
  
            Ellipse( hdc,(int)(200+20*(cr[i].x-cr[i].r)), (int)(400-20*(cr[i].y+cr[i].r)), (int)(200+20*(cr[i].x+cr[i].r)), (int)(400-20*(cr[i].y-cr[i].r)) );//��Բ  
            TextOut( hdc,(int)(200+20*cr[i].x),(int)(400-20*cr[i].y),S[i+1],2); //i,signed i+1; �������ֱ��  
            //TextOut( hdc,(int)(200+20*cr[i].x),(int)(400-20*cr[i].y),cr[i].r,2); //i,signed i+1; �������ֱ��  
        }  
        Sleep(750);  
    }  
    TextOut( hdc,(int)(200+20*cr[t].x),(int)(400-20*cr[t].y),S[t+1],2); //���һ��Բ����ľͷ����  
}  
  
  
int main()//������  
{  
    FILE *fp;  
    char filename[20];  
    long start; //���Լ����������ʱ��  
    double area =0;  
    int i;  
  
    //printf(" �����������ļ�:"); //����Բ����ľͷ����  
    //scanf("%s",filename);  
      
    if((fp=fopen("123.txt","r"))==NULL)  
    {  
        printf(" �����ļ�������!\n ");//�ļ����������˳�  
        exit(0);  
    }  
    start=GetTickCount();  
    //fscanf(fp,"%d",&columnum);  
    cout<<"������Բ��������";  
    cin>>columnum;  
    cout<<"��װ��Ŀ�";  
    cin>>W;  
    cout<<"��װ��ĸߣ�";  
    cin>>H;  
    //cout<<"��װ��ĳ���";  
    //cin>>L;  
    for(i=0;i<columnum;i++)   
        fscanf(fp,"%lf",&cr[i].r);   
    sort(cr,columnum); //�Ƚ��ж�ľͷ������  
    Gdy(); //����Ǳ���������庯��  
    for(i=0;i<columnum;i++) //����һ��ľͷ��ռ�е����  
        if(cr[i].sel)   
            area += pi*cr[i].r*cr[i].r;   
    draw(); //����ͼ��  
    //printf(" %ld\n",columnum);  
    //printf("%lf\n%lf\n%lf\n",W,H);  
    for(i=0;i<columnum && cr[i].sel==1;i++)  
    {  
        cout<<"��װ���Բ�����Ϊ"<<i<<endl;  
    }  
    printf(" װ���������Ϊ:%lf\n",area);  
    printf(" ��װ��������Ϊ:%lf%%\n",area/(W*H)*100);//���㼯װ��������  
    printf(" ��������ʱ��Ϊ:%f��\n ",(GetTickCount()-start)/1000.0); //�����������ʱ��  
    getchar();  
    getchar();  
    return 0;  
}  
