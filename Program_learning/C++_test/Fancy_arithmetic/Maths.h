#ifndef MATHS_H
#define MATHS_H

#define PI 3.1416

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <Windows.h>
#include <fstream>
#include <cmath>

using namespace std;

int save(char *s,char name[])
{
    strcat(name,".txt");
    ofstream fpw;
    fpw.open(name,ios::out | ios::in | ios::ate);
    if(!fpw)
    {
        printf("写入文件失败!");
        return 0;
    }
    fpw<<s<<endl;
    fpw.close();
    return 1;
}

class Solid_geometry{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("立体几何");
            cout<<"立体几何是3维欧氏空间的几何的传统名称"<<endl<<"输入圆半径r，圆柱高h"<<endl<<"即可计算圆周长C1、圆面积Sa、圆球表面积Sb、圆球体积Va、圆柱体积Vb。";
        }

        void cal()
        {
            system("cls");
            float r,h,C1,Sa,Sb,Va,Vb;
            cout<<"请输入圆半径r，圆柱高h，以空格分开:" ;
            cin>>r>>h;
            C1=2*PI*r;
            Sa=PI*r*r;
            Sb=4*PI*r*r;
            Va=4.0/3*PI*r*r*r;
            Vb=Sa*h;
            cout<<"圆周长C1="<<C1<<endl<<"圆面积Sa="<<Sa<<endl<<"圆球表面积Sb="<<Sb<<endl<<"圆球体积Va="<<Va<<endl<<"圆柱体积Vb="<<Vb<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }
};

class Factor{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("公约数与公倍数");
            cout<<"最大公因数，也称最大公约数、最大公因子，指两个或多个整数共有约数中最大的一个。"<<endl<<"两个或多个整数公有的倍数叫做它们的公倍数，其中除0以外最小的一个公倍数就叫做这几个整数的最小公倍数。" <<endl<<"输入两个整数将求取它们的最大公约数和最小公倍数";
        }
        void cal()
        {
            system("cls");
            int a,b,num1,num2,temp;
            cout<<"请输入两个整数，以空格分开:";
            cin>>num1>>num2;
            if(num1<num2)
            {
                temp=num1;
                num1=num2;
                num2=temp;
            }
            a=num1;
            b=num2;
            while(b!=0)
            {
                temp=a%b;
                a=b;
                b=temp;
            }
            cout<<"最大公约数为:"<<a<<"最小公倍数为:"<<num1*num2/a;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }
};

class factorial{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("阶乘");
            cout<<"一个正整数的阶乘是所有小于及等于该数的正整数的积，并且0的阶乘为1。"<<endl<<"输入一个整数可以计算其阶乘";
        }

        void cal()
        {
            system("cls");
            int i,n;
            long long sn=0,t=1;
            cout<<"请输入一个整数以计算其阶乘:";
            cin>>n;
            for(i=1;i<=n;i++)
            {
                t*=i;
                sn+=t;
            }
            cout<<n<<"的阶乘为"<<sn<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }
};

class Narcissistic{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("水仙花数");
            cout<<"水仙花数是指一个三位数，它的每个位上的数字的 3次幂之和等于它本身。"<<endl<<"输入一个数以判别其是否为水仙花数。";
        }

        void cal()
        {
            system("cls");
            int numB,a,b,c;
            cout<<"请输入一个大于100小于1000的数字:";
            cin>>numB;
            a=numB%10;
            b=numB/10%10;
            c=numB/100;
            if(a*a*a+b*b*b+c*c*c==numB)
                cout<<"这是一个水仙花数哦(●'A'●):"<<numB<<endl;
            else
                cout<<"这不是一个水仙花数惹-(￢?￢)σ:"<<numB<<endl;
            system("pause");
        }
};

class Isomorphism{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("同构数");
            cout<<"正整数n若是它平方数的尾部，则称n为同构数。"<<endl<<"输入一个不大于1000的数以找出小于其的同构数。";
        }

        void cal()
        {
            system("cls");
            int numB,num;
            cout<<"请输入一个1000以内任意的数字:";
            cin>>numB;
            long result;
            cout<<numB<<"以内的同构数有:"<<endl;
            for(num=numB;numB>=1;numB--)
            {
                result=pow(numB,2);
                if(numB<10&&numB==result%10)
                    cout<<numB<<endl;
                else if(numB>=10&&numB==result%100)
                    cout<<numB<<endl;
                else if(numB>=100&&numB==result%1000)
                    cout<<numB<<endl;
                else	continue;
            }
            cout<<"<-----------------就这么多啦----------------->"<<endl;
            system("pause");
        }
};
#endif // MATHS_H
