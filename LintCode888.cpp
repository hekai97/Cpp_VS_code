#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
        for(int i=0;i<words.size();i++)
        {
            string temp="";
            for(int j=0;j<words[i].size();j++)
            {
                temp+=words[j][i];
            }
            if(words[i]==temp)
            {
                continue;
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
    vector<string> words={"abcd","bnrt","crm","dt"};
    Solution s;
    cout<<s.validWordSquare(words);
    return 0;
}