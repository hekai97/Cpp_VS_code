#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int res=0;
        int count=0;
        int n=s.size();
        bool barrel[200]={false};
        for(int i=0;i<n;i++)
        {
            // barrel[s[i]-97]=true;
            // count+=1;
            for(int j=i;j<n;j++)
            {
                if(barrel[s[j]]==false)
                {
                    barrel[s[j]]=true;
                    count++;
                }
                else
                {
                    memset(barrel,false,sizeof(barrel));
                    res=max(res,count);
                    count=0;
                    break;
                }
            }
        }
        return res==0?1:res;
    }
};
int main()
{
    string s=" ";
    Solution sol;
    cout<<sol.lengthOfLongestSubstring(s);
    return 0;
}