#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0)
        {
            return head;
        }
        int length=0;
        ListNode* L=head;
        ListNode* temp;
        while(L!=NULL)
        {
            length++;
            L=L->next;
        }
        L=head;
        if(length==1)
        {
            delete(L);
            return NULL;
        }
        if(length==n)
        {
            temp=L;
            L=L->next;;
            delete(temp);
            return L;
        }
        for(int i=0;i<length-n-1;i++)
        {
            L=L->next;
        }
        temp=L->next;
        L->next=L->next->next;
        delete(temp);
        return head;
    }
};