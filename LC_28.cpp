#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
        {
            return 0;
        }
        return KMPIndex(haystack,needle);
    }
    void GetNextval(string t,vector<int>& nextval){
        int j=0,k=-1;
        nextval[0]=-1;
        while(j<t.size()-1)
        {
            if(k==-1||t[j]==t[k])
            {
                j++;
                k++;
                if(t[j]!=t[k])
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
    int KMPIndex(string s,string t)
    {
        int i=0,j=0;
        vector<int> nextval(t.size()+1,0);
        GetNextval(t,nextval);
        int n=s.size(),m=t.size();
        while(i<n&&j<m)
        {
            if(j==-1||s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j=nextval[j];
            }
        }
        if(j>=t.size())
            return i-t.size();
        else
            return -1;
    }
};
int main()
{
    string s="hello",t="ll";
    Solution sol;
    cout<<sol.strStr(s,t);
    return 0;
}

