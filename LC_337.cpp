#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(check[root],uncheck[root]);
    }
private:
    unordered_map<TreeNode*,int>check,uncheck;
    void dfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->left!=nullptr)dfs(root->left);
        if(root->right!=nullptr)dfs(root->right);
        check[root]=uncheck[root->left]+uncheck[root->right]+root->val;
        uncheck[root]=max(check[root->left],uncheck[root->right])+max(check[root->right],uncheck[root->right]);
    }
};
int main()
{
    TreeNode* root=new TreeNode(3);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(3);
    TreeNode* node3=new TreeNode(3);
    TreeNode* node4=new TreeNode(1);
    node1->right=node3;
    node2->right=node4;
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.rob(root);
    return 0;
}