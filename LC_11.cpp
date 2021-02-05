#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,res=0;
        while(left<right)
        {
            res=max(res,((right-left)*(min(height[left],height[right]))));
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution s;
    cout<<s.maxArea(height);
    return 0;
}