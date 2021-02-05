#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n>=5)
        {
            res+=n/5;
            n=n/5;
        }
        return res;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.trailingZeroes(n);
    return 0;
}