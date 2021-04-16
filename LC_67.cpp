#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        string res;
        int index=0;
        if(n>m)
        {
            for(int i=0;i<n-m;++i)
            {
                b.insert(b.begin(),'0');
            }
        }
        else
        {
            for(int i=0;i<m-n;++i)
            {
                a.insert(a.begin(),'0');
            }
        }
        while(!a.empty()&&!b.empty())
        {
            if(index==0)
            {
                if(a.back()==b.back())
                {
                    if(a.back()=='1')
                    {
                        res.insert(res.begin(),'0');
                        index=1;
                    }
                    else
                    {
                        res.insert(res.begin(),'0');
                    }
                }
                else
                {
                    res.insert(res.begin(),'1');
                }
            }
            else
            {
                if(a.back()==b.back())
                {
                    if(a.back()=='1')
                    {
                        res.insert(res.begin(),'1');
                        index=1;
                    }
                    else
                    {
                        res.insert(res.begin(),'1');
                        index=0;
                    }
                }
                else
                {
                    res.insert(res.begin(),'0');
                    index=1;
                }
            }
            a.pop_back();
            b.pop_back();
        }
        if(index==1)
        {
            res.insert(res.begin(),'1');
        }
        else
        {
            int length=res.size();
            for(int i=0;i<length;++i)
            {
                if(res[i]==0)
                {
                    continue;
                }
                else
                {
                    res=res.substr(i,length);
                    return res;
                }
            }
        }
        return res;
    }
};
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.addBinary(s1,s2);
    return 0;
}