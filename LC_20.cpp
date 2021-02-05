#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')'||s[0]==']'||s[0]=='}'||s.size()%2!=0)
        {
            return false;
        }
        stack<char> stc;
        for(int i=0;i!=s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                stc.push(s[i]);
            }
            if(!stc.empty())
            {
                if(s[i]==')')
                {
                    if(stc.top()=='(')
                    {
                        stc.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if(s[i]==']')
                {
                    if(stc.top()=='[')
                    {
                        stc.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if(s[i]=='}')
                {
                    if(stc.top()=='{')
                    {
                        stc.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            } 
            else
            {
                return false;
            }
            
        }
        if(stc.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    string s="()))";
    Solution a;
    bool res=a.isValid(s);
    cout<<res<<endl;
    return 0;
}
