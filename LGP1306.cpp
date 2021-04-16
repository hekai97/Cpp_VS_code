#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution{
public:
    int Number(vector<int>& nums,int k)
    {
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(res,temp,nums,k,0,0);
        return res.size();
    }
private:
    void backtracking(vector<vector<int>>& res,vector<int>& temp,vector<int>& nums,int k,int start,int tempres)
    {
        if(k==0)
        {
            if(isPrimer(tempres))
            {
                res.push_back(temp);
            }
            return;
        }
        for(int i=start;i<nums.size();++i)
        {
            temp.push_back(nums[i]);
            backtracking(res,temp,nums,k-1,i+1,tempres+nums[i]);
            temp.pop_back();
        }
    }
    bool isPrimer(int a)
    {
        for(int i=2;i<=sqrt(a);++i)
        {
            if(a%i==0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;++i)
    {
        cin>>nums[i];
    }
    Solution s;
    cout<<s.Number(nums,k);
    return 0;
}