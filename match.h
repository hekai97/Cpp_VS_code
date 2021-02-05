#include<iostream>
#include<vector>
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;
//生成串
void StrAssign(SqString &s,char cstr[])
{
	int i;
	for(i=0;cstr[i]!='\0';i++)
	{
		s.data[i]=cstr[i];
	}
	s.length=i;
}
//BF算法
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
//求next数组值
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
//获得nextval
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


//KMP算法
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
//改进的KMP算法
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
//BF得到一个结果
void BFres(SqString s,SqString t)
{
	int res=BF(s,t);
	std::cout<<"用BF算出的值为："<<res<<std::endl;
}
void KMPres(SqString s,SqString t)
{
	int res=KMP(s,t);
	std::cout<<"用KMP算法算出的值为："<<res<<std::endl;
}
void KMPIndexres(SqString s,SqString t)
{
	int res=KMPIndex(s,t);
	std::cout<<"用改进后的KMP算法算出的值为："<<res<<std::endl;
}
void PrintArray(SqString t)
{
	int next[MaxSize];
	int nextval[MaxSize];
	GetNext(t,next);
	std::cout<<"next数组的值为：";
	for(int i=0;i<t.length;i++)
	{
		std::cout<<next[i]<<" ";
	}
	std::cout<<std::endl;
	GetNextval(t,nextval);
	std::cout<<"nextval数组的值为：";
	for(int i=0;i<t.length;i++)
	{
		std::cout<<nextval[i]<<" ";
	}
	std::cout<<std::endl;
}