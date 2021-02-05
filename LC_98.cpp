#include<iostream>
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
    bool isValidBST(TreeNode* root) {
        long long min=LONG_LONG_MIN;
        long long max=LONG_LONG_MAX;
        return checkTree(root,min,max);
    }
    bool checkTree(TreeNode* root,long long min,long long max)
    {
        if(root==nullptr)
        {
            return true;
        }
        else if(root->val<=min||root->val>=max)
        {
            return false;
        }
        return checkTree(root->left,min,root->val)&&checkTree(root->right,root->val,max);
    }
};
int main()
{
    // TreeNode* root1=new TreeNode(5);
    // TreeNode* node1=new TreeNode(4);
    // TreeNode* node2=new TreeNode(6);
    // TreeNode* node3=new TreeNode(3);
    // TreeNode* node4=new TreeNode(7);
    // node2->left=node3;
    // node2->right=node4;
    // root1->left=node1;
    // root1->right=node2;
    // Solution s;
    // cout<<s.isValidBST(root1);
    TreeNode* root=new TreeNode(2);
    TreeNode* node1=new TreeNode(1);
    TreeNode* node2=new TreeNode(3);
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.isValidBST(root);
    return 0;
}