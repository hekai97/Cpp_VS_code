#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
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
                Node* tree=que.front();
                que.pop();
                temp.push_back(tree->val);
                int nums=tree->children.size();
                for(int j=0;j<nums;j++)
                {
                    if(tree->children[j]!=nullptr)
                    {
                        que.push(tree->children[j]);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
int main()
{
    Node* root=new Node(1);
    Node* node1_1=new Node(3);
    Node* node1_2=new Node(2);
    Node* node1_3=new Node(4);
    Node* node2_1=new Node(5);
    Node* node2_2=new Node(6);
    node1_3->children.push_back(node2_1);
    node1_3->children.push_back(node2_2);
    root->children.push_back(node1_1);
    root->children.push_back(node1_2);
    root->children.push_back(node1_3);
    Solution s;
    vector<vector<int>> res=s.levelOrder(root);
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