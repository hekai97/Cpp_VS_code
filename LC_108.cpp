#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums,0,nums.size()-1);
    }
private:
    TreeNode* sorted(vector<int>& nums,int left,int right)
    {
        if(left>right)return nullptr;
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sorted(nums,left,mid-1);
        root->right=sorted(nums,mid+1,right);
        return root;
    }
};
int main()
{
    vector<int> nums={-10,-3,0,5,9};
    Solution s;
    TreeNode* root=s.sortedArrayToBST(nums);
    return 0;
}