#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;++i)
        {
            int over=0;
            int j;
            for(j=i;j<n+i;++j)
            {
                if(cost[j%n]>gas[j%n]+over)
                {
                    break;
                }
                else
                {
                    over=gas[j%n]-cost[j%n]+over;
                }
            }
            if(j==n+i)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> gas={5,1,2,3,4};
    vector<int> cost={4,4,1,5,1};
    Solution s;
    cout<<s.canCompleteCircuit(gas,cost);
    return 0;
}