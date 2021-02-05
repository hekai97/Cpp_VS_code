#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {                 //牛顿迭代法
        double a,b;
        a = b = 1;
        while(1)
        {
            a=b;
            b = 0.5 * (a + (x / a));
            if(fabs(b-a)<1)
            {
                return b;
            }
        }
    }
};
int main()
{
    Solution a;
    int b = a.mySqrt(3);
    cout<<b<<endl;
    getchar();
    return 0;
}