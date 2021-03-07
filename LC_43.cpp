#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int L1=num1.size(),L2=num2.size();
        int index=0;
        vector<string> tempRes(L2,"");
        for(int i=L2-1;i>=0;--i)
        {
            for(int k=0;k<L2-1-i;++k)
            {
                tempRes[i].push_back('0');
            }
            for(int j=L1-1;j>=0;--j)
            {
                int temp=(int)(num2[i]-48)*(int)(num1[j]-48)+index;
                int divisor=temp/10;
                int remainder=temp%10;
                index=divisor;
                tempRes[i].insert(tempRes[i].begin(),remainder+48);
            }
            tempRes[i].insert(tempRes[i].begin(),index+48);
            index=0;
        }
        string res="";
        index=0;
        while(!tempRes.empty())
        {
            int temp=0;
            for(int i=0;i<tempRes.size();++i)
            {
                if(!tempRes[i].empty())
                {
                    temp+=(int)(tempRes[i][tempRes[i].size()-1]-48);
                    tempRes[i].pop_back();
                }
                else
                {
                    tempRes.pop_back();
                }
            }
            temp+=index;
            int divisor=temp/10;
            int remainder=temp%10;
            index=divisor;
            res.insert(res.begin(),remainder+48);
        }
        while(!res.empty())
        {
            if(res[0]=='0'&&res.size()!=1)
            {
                res.erase(res.begin(),res.begin()+1);
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
int main()
{
    string num1="9",num2="99";
    Solution s;
    cout<<s.multiply(num1,num2);
    return 0;
}