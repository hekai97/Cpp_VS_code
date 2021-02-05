#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> b;
        string a;
        for(auto i=0;i<S.size()-1;i++)
        {
            if(S[i]=='(')
            {
                if(!b.empty())
                {
                    a+="(";
                }
                b.push(S[i]);
            }
            if(S[i]==')')
            {
                b.pop();
                if(!b.empty())
                {
                    a+=")";
                }
            }
        }
        return a;
    }
};
int main()
{
    Solution a;
    string s="(()())(())(()(()))";
    string c=a.removeOuterParentheses(s);
    cout<<c<<endl;
    return 0;
}