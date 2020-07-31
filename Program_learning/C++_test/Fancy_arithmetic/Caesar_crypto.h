#ifndef CAESAR_CRYPTO_H
#define CAESAR_CRYPTO_H

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class caesar{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("凯撒密码");
            cout<<"凯撒密码是一种最简单且最广为人知的加密技术。它是一种替换加密的技术，明文中的所有字母都在字母表上向后（或向前）按照一个固定数目进行偏移后被替换成密文。";
        }

        void en()
        {
            system("cls");
            char Inform[1000],str[1000];
            cout<<"请输入加密字符串:";
            cin>>Inform;
            int numB,i;
            for(numB=0;numB<26;numB++)
            {
                for(i=0;i<strlen(Inform);i++)
                {
                    if(Inform[i]>='A'&&Inform[i]<='Z')
                    {
                        str[i]=((Inform[i]-'A')+numB)%26+'A';
                    }
                    else if(Inform[i]>='a'&&Inform[i]<='z')
                    {
                        str[i]=((Inform[i]-'a')+numB)%26+'a';
                    }
                }
                cout<<"偏移量为"<<numB<<"时的密文为:" <<str<<endl;
            }
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }

        void de()
        {
            system("cls");
            char Inform[1000],str[1000];
            cout<<"请输入解密字符串:";
            cin>>Inform;
            int numB,num,i;
            for(numB=0;numB<26;numB++)
            {
                num=26-numB;
                for(i=0;i<strlen(Inform);i++)
                {
                    if(Inform[i]>='A' &&Inform[i]<='Z')
                    {
                        str[i]=((Inform[i]-'A')+numB)%26+'A';
                    }
                    else if(Inform[i]>='a'&&Inform[i]<='z')
                    {
                        str[i]=((Inform[i]-'a')+numB)%26+'a';
                    }
                }
                cout<<"偏移量为"<<numB<<"时的密文为:" << str << endl;
            }
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }

};
#endif // CAESAR_CRYPTO_H
