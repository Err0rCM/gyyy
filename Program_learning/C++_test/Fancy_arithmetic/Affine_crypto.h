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
            SetConsoleTitleA("仿射密码");
            cout<<"仿射密码为单表加密的一种，字母系统中所有字母都藉一简单数学方程加密，对应至数值，或转回字母。";
        }

        void en()
        {
            system("cls");
            char text[10000];
            char result[10000];
			int k1;int k2;
            cout<<"请输入需要加密字符串:";
            cin>>text;
            cout<<"输入key1:";
            cin>>k1;
            cout<<"输入key2:";
            cin>>k2;
			int i,z=0;
    		int l = strlen(text); //获取明文的长度
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
				else{  //判断是否是空格
            	result[z] = text[i];
       			 }
        		z++;
   			}
            cout << "加密后密文:" << result<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }

        void de()
        {
            system("cls");
            char text[10000];
            char result[10000];
			int k3;int k2;
 			cout<<"请输入需要解密字符串:";
            cin>>text;
            cout<<"输入密钥key1的逆元:";
            cin>>k3;
            cout<<"输入密钥key2:";
            cin>>k2;
            cout<<"解密为:"<<endl;
			int i,z=0;
    		int l = strlen(text); //获取明文的长度
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
    		cout << "解密后明文:" << result<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }
};
#endif // AFFINE_CRYPTO_H
