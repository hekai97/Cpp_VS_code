#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int MinGroup(vector<int>& prices,int limit)
    {
        sort(prices.begin(),prices.end());
        int res=0;
        int i=0,j=prices.size()-1;
        while(i<=j)
        {
            if(prices[i]+prices[j]>limit)
            {
                res++;
                j--;
            }
            else if(prices[i]+prices[j]<=limit)
            {
                i++;
                j--;
                res++;
            }
        }
        return res;
    }
};
int main()
{
    int limit;
    int n;
    vector<int> prices;
    cin>>limit>>n;
    for(int i=0;i<n;++i)
    {
        int temp;
        cin>>temp;
        prices.push_back(temp);
    }
    Solution s;
    cout<<s.MinGroup(prices,limit);
    return 0;
}