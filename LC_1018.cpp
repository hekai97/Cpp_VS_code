#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int tmp=0;
        for(int i=0;i<A.size();i++)
        {
            tmp=tmp*2+A[i];
            if(tmp>10)tmp%=10;
            if(tmp%5==0)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> A={0,1,1,1,1,1};
    Solution s;
    vector<bool>res=s.prefixesDivBy5(A);
    for(auto a:res)
    {
        cout<<a<<" ";
    }
    return 0;
}