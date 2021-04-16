#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution{
public:
    int MaxNum(vector<vector<int>>& nums)
    {
        int n=nums.size();
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<i+1;++j)
            {
                nums[i][j]+=max(nums[i+1][j],nums[i+1][j+1]);
            }
        }
        return nums[0][0];
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(n,-1));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i+1;++j)
        {
            cin>>nums[i][j];
        }
    }
    Solution s;
    cout<<s.MaxNum(nums);
    return 0;
}
