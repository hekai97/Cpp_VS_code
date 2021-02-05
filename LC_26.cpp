#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int j = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[j]!=nums[i])
            {
                j++;
                nums[j]=nums[i];
            }
            if(i>=nums.size())
            {
                break;
            }
        }
        return j+1;
    }
};
int main()
{
    vector<int> a={1,1,2,3,4,5,5,5,5,6,7};
    Solution b;
    int c=b.removeDuplicates(a);
    for(int i = 0;i<c;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<c<<endl;
    return 0;
}
