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
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int res=0;
        int temp=0;
        dfs(res,temp,root);
        return res;
    }
private:
    void dfs(int& res,int temp,TreeNode* root)
    {
        temp=temp*10+root->val;
        if(root->left!=nullptr)dfs(res,temp,root->left);
        if(root->right!=nullptr)dfs(res,temp,root->right);
        if(root!=nullptr&&root->left==nullptr&&root->right==nullptr)
        {
            res+=temp;
            return;
        }
    }
};
int main()
{
    TreeNode* root=new TreeNode(4);
    TreeNode* node1=new TreeNode(9);
    TreeNode* node2=new TreeNode(0);
    TreeNode* node3=new TreeNode(5);
    TreeNode* node4=new TreeNode(1);
    node1->left=node3;
    node1->right=node4;
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.sumNumbers(root);
    return 0;
}