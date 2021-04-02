#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==t.size()&&s!=t)
        {
            return false;
        }
        int index=0;
        for(int i=0;i<s.size();++i)
        {
            if(index==t.size())
            {
                return false;
            }
            int j;
            for(j=index;j<t.size();++j)
            {
                if(s[i]==t[j])
                {
                    index=j+1;
                    break;
                }
            }
            if(j==t.size()&&i!=s.size()-1)
            {
                index=j;
            }
            else if(j==t.size()&&i==s.size()-1)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string s="abc";
    string t="ahbgdc";
    Solution sol;
    cout<<sol.isSubsequence(s,t);
}