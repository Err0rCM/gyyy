#ifndef AFFINE_CRYPTO_H
#define AFFINE_CRYPTO_H

#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

class  affine{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("��������");
            cout<<"��������Ϊ������ܵ�һ�֣���ĸϵͳ��������ĸ����һ����ѧ���̼��ܣ���Ӧ����ֵ����ת����ĸ��";
        }

        void en()
        {
            system("cls");
            char text[10000];
            char result[10000];
			int k1;int k2;
            cout<<"��������Ҫ�����ַ���:";
            cin>>text;
            cout<<"����key1:";
            cin>>k1;
            cout<<"����key2:";
            cin>>k2;
			int i,z=0;
    		int l = strlen(text); //��ȡ���ĵĳ���
    		for(i=0;i<l;i++)
    		{
 
        		if (text[i] >= 'A' && text[i] <= 'Z')
				{
          	  		result[z]=(k1*(text[i]-'A')+k2)%26+'A';
        		} 
				else if (text[i] >= 'a' && text[i] <= 'z')
				{
            		result[z]=(k1*(text[i]-'a')+k2)%26+'a';
        		} 
				else{  //�ж��Ƿ��ǿո�
            	result[z] = text[i];
       			 }
        		z++;
   			}
            cout << "���ܺ�����:" << result<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }

        void de()
        {
            system("cls");
            char text[10000];
            char result[10000];
			int k3;int k2;
 			cout<<"��������Ҫ�����ַ���:";
            cin>>text;
            cout<<"������Կkey1����Ԫ:";
            cin>>k3;
            cout<<"������Կkey2:";
            cin>>k2;
            cout<<"����Ϊ:"<<endl;
			int i,z=0;
    		int l = strlen(text); //��ȡ���ĵĳ���
    		for(i=0;i<l;i++)
   			{
        		if (text[i] >= 'A' && text[i] <= 'Z')
				{
            		result[z]=(k3*((text[i]-'A')-k2))%26+'A';
            		if(k3*((text[i]-'A')-k2) < 0)
					{
               		   result[z] = result[z] + 26;
           		 	}
       		 	} 
				else if (text[i] >= 'a' && text[i] <= 'z')
				{
            		result[z]=(k3*((text[i]-'a')-k2))%26+'a';
            		if(k3*((text[i]-'a')-k2) < 0)
					{ 
               		 	result[z] = result[z] + 26;
            		}
        		} else
					{  
            			result[z] = text[i];
       				 }
        			z++;
    		}
    		cout << "���ܺ�����:" << result<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }
};
#endif // AFFINE_CRYPTO_H
