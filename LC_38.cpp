#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string num=countAndSay(n-1),ans;
        int count=1;
        for(int i=0;i<num.size();++i)
        {
            if(num[i]!=num[i+1])
            {
                ans+=(count+'0');
                ans+=num[i];
                count=0;
            }
            count++;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.countAndSay(n);
    return 0;
}