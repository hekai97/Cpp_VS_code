#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            if(i>=1)
            {
                for(int j=1;j<i;j++)
                {
                    temp.push_back(res[i-1][j-1]+res[i-1][j]);
                }
                temp.push_back(1);
            }
            res.push_back(temp);
        }
        return res;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<vector<int>>res=s.generate(n);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}