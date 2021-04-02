#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int powN = 1 << n;
        for(int i = 0; i < powN; ++i)
        {
            int temp=i>>1;
            ans.push_back(i^temp);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> res=s.grayCode(n);
    for(auto a:res)
    {
        cout<<a<<" ";
    }
    return 0;
}