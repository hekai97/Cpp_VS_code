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
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return 0;
        }
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return count;
    }
private:
    int count;
    void dfs(TreeNode* root,int sum){
        if(root==nullptr)
        {
            return;
        }
        else if(sum-root->val==0)
        {
            count++;
        }
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};
int main()
{
    TreeNode* root=new TreeNode(10);
    TreeNode* node1=new TreeNode(5);
    TreeNode* node2=new TreeNode(-3);
    TreeNode* node3=new TreeNode(3);
    TreeNode* node4=new TreeNode(2);
    TreeNode* node5=new TreeNode(11);
    TreeNode* node6=new TreeNode(3);
    TreeNode* node7=new TreeNode(-2);
    TreeNode* node8=new TreeNode(1);
    node3->left=node6;
    node3->right=node7;
    node4->right=node8;
    node1->left=node3;
    node1->right=node4;
    node2->right=node5;
    root->left=node1;
    root->right=node2;
    Solution s;
    cout<<s.pathSum(root,8);
    return 0;
}