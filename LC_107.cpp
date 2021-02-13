#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root==nullptr)
        {
            return res;
        }
        que.push(root);
        while(!que.empty())
        {
            vector<int> temp;
            int length=que.size();
            for(int i=0;i<length;i++)
            {
                TreeNode* q=que.front();
                que.pop();
                temp.push_back(q->val);
                if(q->left!=nullptr)que.push(q->left);
                if(q->right!=nullptr)que.push(q->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
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
    vector<vector<int>> res=s.levelOrderBottom(root);
    for(auto i=0;i<res.size();i++)
    {
        for(auto j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}