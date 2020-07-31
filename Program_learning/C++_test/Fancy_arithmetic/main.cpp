#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "Affine_crypto.h"
#include "Replacement_crypto.h"
#include "Caesar_crypto.h"
#include "Virginia_crypto.h"
#include "Maths.h"

#define	NR(x)	(sizeof(x)/sizeof(x[0]))
#define TITLE  "���������"
#define Welcome "��ӭʹ����������ϵͳ"
#define TITLE1 "��ѧ����"

using namespace std;

enum//ö�ټ�ֵ����
{
    UP = 72,
    DOWN = 80 ,
    LEFT = 75 ,
    RIGHT = 77 ,
    ENTER = 13 ,
    ESC = 27 ,
};

const char *menu[]=//���˵�
{
    "��      ��������     ��",
    "��      �û�����     ��",
    "��      ��������     ��",
    "��    ά����������   ��",
    "��      ��ѧ����     ��",
    "��        �˳�       ��",
};


CONSOLE_CURSOR_INFO cci;//����ṹ��
COORD pos={0,0};//��������


void showmenu(HANDLE hOut,const char **menu,int size,int index)//���˵�
{
    int i;
    system("cls");//���ÿ���̨
    SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_INTENSITY);//������ɫ
    pos.X=45;
    pos.Y=0;
    SetConsoleCursorPosition(hOut,pos);//���ù��λ��
    cout<<TITLE;
    pos.X=40;
    pos.Y=1;
    SetConsoleCursorPosition(hOut,pos);
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
    cout<<Welcome;
    for(i=0;i<size;i++)
    {
        if(i==index)
        {
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
            pos.X=39;
            pos.Y=3+i;
            SetConsoleCursorPosition(hOut,pos);
            cout<<menu[i];
        }
        else
        {
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            pos.X=39;
            pos.Y=3+i;
            SetConsoleCursorPosition(hOut,pos);
            cout<<menu[i];
        }
    }
    fflush(stdout);//ˢ�±�׼���������
}

int  get_userinput(int *index,int size)//��ȡ������������ȷ���˳�
{
    int gch;
    gch=getch();
    switch(gch)
    {
        case UP:	if(*index>0)		*index-=1;return 0;
        case DOWN:	if(*index<size-1)	*index+=1;return 0;
        case ENTER:	return ENTER;
        case ESC:	return ESC;
        default:	return 0;
    }
}

int choose_ed(HANDLE hOut,int flag)//�μ��˵�
{
    int index=0,ret,i;
    const char *menu1[]={"��    ����    ��",
    "��    ����    ��",
    "��    ����    ��"} ;
    const char *menu2[]={"��    ����    ��",
    "��    ����    ��"} ;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE |FOREGROUND_RED |FOREGROUND_INTENSITY);
    pos.X=40;
    pos.Y=2;
    SetConsoleCursorPosition(hOut,pos);
    if(flag)
    {
        cout<<"��ѡ����ܻ����" ;
        while(1)
        {
            for(i=0;i<NR(menu1);i++)
            {
                if(i==index)
                {
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
                    pos.X=41;
                    pos.Y=4+i;
                    SetConsoleCursorPosition(hOut,pos);
                    cout<<menu1[i];
                }
                else
                {
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    pos.X=41;
                    pos.Y=4+i;
                    SetConsoleCursorPosition(hOut,pos);
                    cout<<menu1[i];
                }
            }
            ret=get_userinput(&index,NR(menu1));
            if(ret==ESC)
                break ;
            if(ret==ENTER)
            {
                switch(index)
                {
                    case 0:return 1; 	//1
                    case 1:return 2; 	//2
                    case 2:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0;//�˳�
                };
            }
        }
    }
    else
    {
        while(1)
        {
            for(i=0;i<NR(menu2);i++)
            {
                if(i==index)
                {
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    pos.X=41;
                    pos.Y=4+i;
                    SetConsoleCursorPosition(hOut,pos);
                    cout<<menu2[i];
                }
                else
                {
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    pos.X=41;
                    pos.Y=4+i;
                    SetConsoleCursorPosition(hOut,pos);
                    cout<<menu2[i];
                }
            }
            fflush(stdout);
            ret=get_userinput(&index,NR(menu2));
            if(ret==ESC)
                break ;
            if(ret==ENTER)
            {
                switch(index)
                {
                    case 0:return 1; 	//1
                    case 1:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0;//�˳�
                }
            }
        }
    }
}

