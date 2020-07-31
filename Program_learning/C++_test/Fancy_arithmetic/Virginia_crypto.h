#ifndef VIRGINIA_CRYPTO_H
#define VIRGINIA_CRYPTO_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <Windows.h>

using namespace std;

class virginia{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("维吉尼亚密码");
            cout<<"维吉尼亚密码（又译维热纳尔密码）是使用一系列凯撒密码组成密码字母表的加密算法，属于多表密码的一种简单形式。";
        }

        void en()
        {
        	system("cls");
            char text[1000]="";
            cout<<"请输入需要加密字符串:";
            cin>>text;
    		char result[1000]="";
    		char k[1000]="";
    		cout<<"请输入密钥";
    		cin>>k;
    		int i=0,j=0,z=0;
    		int m = strlen(k); //获取密钥的长度
    		int l = strlen(text); //获取明文的长度
    		for(i=0;i<l;i++)
   			 {
        		if (text[i] >= 'A' && text[i] <= 'Z')
				{
            		if(j==m)
					{
               	    	j=0;   //循环密钥
                		result[z]=(text[i]-'A'+k[j]-'A')%26+'A';
            		} 
					else 
					{
                		result[z]=(text[i]-'A'+k[j]-'A')%26+'A';
            		}
            			j++;
        		} 
			else if (text[i] >= 'a' && text[i] <= 'z')
			{
            	if(j==m)
				{
                	j=0;   //循环密钥
               		result[z]=(text[i]-'a'+k[j]-'a')%26+'a';
            	} 
				else 
					{
                	result[z]=(text[i]-'a'+k[j]-'a')%26+'a';
            		}
            		j++;
       		} 
			  	else{  //判断是否是空格
            	result[z] = text[i];
        			}
        			z++;
   			 }
            cout<<"密文:"<<result<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }

        void de()
        {
            system("cls");
            char text[1000]="";
            cout<<"请输入需要解密字符串:";
            cin>>text;
    		char result[1000]="";
    		char k[1000]="";
    		cout<<"请输入密钥";
    		cin>>k;
    		    int i,j=0,z=0;
    int m = strlen(k); //获取密钥的长度
    int l = strlen(text); //获取密文的长度
    for(i=0;i<l;i++)
    {
        //判断是否是空格
        if (text[i] >= 'A' && text[i] <= 'Z'){
            if(j==m){
                j=0;   //循环密钥
                result[z]=(text[i]-k[j]+26)%26+'A';
            } else {
                result[z]=(text[i]-k[j]+26)%26+'A';
            }
            j++;
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            if(j==m){
                j=0;   //循环密钥
                result[z]=(text[i]-k[j]+26)%26+'a';
            } else {
                result[z]=(text[i]-k[j]+26)%26+'a';
            }
            j++;
        } else{
            result[z] = text[i];
        }
        z++;
    }
            cout<<"解密为:"<<result<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }
};
#endif // VIRGINIA_CRYPTO_H
