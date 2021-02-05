#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i=1;
        ListNode* temp=head;
        ListNode* res=new ListNode(-1,head);
        ListNode* res1=res;
        stack<ListNode*> t;
        while(temp!=nullptr)
        {
            if(i<=m-1)
            {
                res=res->next;
            }
            if(i>=m&&i<=n)
            {
                t.push(temp);
            }
            if(i>n)
            {
                break;
            }
            i++;
            temp=temp->next;
        }
        while(!t.empty())
        {
            res->next=t.top();
            t.pop();
            res=res->next;
        }
        res->next=temp;
        return res1->next;
    }
};
int main()
{
    ListNode* head=new ListNode(1);
    ListNode* node1=new ListNode(2);
    ListNode* node2=new ListNode(3);
    ListNode* node3=new ListNode(4);
    ListNode* node4=new ListNode(5);
    node3->next=node4;
    node2->next=node3;
    node1->next=node2;
    head->next=node1;
    // ListNode* head=new ListNode(3);
    // ListNode* end=new ListNode(5);
    // head->next=end;
    Solution s;
    ListNode* res=s.reverseBetween(head,1,2);
    while(res!=nullptr)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}