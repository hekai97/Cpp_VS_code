#include <iostream>
using namespace std;
class Solution
{
public:
    int func(int n,int m)
    {
        if(n==0)
        {
            return 1;
        }
        else if(m==0)
        {
            return func(n-1,1);
        }
        else
        {
            return func(n-1,m+1)+func(n,m-1);
        }
    }
};
int main()
{
    int num;
    cin >> num;
    Solution slove;
    int ans = slove.func(num,0);
    cout << ans << endl;
    return 0;
}