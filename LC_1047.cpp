#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> a;
        string res="";
        for(auto ch:S)
        {
            if(a.empty()||a.top()!=ch)
            {
                a.push(ch);
            }
            else
            {
                a.pop();
            }
        }
        while(!a.empty())
        {
            res=a.top()+res;
            a.pop();
        }
         return res;
    }
};
int main()
{
    string s="abbbabaaa";
    Solution sol;
    string res=sol.removeDuplicates(s);
    cout<<res<<endl;
    return 0;
}