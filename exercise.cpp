#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string MinStr(string s,int n)
    {
        int m=s.size();
        while(n--)
        {
            for(int i=0;i<m-1;++i)
            {
                if(s[i]>s[i+1])
                {
                    s.erase(i,1);
                    break;
                }
            }
        }
        return s;
    }
};
int main()
{
    string s;
    int n;
    cin>>s>>n;
    Solution sol;
    cout<<sol.MinStr(s,n);
    return 0;
}