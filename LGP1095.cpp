#include<bits/stdc++.h>
using namespace std;
int count=0;
class Solution
{
public:
    bool canleave(int m,int s,int t,int& res,int& time){
        res=0,time=1;
        int s2=0;
        for(;time<=t;time++){
            res+=17;
            if(m>=10){
                s2+=60;
                m-=10;
            }
            else
            {
                m+=4;
            }
            if(s2>res)res=s2;
            if(res>s){
                return true;
            }
        }
        return false;
    }
};
int main()
{
    int m,s,t;
    int res=0,time=0;
    cin>>m>>s>>t;
    Solution sol;
    if(sol.canleave(m,s,t,res,time))
    {
        cout<<"Yes"<<endl<<time;
    }
    else
    {
        cout<<"No"<<endl<<res<<endl;
    }
    return 0;
}