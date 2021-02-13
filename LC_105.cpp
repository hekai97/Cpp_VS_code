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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode();
        if(preorder.size()!=0)
        {
            root->val=preorder[0];
        }
        else
        {
            return nullptr;
        }
        int i;
        vector<int> Inleft;
        for(i=0;i<inorder.size();++i)
        {
            if(inorder[i]==root->val)
            {
                break;
            }
            Inleft.push_back(inorder[i]);
        }
        vector<int> Preleft(preorder.begin()+1,preorder.begin()+i+1);
        vector<int> Inright(inorder.begin()+i+1,inorder.end());
        vector<int> Preright(preorder.begin()+i+1,preorder.end());
        root->left=buildTree(Preleft,Inleft);
        root->right=buildTree(Preright,Inright);
        return root;
    }
};
int main()
{
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    Solution s;
    TreeNode*root=s.buildTree(preorder,inorder);
    return 0;
}