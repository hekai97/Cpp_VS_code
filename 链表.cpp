#include <iostream>
using namespace std;
class Node
{
public:
    int a;
    Node* next;
};
Node* Head = nullptr;
Node* End = nullptr;
void addToend(int num)
{
    Node* temp = new Node;
    temp->a=num;
    temp->next=nullptr;
    if(Head==nullptr)
    {
        Head=temp;
        End=temp;
    }
    else
    {
        End->next=temp;
        End=temp;
    }
}
void des()
{
    Node* temp=Head;
    while(temp!=nullptr)
    {
        Node* pt=temp;
        temp=temp->next;
        delete pt;
    }
    Head=nullptr;
    End=nullptr;
}
int main()
{
    for(int i=0;i<10;++i)
    {
        addToend(i);
    }
    Node* temp = Head;
    while(temp!=nullptr)
    {
        cout<<temp->a<<endl;
        temp=temp->next;
    }
    des();
    return 0;
}