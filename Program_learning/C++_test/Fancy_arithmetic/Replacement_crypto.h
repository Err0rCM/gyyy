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
            SetConsoleTitleA("�û�����");
            cout<<"�û��������һ�����ڵļ��ܷ����������ĵ���ĸ������ͬ��������˳�򱻴����ˡ�";
        }

        void en()
        {
            system("cls");
            char m[999999],c[999999];
    		int x[26];
    		int t,k,len,a=0,i,j;
    		cout<<"����������:" ;
    		cin>>m;
			len=strlen(m);
    		cout<<endl<<"��������Կ����:" ;
    		cin>>k;
    		t=k-len%k; //��ȫ�ո�λ��
    		cout<<endl<<"��������Կ˳��,�Կո�ֿ�:"; 
    		re:for(i=0; i<k; i++)
    	    cin>>x[i];
    		for(i=0;i<k;i++)
    			for(j=i+1;j<k;j++)
    				if(x[i]==x[j]||x[i]>k)
    				{
    					cout<<"������������������:";
    					goto re;
					}
    		for(j=0; j<(len+t)/k; j++) /* ���� --> ����j<3 ��0,1,2���� */
    		    for(i=0; i<k; i++)
    		    	c[a++]=m[x[i]+k*j-1];
            /*
            m������������ַ���
            x[i]���������Կ��ʽ
            m[x[i]]������Կ��ʽ��Ϊm�ַ���������λ��
            */
            //printf("%d\n",x[i]+k*j);
            cout<<"����Ϊ:"; 
    		for(i=0;i<=len+t;i++)
    			if(c[i]!=' ')
					cout<<c[i];
			cout<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }

        void de()
        {
			system("cls");
            char m[10000],c[10000];
    		int x[26];
    		int t,k,len,a=0,i,j;
    		cout<<"����������:" ;
    		cin>>m;
			len=strlen(m);
    		cout<<endl<<"��������Կ����:" ;
    		cin>>k;
    		t=k-len%k; //��ȫ�ո�λ��
    		cout<<endl<<"��������Կ˳��,�Կո�ֿ�:"; 
    		re:for(i=0; i<k; i++)
    	    cin>>x[i];
    		for(i=0;i<k;i++)
    			for(j=i+1;j<k;j++)
    				if(x[i]==x[j]||x[i]>k)
    				{
    					cout<<"������������������:";
    					goto re;
					}
    		for(j=0; j<(len+t)/k; j++)
    		    for(i=0; i<k; i++)
    		    	c[a++]=m[x[i]+k*j-1];
    		cout<<"����Ϊ:"; 
    		for(i=0;i<=len+t;i++)
    			if(c[i]!=' ')
					cout<<c[i];
			cout<<endl;
            cout<<"<-----------------����������----------------->"<<endl;
            system("pause");
        }
};
#endif
