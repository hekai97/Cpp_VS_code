#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        return nums[nums.size()-n];
    }
};
int main()
{
    vector<int> nums={1,3,4,2};
    Solution s;
    cout<<s.kthLargestElement(2,nums);
    return 0;
}