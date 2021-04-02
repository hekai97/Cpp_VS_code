#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_set<int> numset;
        for(auto a:nums)
        {
            numset.emplace(a);
        }
        int maxlength=0;
        for(auto a:numset)
        {
            if(!numset.count(a-1))
            {
                int currnum=a;
                int length=1;
                while(numset.count(currnum+1))
                {
                    currnum+=1;
                    length+=1;
                }
                maxlength=max(maxlength,length);
            }
        }
        return maxlength;
    }
};
int main()
{
    vector<int> nums={100,4,200,1,3,2};
    Solution s;
    cout<<s.longestConsecutive(nums);
    return 0;
}