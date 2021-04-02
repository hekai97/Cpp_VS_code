#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> maps;
        for(int i=0;i<strs.size();++i)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            maps[temp].push_back(strs[i]);
        }
        for(auto it=maps.begin();it!=maps.end();++it)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
int main()
{
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> res=s.groupAnagrams(strs);
    for(auto a:res)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}