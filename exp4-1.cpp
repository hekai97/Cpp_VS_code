#include<iostream>
#include"match.h"
using namespace std;
int main(){
	/*SqString s,t;
	char ch1[]="abcabcdabcdeabcdefabcdefg";
	char ch2[]="abcdeabcdefab";
	StrAssign(s,ch1);
	StrAssign(t,ch2);
	BFres(s,t);
	PrintArray(t);
	KMPres(s,t);
	KMPIndexres(s,t);
	getchar();*/
	int next[MaxSize];
	SqString s;
	s.data[0]='b';
	s.data[1]='a';
	s.data[2]='b';
	s.data[3]='a';
	s.data[4]='b';
	s.length=5;
	GetNext(s,next);
	for(int i=0;i<5;i++)
	{
		cout<<next[i]<<" ";
	}
	cout<<endl;
	int nextval[MaxSize];
	GetNextval(s,nextval);
	for(int i=0;i<5;i++)
	{
		cout<<nextval[i]<<" ";
	}
	return 0;
}