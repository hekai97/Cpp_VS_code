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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<string> res;
        dfs(res,root,"");
        return res;
    }
private:
    void dfs(vector<string>& res,TreeNode*root,string path)
    {
        path+=to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            res.push_back(path);
        }
        if(root->left!=nullptr)dfs(res,root->left,path+"->");
        if(root->right!=nullptr)dfs(res,root->right,path+"->");
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
    TreeNode* node9=new TreeNode(5);
    node5->right=node8;
    node5->left=node9;
    node3->left=node6;
    node3->right=node7;
    node1->left=node3;
    node2->left=node4;
    node2->right=node5;
    root->left=node1;
    root->right=node2;
    Solution s;
    vector<string> res=s.binaryTreePaths(root);
    for(auto c:res)
    {
        cout<<c<<" ";
    }
    return 0;
}