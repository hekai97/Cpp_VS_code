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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root==nullptr)
        {
            return res;
        }
        que.push(root);
        while(!que.empty())
        {
            int temp=INT_MIN;
            int length=que.size();
            for(int i=0;i<length;i++)
            {
                TreeNode* tree=que.front();
                que.pop();
                temp=max(temp,tree->val);
                if(tree->left!=nullptr)que.push(tree->left);
                if(tree->right!=nullptr)que.push(tree->right);
            }
            res.push_back(temp);
        }
        return res;
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
    vector<int> res=s.largestValues(root);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}