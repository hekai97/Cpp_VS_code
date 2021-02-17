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
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;
    }
};
int main()
{
    TreeNode* root=new TreeNode(3);
    TreeNode* node1=new TreeNode(9);
    TreeNode* node2=new TreeNode(20);
    TreeNode* node3=new TreeNode(15);
    TreeNode* node4=new TreeNode(7);
    node2->left=node3;
    node2->right=node4;
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.minDepth(root);
    return 0;
}