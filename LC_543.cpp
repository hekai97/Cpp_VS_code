#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        dfs(root);
        return Max;
    }
private:
    int Max;
    int dfs(TreeNode* root){
        if(root->left==nullptr&&root->right==nullptr){
            return 0;
        }
        int leftlength=root->left==nullptr?0:dfs(root->left)+1;
        int rightlength=root->right==nullptr?0:dfs(root->right)+1;
        Max=max(Max,leftlength+rightlength);
        return max(leftlength,rightlength);
    }
};
int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(3);
    TreeNode* node3=new TreeNode(4);
    TreeNode* node4=new TreeNode(5);
    node1->left=node3;
    node1->right=node4;
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.diameterOfBinaryTree(root);
    return 0;
}