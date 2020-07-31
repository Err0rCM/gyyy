#ifndef Replacement_password_h
#define Replacement_password_h

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <Windows.h>

using namespace std;

class replacement{
    public:
        void show_information()
        {
            system("cls");
            SetConsoleTitleA("置换密码");
            cout<<"置换密码就是一种早期的加密方法，与明文的字母保持相同，区别是顺序被打乱了。";
        }

        void en()
        {
            system("cls");
            char m[999999],c[999999];
    		int x[26];
    		int t,k,len,a=0,i,j;
    		cout<<"请输入明文:" ;
    		cin>>m;
			len=strlen(m);
    		cout<<endl<<"请输入密钥长度:" ;
    		cin>>k;
    		t=k-len%k; //补全空格位数
    		cout<<endl<<"请输入密钥顺序,以空格分开:"; 
    		re:for(i=0; i<k; i++)
    	    cin>>x[i];
    		for(i=0;i<k;i++)
    			for(j=i+1;j<k;j++)
    				if(x[i]==x[j]||x[i]>k)
    				{
    					cout<<"输入有误！请重新输入:";
    					goto re;
					}
    		for(j=0; j<(len+t)/k; j++) /* 分组 --> 这里j<3 有0,1,2三组 */
    		    for(i=0; i<k; i++)
    		    	c[a++]=m[x[i]+k*j-1];
            /*
            m是输入的明文字符串
            x[i]是输入的密钥方式
            m[x[i]]即把密钥方式作为m字符串的数组位置
            */
            //printf("%d\n",x[i]+k*j);
            cout<<"密文为:"; 
    		for(i=0;i<=len+t;i++)
    			if(c[i]!=' ')
					cout<<c[i];
			cout<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }

        void de()
        {
			system("cls");
            char m[10000],c[10000];
    		int x[26];
    		int t,k,len,a=0,i,j;
    		cout<<"请输入密文:" ;
    		cin>>m;
			len=strlen(m);
    		cout<<endl<<"请输入密钥长度:" ;
    		cin>>k;
    		t=k-len%k; //补全空格位数
    		cout<<endl<<"请输入密钥顺序,以空格分开:"; 
    		re:for(i=0; i<k; i++)
    	    cin>>x[i];
    		for(i=0;i<k;i++)
    			for(j=i+1;j<k;j++)
    				if(x[i]==x[j]||x[i]>k)
    				{
    					cout<<"输入有误！请重新输入:";
    					goto re;
					}
    		for(j=0; j<(len+t)/k; j++)
    		    for(i=0; i<k; i++)
    		    	c[a++]=m[x[i]+k*j-1];
    		cout<<"明文为:"; 
    		for(i=0;i<=len+t;i++)
    			if(c[i]!=' ')
					cout<<c[i];
			cout<<endl;
            cout<<"<-----------------就是这样啦----------------->"<<endl;
            system("pause");
        }
};
#endif
