#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0||isempty(strs)){
            return "";
        }
        string res="";
        int index=0;
        char temp;
        bool tempres=true;
        while(tempres&&index<strs[0].size())
        {
            temp=strs[0][index];
            for(int i=1;i<strs.size();++i)
            {
                if(temp==strs[i][index])
                {
                    continue;
                }
                else
                {
                    tempres=false;
                    break;
                }
            }
            if(tempres){
                res+=temp;
                ++index;
            }
        }
        return res;
    }
private:
    bool isempty(vector<string> &strs){
        for(int i=0;i<strs.size();++i)
        {
            if(strs[i].empty())
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<string> strs={"a"};
    Solution s;
    cout<<s.longestCommonPrefix(strs);
    return 0;
}