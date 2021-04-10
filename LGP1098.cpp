#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string Unfold(string s,int p1,int p2,int p3)
    {
        string res="";
        for(int i=0;i<s.size();++i)
        {
            if(i==0&&s[i]=='-')
            {
                res+='-';
            }
            else if(s[i]!='-')
            {
                res+=s[i];
            }
            else
            {
                char pre=s[i-1];
                char next=s[i+1];
                if((isdigit(pre)&&isdigit(next)))
                {
                    if(pre+1==next)
                    {
                        continue;
                    }
                    else if(pre>=next)
                    {
                        res+='-';
                    }
                    else
                    {
                        string temp="";
                        for(char c=pre+1;c<next;++c)
                        {
                            for(int t=0;t<p2;++t)
                            {
                                if(p1==1||p1==2)
                                {
                                    temp+=c;
                                }
                                else
                                {
                                    temp+='*';
                                }
                            }
                        }
                        if(p3==1)
                        {
                            res+=temp;
                        }
                        else
                        {
                            reverse(temp.begin(),temp.end());
                            res+=temp;
                        }
                    }
                }
                else if(isalpha(pre)&&isalpha(next))
                {
                    if(pre+1==next)
                    {
                        continue;
                    }
                    else if(pre>=next)
                    {
                        res+='-';
                    }
                    else
                    {
                        string temp="";
                        for(char c=pre+1;c<next;++c)
                        {
                            for(int t=0;t<p2;++t)
                            {
                                if(p1==1)
                                {
                                    temp+=c;
                                }
                                else if(p1==2)
                                {
                                    temp+=toupper(c);
                                }
                                else
                                {
                                    temp+='*';
                                }
                            }
                        }
                        if(p3==1)
                        {
                            res+=temp;
                        }
                        else
                        {
                            reverse(temp.begin(),temp.end());
                            res+=temp;
                        }
                    }
                }
                else
                {
                    res+='-';
                }
            }
        }
        return res;
    }
};
int main()
{
    int p1,p2,p3;
    string s;
    cin>>p1>>p2>>p3;
    cin>>s;
    Solution sol;
    cout<<sol.Unfold(s,p1,p2,p3);
    return 0;
}