int menu_x(HANDLE hOut)//��ѧ����Ĵμ��˵�
{
    system("cls");
    int index=0,ret,i;
    const char *menu[]={"��       ���弸��       ��",
    "��    ��Լ���빫����    ��",
    "��         �׳�         ��",
    "��       ˮ�ɻ���       ��",
    "��        ͬ����        ��",
    "��         ����         ��"} ;
    SetConsoleTitleA(TITLE1);
    while(1)
    {
        system("cls");
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE |FOREGROUND_RED |FOREGROUND_INTENSITY);
        pos.X=46;
        pos.Y=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"��ѡ������" ;
        for(i=0;i<NR(menu);i++)
        {
            if(i==index)
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
                pos.X=38;
                pos.Y=3+i;
                SetConsoleCursorPosition(hOut,pos);
                cout<<menu[i];
            }
            else
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                pos.X=38;
                pos.Y=3+i;
                SetConsoleCursorPosition(hOut,pos);
                cout<<menu[i];
            }
        }
            ret=get_userinput(&index , NR(menu));
            if(ret==ESC)
                break ;
            if(ret==ENTER)
            {
                switch(index)
                {
                    case 0:Solid_geometry a;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);a.show_information();if(choose_ed(hOut,0)==1)	a.cal();else SetConsoleTitleA(TITLE1);break;
                    case 1:Factor b;		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);b.show_information();if(choose_ed(hOut,0)==1)	b.cal();else SetConsoleTitleA(TITLE1);break;
                    case 2:factorial c;		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);c.show_information();if(choose_ed(hOut,0)==1)	c.cal();else SetConsoleTitleA(TITLE1);break;
                    case 3:Narcissistic d;	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);d.show_information();if(choose_ed(hOut,0)==1)	d.cal();else SetConsoleTitleA(TITLE1);break;
                    case 4:Isomorphism e;	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);e.show_information();if(choose_ed(hOut,0)==1)	e.cal();else SetConsoleTitleA(TITLE1);break;
                    case 5:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0 ;//�˳�
                }
            }
    }
    fflush(stdout);
}


int main()
{
    int index=0,ret,rt;
    HANDLE hOut;
    SetConsoleTitleA(TITLE);//���ÿ���̨����
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);//����Ϊ��׼������
    GetConsoleCursorInfo(hOut,&cci);//��ȡ�����Ϣ
    cci.dwSize=1;//���ù���С
    cci.bVisible=0;//���ù�겻�ɼ�
    SetConsoleCursorInfo(hOut,&cci);//Ӧ������
    while(1)
    {
        showmenu(hOut,menu,NR(menu),index);
        ret=get_userinput(&index,NR(menu));
        if(ret==ESC)
            break ;
        if(ret==ENTER)
        {
            switch(index)
            {
                case 0:affine a;		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);a.show_information();	if((rt=choose_ed(hOut,1))==1)	a.en();else if(rt==2) a.de();SetConsoleTitleA(TITLE);break;  	//1
                case 1:replacement b;	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);b.show_information();	if((rt=choose_ed(hOut,1))==1)	b.en();else if(rt==2) b.de();SetConsoleTitleA(TITLE);break;  	//2
                case 2:caesar c;		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);c.show_information();	if((rt=choose_ed(hOut,1))==1)	c.en();else if(rt==2) c.de();SetConsoleTitleA(TITLE);break;  	//3
                case 3:virginia d;		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);d.show_information();	if((rt=choose_ed(hOut,1))==1)	d.en();else if(rt==2) d.de();SetConsoleTitleA(TITLE);break;  	//4
                case 4:menu_x(hOut);	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);SetConsoleTitleA(TITLE);break;  	//5
                case 5:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0;//�˳�
            }
        }
        fflush(stdout);
    }
    return 0;
}
