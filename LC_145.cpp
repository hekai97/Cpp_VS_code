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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(res,root);
        return res;
    }
private:
    void postorder(vector<int>& res,TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        postorder(res,root->left);
        postorder(res,root->right);
        res.push_back(root->val);
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
    vector<int> res=s.postorderTraversal(root);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}