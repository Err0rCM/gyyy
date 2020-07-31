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
#define TITLE  "奇妙的运算"
#define Welcome "欢迎使用奇妙运算系统"
#define TITLE1 "数学运算"

using namespace std;

enum//枚举键值数据
{
    UP = 72,
    DOWN = 80 ,
    LEFT = 75 ,
    RIGHT = 77 ,
    ENTER = 13 ,
    ESC = 27 ,
};

const char *menu[]=//主菜单
{
    "＊      仿射密码     ＊",
    "＊      置换密码     ＊",
    "＊      凯撒加密     ＊",
    "＊    维吉尼亚密码   ＊",
    "＊      数学运算     ＊",
    "＊        退出       ＊",
};


CONSOLE_CURSOR_INFO cci;//定义结构体
COORD pos={0,0};//重置坐标


void showmenu(HANDLE hOut,const char **menu,int size,int index)//主菜单
{
    int i;
    system("cls");//调用控制台
    SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_INTENSITY);//设置颜色
    pos.X=45;
    pos.Y=0;
    SetConsoleCursorPosition(hOut,pos);//设置光标位置
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
    fflush(stdout);//刷新标准输出缓冲区
}

int  get_userinput(int *index,int size)//获取输入上下左右确定退出
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

int choose_ed(HANDLE hOut,int flag)//次级菜单
{
    int index=0,ret,i;
    const char *menu1[]={"＊    加密    ＊",
    "＊    解密    ＊",
    "＊    返回    ＊"} ;
    const char *menu2[]={"＊    继续    ＊",
    "＊    返回    ＊"} ;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE |FOREGROUND_RED |FOREGROUND_INTENSITY);
    pos.X=40;
    pos.Y=2;
    SetConsoleCursorPosition(hOut,pos);
    if(flag)
    {
        cout<<"请选择加密或解密" ;
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
                    case 2:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0;//退出
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
                    case 1:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0;//退出
                }
            }
        }
    }
}

int menu_x(HANDLE hOut)//数学运算的次级菜单
{
    system("cls");
    int index=0,ret,i;
    const char *menu[]={"＊       立体几何       ＊",
    "＊    公约数与公倍数    ＊",
    "＊         阶乘         ＊",
    "＊       水仙花数       ＊",
    "＊        同构数        ＊",
    "＊         返回         ＊"} ;
    SetConsoleTitleA(TITLE1);
    while(1)
    {
        system("cls");
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE |FOREGROUND_RED |FOREGROUND_INTENSITY);
        pos.X=46;
        pos.Y=1;
        SetConsoleCursorPosition(hOut,pos);
        cout<<"请选择运算" ;
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
                    case 5:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0 ;//退出
                }
            }
    }
    fflush(stdout);
}


int main()
{
    int index=0,ret,rt;
    HANDLE hOut;
    SetConsoleTitleA(TITLE);//设置控制台标题
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);//设置为标准输出句柄
    GetConsoleCursorInfo(hOut,&cci);//获取光标信息
    cci.dwSize=1;//设置光标大小
    cci.bVisible=0;//设置光标不可见
    SetConsoleCursorInfo(hOut,&cci);//应用设置
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
                case 5:SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);return 0;//退出
            }
        }
        fflush(stdout);
    }
    return 0;
}
