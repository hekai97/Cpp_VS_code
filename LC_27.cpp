#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
int main()
{
    vector<int> a={0,1,2,3,4,5,6,7,8,9};
    int val=4;
    int res;
    Solution sol;
    res=sol.removeElement(a,val);
    for(int i=0;i<res;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<res<<endl;
    return 0;
}