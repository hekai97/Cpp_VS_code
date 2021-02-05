#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}    //初始化当前结点值为x,指针为空
 };
 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Temp = head;
        while(Temp != nullptr)
        {
            while(Temp->next != nullptr)
            {
                if(Temp->val == Temp->next->val)
                {
                    ListNode* Temp1 = Temp->next;
                    Temp->next = Temp1->next;
                    delete Temp1;
                }
                else
                {
                    break;
                }
                
            }
            Temp = Temp->next;
        }
        delete Temp;
        return head;
    }
};