#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1)return true;
        //int count=0;
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            while(i<j&&!(std::isalpha(s[i])||std::isalnum(s[i])))
            {
                i++;
            }
            while(i<j&&!(std::isalpha(s[j])||std::isalnum(s[j])))
            {
                j--;
            }
            if(std::tolower(s[i])==std::tolower(s[j]))
            {
                //count++;
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string s=".,";
    Solution sol;
    cout<<sol.isPalindrome(s);
    return 0;
}