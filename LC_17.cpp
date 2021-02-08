#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return {};
        }
        vector<string> res;
        string temp;
        unordered_map<char,string> phone{
            {'2',"abc"},
            {'3',"def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtracking(phone,digits,res,temp,0);
        return res;
    }
private:
    void backtracking(const unordered_map<char,string>& phone,string digits,vector<string>& res,string temp,int count)
    {
        if(count==digits.size())
        {
            res.push_back(temp);
            return;
        }
        char num=digits[count];
        auto& letters=phone.at(num);
        for(auto& ch:letters)
        {
            temp.push_back(ch);
            backtracking(phone,digits,res,temp,count+1);
            temp.pop_back();
        }
    }
};
int main()
{
    string s="23";
    Solution sol;
    vector<string> res=sol.letterCombinations(s);
    for(auto temp:res)
    {
        cout<<temp<<endl;
    }
    return 0;
}