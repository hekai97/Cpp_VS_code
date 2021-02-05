#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(newInterval.size()==0)
        {
            return intervals;
        }
        intervals.push_back(newInterval);
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=res[j][1])
            {
                res[j][0]=min(res[j][0],intervals[i][0]);
                res[j][1]=max(res[j][1],intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> a={{1,3},{6,9}};
    vector<int> b={2,5};
    Solution s;
    vector<vector<int>> res=s.insert(a,b);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
