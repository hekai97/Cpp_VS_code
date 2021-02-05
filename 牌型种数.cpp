#include <iostream>
using namespace std;
int sum = 0;
class Solution
{
public:
    auto func(int i,int s)
    {
        if(i>13)
        {
            return;
        }
        if(s>=13)
        {
            if(s==13)
            {
                sum++;
            }
            return;
        }
        func(i+1,s+0);
        func(i+1,s+1);
        func(i+1,s+2);
        func(i+1,s+3);
        func(i+1,s+4);
    }
};
int main()
{
    Solution slove;
    slove.func(0,0);
    cout<< sum <<endl;
    return 0;
}