#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* source=root;
        TreeNode* mirror=root;
        return isSameTree(source,mirror);
    }
    bool isSameTree(TreeNode* source,TreeNode* mirror)
    {
        if(source==nullptr&&mirror==nullptr)
        {
            return true;
        }
        else if(source==nullptr||mirror==nullptr)
        {
            return false;
        }
        else if(source->val!=mirror->val)
        {
            return false;
        }
        else 
        {
            return isSameTree(source->left,mirror->right)&&(isSameTree(mirror->right,source->left));
        }
    }
};
int main()
{
    TreeNode* node1=new TreeNode(3);
    TreeNode* node2=new TreeNode(4);
    TreeNode* node3=new TreeNode(4);
    TreeNode* node4=new TreeNode(3);
    TreeNode* node5=new TreeNode(2);
    TreeNode* node6=new TreeNode(2);
    TreeNode* root=new TreeNode(1);
    node5->left=node1;
    node5->right=node2;
    node6->left=node3;
    node6->right=node4;
    root->left=node5;
    root->right=node6;
    Solution s;
    cout<<s.isSymmetric(root);
    return 0;
}