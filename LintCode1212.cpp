#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param nums: a binary array
     * @return:  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // Write your code here
        int res=0;
        int temp=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                temp++;
            }
            else
            {
                res=res>temp?res:temp;
                temp=0;
            }
        }
        return res;
    }
};
int main()
{
    vector<int>nums={1,1,0,1,1,1};
    Solution s;
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}