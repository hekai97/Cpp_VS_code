#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        int mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(target==nums[mid])return mid;
            else if(target<nums[mid])high=mid;
            else if(target>nums[mid])low=mid+1;
        }
        return low;
    }
};
int main()
{
    vector<int> a={1,3,5,6};
    Solution s;
    int target;
    while(1)
    {
        cin>>target;
        if(cin.fail())break;
        cout<<s.searchInsert(a,target)<<endl;
    }
    return 0;
}