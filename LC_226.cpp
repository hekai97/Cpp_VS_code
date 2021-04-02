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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* temp=root->right;
        root->right=invertTree(root->left);
        root->left=invertTree(temp);
        return root;
    }
};
int main()
{
    TreeNode* root=new TreeNode(4);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(7);
    TreeNode* node3=new TreeNode(1);
    TreeNode* node4=new TreeNode(3);
    TreeNode* node5=new TreeNode(6);
    TreeNode* node6=new TreeNode(9);
    node1->left=node3;
    node1->right=node4;
    node2->left=node5;
    node2->right=node6;
    root->left=node1;
    root->right=node2;
    Solution s;
    TreeNode* res=s.invertTree(root);
    return 0;
}