#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int chance=1;
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isVail(s,i+1,j)||isVail(s,i,j-1);
            }
        }
        return true;
    }
private:
    bool isVail(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
            {
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
    string s="aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    Solution sol;
    cout<<sol.validPalindrome(s);
    return 0;
}