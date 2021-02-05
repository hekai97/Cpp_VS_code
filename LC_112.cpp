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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
            return false;
        }
        else if(root->left==nullptr&&root->right==nullptr)
        {
            return targetSum-root->val==0;
        }
        else
        {
            return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
        }
    }
};
int main()
{
    TreeNode* root=new TreeNode(5);
    TreeNode* node1=new TreeNode(4);
    TreeNode* node2=new TreeNode(8);
    TreeNode* node3=new TreeNode(11);
    TreeNode* node4=new TreeNode(13);
    TreeNode* node5=new TreeNode(4);
    TreeNode* node6=new TreeNode(7);
    TreeNode* node7=new TreeNode(2);
    TreeNode* node8=new TreeNode(1);
    node5->right=node8;
    node3->left=node6;
    node3->right=node7;
    node1->left=node3;
    node2->left=node4;
    node2->right=node5;
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.hasPathSum(root,21);
    return 0;
}