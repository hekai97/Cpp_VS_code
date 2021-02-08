#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> numbers;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int res;
                int n2 = numbers.top();
                numbers.pop();
                int n1 = numbers.top();
                numbers.pop();
                if(tokens[i]=="+")
                   res=n1+n2;
                else if(tokens[i]=="-")
                   res=n1-n2;
                else if(tokens[i]=="/")
                   res=n1/n2;
                else
                   res=n1*n2;
                numbers.push(res);
            }else{
                numbers.push(stoi(tokens[i]));
            } 
        }
        return numbers.top();
    }
 };
 int main()
 {
     vector<string> tokens={"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
     Solution s;
     cout<<s.evalRPN(tokens);
     return 0;
 }