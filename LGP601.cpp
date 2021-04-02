#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string Add(string s1,string s2){
        string res;
        int index=0;
        char base='0';
        while(!s1.empty()&&!s2.empty())
        {
            int t1=s1.back()-base;
            int t2=s2.back()-base;
            int temp=t1+t2+index;
            index=0;
            s1.pop_back();
            s2.pop_back();
            if(temp>=10)
            {
                temp%=10;
                index=1;
            }
            res.insert(res.begin(),temp+base);
        }
        if(s1.empty()&&!s2.empty())
        {
            while(!s2.empty()){
                int temp=s2.back()-base+index;
                if(temp>=10){
                    temp%=10;
                    index=1;
                }
                else
                {
                    index=0;
                }
                res.insert(res.begin(),temp+base);
                s2.pop_back();
            }
            if(s2.empty()&&index==1){
                res.insert(res.begin(),index+base);
            }
        }
        else if(s2.empty()&&!s1.empty())
        {
            while(!s1.empty()){
                int temp=s1.back()-base+index;
                if(temp>=10){
                    temp%=10;
                    index=1;
                }
                else
                {
                    index=0;
                }
                res.insert(res.begin(),temp+base);
                s1.pop_back();
            }
            if(s1.empty()&&index==1){
                res.insert(res.begin(),index+base);
            }
        }
        else
        {
            if(index!=0)
            res.insert(res.begin(),index+base);
        }
        return res;
    }
};
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.Add(s1,s2);
    return 0;
}