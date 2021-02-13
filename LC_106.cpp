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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode();
        if(postorder.size()!=0)
        {
            root->val=postorder[postorder.size()-1];
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
        vector<int> Postleft(postorder.begin(),postorder.begin()+i);
        vector<int> Inright(inorder.begin()+i+1,inorder.end());
        vector<int> Postright(postorder.begin()+i,postorder.end()-1);
        root->left=buildTree(Inleft,Postleft);
        root->right=buildTree(Inright,Postright);
        return root;
    }
};
int main()
{
    vector<int> postorder={9,15,7,20,3};
    vector<int> inorder={9,3,15,20,7};
    Solution s;
    TreeNode*root=s.buildTree(inorder,postorder);
    return 0;
}