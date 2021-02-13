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
    int maxDepth(Node* root) {
        queue<Node*> que;
        int count=0;
        if(root==nullptr)
        {
            return count;
        }
        que.push(root);
        while(!que.empty())
        {
            int length=que.size();
            for(int i=0;i<length;i++)
            {
                Node* tree=que.front();
                que.pop();
                int nums=tree->children.size();
                for(int j=0;j<nums;j++)
                {
                    if(tree->children[j]!=nullptr)
                    {
                        que.push(tree->children[j]);
                    }
                }
            }
            count++;
        }
        return count;
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
    cout<<s.maxDepth(root);
    return 0;
}