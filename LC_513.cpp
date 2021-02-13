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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int count=1;
        int res;
        que.push(root);
        int high=Treehigh(root);
        while(!que.empty())
        {
            int length=que.size();
            for(int i=0;i<length;i++)
            {
                TreeNode* q=que.front();
                que.pop();
                if(count==high)
                {
                    res=q->val;
                    break;
                }
                if(q->left!=nullptr)que.push(q->left);
                if(q->right!=nullptr)que.push(q->right);
            }
            count++;
        }
        return res;
    }
private:
    int Treehigh(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        return max(Treehigh(root->left),Treehigh(root->right))+1;
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
    cout<<s.findBottomLeftValue(root);
    return 0;
}