#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root==nullptr)
        {
            return res;
        }
        q.push(root);
        int count=1;
        while(!q.empty())
        {
            vector<int> temp;
            int leng=q.size();
            for(int i=0;i<leng;i++)
            {
                TreeNode* temptree=q.front();
                q.pop();
                temp.push_back(temptree->val);
                if(temptree->left!=nullptr)
                {
                    q.push(temptree->left);
                }
                if(temptree->right!=nullptr)
                {
                    q.push(temptree->right);
                }
            }
            if(count==1)
            {
                count=0;
            }
            else
            {
                count=1;
                reverse(temp.begin(),temp.end());
            }
            
            res.push_back(temp);
        }
        return res;
    }
};
int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(3);
    TreeNode* node3=new TreeNode(4);
    TreeNode* node4=new TreeNode(5);
    node1->left=node3;
    node2->right=node4;
    root->left=node1;
    root->right=node2;
    Solution s;
    vector<vector<int>> res=s.zigzagLevelOrder(root);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}