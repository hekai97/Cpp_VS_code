#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n=nums.size(),m=nums[0].size();
        if(n*m!=r*c)return nums;
        vector<vector<int>> res(r,vector<int>(c));
        for(int i=0;i<m*n;i++)
        {
            res[i/c][i%c]=nums[i/n][i%n];
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> nums={
        {1,2,3,4}
    };
    Solution s;
    vector<vector<int>> res=s.matrixReshape(nums,2,2);
    for(int i=0;i<res.size();++i)
    {
        for(int j=0;j<res[i].size();++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}