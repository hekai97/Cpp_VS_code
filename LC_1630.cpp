#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++)
        {
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            res.push_back(check(temp));
        }
        return res;
    }
    bool check(vector<int> temp)
    {
        if(temp.size()<=2)
        {
            return true;
        }
        sort(temp.begin(),temp.end());
        int k=temp[1]-temp[0];
        for(int i=2;i<temp.size();i++)
        {
            if((temp[i]-temp[i-1])!=k)return false;
        }
        return true;
    }
};
int main()
{
    vector<int> nums={4,6,5,9,3,7};
    vector<int> l={0,0,2};
    vector<int> r={2,3,5};
    Solution s;
    vector<bool> res=s.checkArithmeticSubarrays(nums,l,r);
    for(bool a:res)
    {
        cout<<a<<" ";
    }
    return 0;
}