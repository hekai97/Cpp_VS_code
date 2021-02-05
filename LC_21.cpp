#include<iostream>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode();
        ListNode* temp1=&*temp;
        ListNode* p;
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val<=l2->val)
            {
                p=new ListNode(l1->val);
                l1=l1->next;
            }
            else
            {
                p=new ListNode(l2->val);
                l2=l2->next;
            }
            temp1->next=p;
            temp1=temp1->next;
        }
        if(l1!=nullptr)
        {
            temp1->next=l1;
        }
        else
        {
            temp1->next=l2;
        }
        
        return temp->next;
    }
};
//测试代码
int main()
{
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(2);
    l1->next->next=new ListNode(4,nullptr);
    ListNode* l2=new ListNode(1);
    l2->next=new ListNode(3);
    l2->next->next=new ListNode(4,nullptr);
    Solution s;
    ListNode* temp=s.mergeTwoLists(l1,l2);
    while(temp!=nullptr)
    {
        cout<<temp->val;
        temp=temp->next;
    }
    return 0;
}