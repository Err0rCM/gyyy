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
            SetConsoleTitleA("ά����������");
            cout<<"ά���������루����ά���ɶ����룩��ʹ��һϵ�п����������������ĸ��ļ����㷨�����ڶ�������һ�ּ���ʽ��";
        }

        void en()
        {
        	system("cls");
            char text[1000]="";
            cout<<"��������Ҫ�����ַ���:";
            cin>>text;
    		char result[1000]="";
    		char k[1000]="";
    		cout<<"��������Կ";
    		cin>>k;
    		int i=0,j=0,z=0;
    		int m = strlen(k); //��ȡ��Կ�ĳ���
    		int l = strlen(text); //��ȡ���ĵĳ���
    		for(i=0;i<l;i++)
   			 {
        		if (text[i] >= 'A' && text[i] <= 'Z')
				{
            		if(j==m)
					{
               	    	j=0;   //ѭ����Կ
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
                	j=0;   //ѭ����Կ
               		result[z]=(text[i]-'a'+k[j]-'a')%26+'a';
            	} 
				else 
					{
                	result[z]=(text[i]-'a'+k[j]-'a')%26+'a';
            		}
            		j++;
       		} 
			  	else{  //�ж��Ƿ��ǿո�
            	result[z] = text[i];
        			}
        			z++;
   			 }
            cout<<"����:"<<result<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }

        void de()
        {
            system("cls");
            char text[1000]="";
            cout<<"��������Ҫ�����ַ���:";
            cin>>text;
    		char result[1000]="";
    		char k[1000]="";
    		cout<<"��������Կ";
    		cin>>k;
    		    int i,j=0,z=0;
    int m = strlen(k); //��ȡ��Կ�ĳ���
    int l = strlen(text); //��ȡ���ĵĳ���
    for(i=0;i<l;i++)
    {
        //�ж��Ƿ��ǿո�
        if (text[i] >= 'A' && text[i] <= 'Z'){
            if(j==m){
                j=0;   //ѭ����Կ
                result[z]=(text[i]-k[j]+26)%26+'A';
            } else {
                result[z]=(text[i]-k[j]+26)%26+'A';
            }
            j++;
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            if(j==m){
                j=0;   //ѭ����Կ
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
            cout<<"����Ϊ:"<<result<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }
};
#endif // VIRGINIA_CRYPTO_H
