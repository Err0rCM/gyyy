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
            SetConsoleTitleA("��������");
            cout<<"����������һ����������Ϊ��֪�ļ��ܼ���������һ���滻���ܵļ����������е�������ĸ������ĸ������󣨻���ǰ������һ���̶���Ŀ����ƫ�ƺ��滻�����ġ�";
        }

        void en()
        {
            system("cls");
            char Inform[1000],str[1000];
            cout<<"����������ַ���:";
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
                cout<<"ƫ����Ϊ"<<numB<<"ʱ������Ϊ:" <<str<<endl;
            }
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }

        void de()
        {
            system("cls");
            char Inform[1000],str[1000];
            cout<<"����������ַ���:";
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
                cout<<"ƫ����Ϊ"<<numB<<"ʱ������Ϊ:" << str << endl;
            }
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }

};
#endif // CAESAR_CRYPTO_H
