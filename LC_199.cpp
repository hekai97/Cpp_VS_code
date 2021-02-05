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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> a;
        a.push(root);
        while(!a.empty())
        {
            int n=a.size();
            res.push_back(a.front()->val);
            while(n--)
            {
                TreeNode* temp=a.front();
                a.pop();
                if(temp->right!=nullptr)a.push(temp->right);
                if(temp->left!=nullptr)a.push(temp->left);
            }
        }
        return res;
    }
};
int main()
{
    // TreeNode* root=new TreeNode(1);
    // TreeNode* node1=new TreeNode(2);
    // TreeNode* node2=new TreeNode(3);
    // TreeNode* node3=new TreeNode(5);
    // TreeNode* node4=new TreeNode(4);
    // node2->right=node4;
    // node1->left=node3;
    // root->left=node1;
    // root->right=node2;
    TreeNode* root=new TreeNode(1);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(3);
    TreeNode* node3=new TreeNode(4);
    node1->left=node3;
    root->left=node1;
    root->right=node2;
    Solution s;
    vector<int> res=s.rightSideView(root);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}