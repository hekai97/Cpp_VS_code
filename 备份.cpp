#include <iostream>
#include <cmath>
using namespace std;
class TABLE
{
public:
    double T;
    double Y;
};
double f(double k,double t) 
{
    double x=0.202*exp(-k*t);
    return x;
}
double F(double k,double y,double t)
{
    double x=pow(y-f(k,t),2);
	return x;
}
int main()
{
    TABLE table[100];
    int num;            //表格的列数
    double a,b,d1,d2,c;
    c=0.0001;
    double sum1=0,sum2=0;
    cin>>a>>b;          //输入区间端点
    cin>>num;           //输入表格列数
    for(int i=1;i<=num;i++)
    {
        cin>>table[i].T>>table[i].Y;//输入每一列的T，Y值
    }
    d1=a+(1-0.618)*(b-a);
    d2=b-(1-0.618)*(b-a);
    while((b-a)>=c)
    {
        for(int i=1;i<=num;i++)
        {
            sum1+=F(d1,table[i].Y,table[i].T);
            sum2+=F(d2,table[i].Y,table[i].T);
        }
        if(sum1>sum2)
        {
            a=d1;
            b=d2;
            d1=a+(1-0.618)*(b-a);
        }
        else
        {
            b=d2;
            a=d1;
            d2=b-(1-0.618)*(b-a);
        }
        sum1=0;
        sum2=0;
    }
    cout<<"最优解:"<<(a+b)/2<<endl;
    getchar();
    getchar();
    return 0;
}