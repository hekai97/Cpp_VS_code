#include<iostream>
#include<vector>
#include<algorithm>
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
    int i=0;
    void recoverTree(TreeNode* root) {
        vector<int> res;
        GetInorder(root,res);
        sort(res.begin(),res.end());
        RecInorder(root,res);
    }
    void GetInorder(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)
        {
            return;
        }
        GetInorder(root->left,res);
        res.push_back(root->val);
        GetInorder(root->right,res);
    }
    void RecInorder(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)
        {
            return;
        }
        RecInorder(root->left,res);
        root->val=res[i];
        i++;
        RecInorder(root->right,res);
    }
};
int main()
{
    TreeNode* root=new TreeNode(3);
    TreeNode* node1=new TreeNode(1);
    TreeNode* node2=new TreeNode(4);
    TreeNode* node3=new TreeNode(2);
    node2->left=node3;
    root->left=node1;
    root->right=node2;
    Solution s;
    s.recoverTree(root);
    return 0;
}