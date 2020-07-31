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
        printf("д���ļ�ʧ��!");
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
            SetConsoleTitleA("���弸��");
            cout<<"���弸����3άŷ�Ͽռ�ļ��εĴ�ͳ����"<<endl<<"����Բ�뾶r��Բ����h"<<endl<<"���ɼ���Բ�ܳ�C1��Բ���Sa��Բ������Sb��Բ�����Va��Բ�����Vb��";
        }

        void cal()
        {
            system("cls");
            float r,h,C1,Sa,Sb,Va,Vb;
            cout<<"������Բ�뾶r��Բ����h���Կո�ֿ�:" ;
            cin>>r>>h;
            C1=2*PI*r;
            Sa=PI*r*r;
            Sb=4*PI*r*r;
            Va=4.0/3*PI*r*r*r;
            Vb=Sa*h;
            cout<<"Բ�ܳ�C1="<<C1<<endl<<"Բ���Sa="<<Sa<<endl<<"Բ������Sb="<<Sb<<endl<<"Բ�����Va="<<Va<<endl<<"Բ�����Vb="<<Vb<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }
};

class Factor{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("��Լ���빫����");
            cout<<"���������Ҳ�����Լ����������ӣ�ָ����������������Լ��������һ����"<<endl<<"���������������еı����������ǵĹ����������г�0������С��һ���������ͽ����⼸����������С��������" <<endl<<"����������������ȡ���ǵ����Լ������С������";
        }
        void cal()
        {
            system("cls");
            int a,b,num1,num2,temp;
            cout<<"�����������������Կո�ֿ�:";
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
            cout<<"���Լ��Ϊ:"<<a<<"��С������Ϊ:"<<num1*num2/a;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }
};

class factorial{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("�׳�");
            cout<<"һ���������Ľ׳�������С�ڼ����ڸ������������Ļ�������0�Ľ׳�Ϊ1��"<<endl<<"����һ���������Լ�����׳�";
        }

        void cal()
        {
            system("cls");
            int i,n;
            long long sn=0,t=1;
            cout<<"������һ�������Լ�����׳�:";
            cin>>n;
            for(i=1;i<=n;i++)
            {
                t*=i;
                sn+=t;
            }
            cout<<n<<"�Ľ׳�Ϊ"<<sn<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }
};

class Narcissistic{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("ˮ�ɻ���");
            cout<<"ˮ�ɻ�����ָһ����λ��������ÿ��λ�ϵ����ֵ� 3����֮�͵���������"<<endl<<"����һ�������б����Ƿ�Ϊˮ�ɻ�����";
        }

        void cal()
        {
            system("cls");
            int numB,a,b,c;
            cout<<"������һ������100С��1000������:";
            cin>>numB;
            a=numB%10;
            b=numB/10%10;
            c=numB/100;
            if(a*a*a+b*b*b+c*c*c==numB)
                cout<<"����һ��ˮ�ɻ���Ŷ(��'A'��):"<<numB<<endl;
            else
                cout<<"�ⲻ��һ��ˮ�ɻ�����-(�V?�V)��:"<<numB<<endl;
            system("pause");
        }
};

class Isomorphism{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("ͬ����");
            cout<<"������n������ƽ������β�������nΪͬ������"<<endl<<"����һ��������1000�������ҳ�С�����ͬ������";
        }

        void cal()
        {
            system("cls");
            int numB,num;
            cout<<"������һ��1000�������������:";
            cin>>numB;
            long result;
            cout<<numB<<"���ڵ�ͬ������:"<<endl;
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
            cout<<"<-----------------����ô����----------------->"<<endl;
            system("pause");
        }
};
#endif // MATHS_H
