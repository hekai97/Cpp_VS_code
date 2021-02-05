#include<iostream>
#include<vector>
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;
//���ɴ�
void StrAssign(SqString &s,char cstr[])
{
	int i;
	for(i=0;cstr[i]!='\0';i++)
	{
		s.data[i]=cstr[i];
	}
	s.length=i;
}
//BF�㷨
int BF(SqString s,SqString t)
{
	int i=0,j=0;
	while(i<s.length&&j<t.length)
	{
		if(s.data[i]==t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=t.length)
		return i-t.length;
	else
		return -1;
}
//��next����ֵ
void GetNext(SqString t,int next[])
{
	int j,k;
	j=0;
	k=-1;
	next[0]=-1;
	while(j<t.length-1)
	{
		if(k==-1||t.data[j]==t.data[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
		{
			k=next[k];
		}
	}
}
//���nextval
void GetNextval(SqString t,int nextval[])
{
	int j=0,k=-1;
	nextval[0]=-1;
	while(j<t.length)
	{
		if(k==-1||t.data[j]==t.data[k])
		{
			j++;
			k++;
			if(t.data[j]!=t.data[k])
			{
				nextval[j]=k;
			}
			else
			{
				nextval[j]=nextval[k];
			}
		}
		else
		{
			k=nextval[k];
		}
	}
}


//KMP�㷨
int KMP(SqString s,SqString t)
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while(i<s.length&&j<t.length)
	{
		if(j==-1||s.data[i]==t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j>=t.length)
		return i-t.length;
	else
		return -1;
}
//�Ľ���KMP�㷨
int KMPIndex(SqString s,SqString t)
{
	int nextval[MaxSize],i=0,j=0;
	GetNextval(t,nextval);
	while(i<s.length&&j<t.length)
	{
		if(j==-1||s.data[i]==t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j=nextval[j];
		}
	}
	if(j>=t.length)
		return i-t.length;
	else
		return -1;
}
//BF�õ�һ�����
void BFres(SqString s,SqString t)
{
	int res=BF(s,t);
	std::cout<<"��BF�����ֵΪ��"<<res<<std::endl;
}
void KMPres(SqString s,SqString t)
{
	int res=KMP(s,t);
	std::cout<<"��KMP�㷨�����ֵΪ��"<<res<<std::endl;
}
void KMPIndexres(SqString s,SqString t)
{
	int res=KMPIndex(s,t);
	std::cout<<"�øĽ����KMP�㷨�����ֵΪ��"<<res<<std::endl;
}
void PrintArray(SqString t)
{
	int next[MaxSize];
	int nextval[MaxSize];
	GetNext(t,next);
	std::cout<<"next�����ֵΪ��";
	for(int i=0;i<t.length;i++)
	{
		std::cout<<next[i]<<" ";
	}
	std::cout<<std::endl;
	GetNextval(t,nextval);
	std::cout<<"nextval�����ֵΪ��";
	for(int i=0;i<t.length;i++)
	{
		std::cout<<nextval[i]<<" ";
	}
	std::cout<<std::endl;
}