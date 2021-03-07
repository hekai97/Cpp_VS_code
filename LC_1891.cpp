#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param arr: the distance between any two cities
     * @return: the minimum distance Alice needs to walk to complete the travel plan
     */
    int travelPlan(vector<vector<int>> &arr) {
        // Write your code here.
        int n=arr.size();
        deque<bool> visited(n);
        int ans=INT_MAX;
        int temp=0,count=0;
        dfs(arr,ans,temp,visited,count,0);
        return ans;
    }
private:
    void dfs(vector<vector<int>>& arr,int& ans,int temp,deque<bool>& visited,int count,int start)
    {
        if(start>=arr.size())return;
        if(count==arr.size())
        {
            ans=min(ans,temp);
            return;
        }
        for(int i=0;i<arr[start].size();++i)
        {
            if(count!=arr.size()-1&&i==0){
                continue;
            }
            if(!visited[i]&&start!=i)
            {
                visited[i]=true;
                dfs(arr,ans,temp+arr[start][i],visited,count+1,i);
                visited[i]=false;
            }
        }
    }
};
int main()
{
    vector<vector<int>> arr={
        {0,10000,2},
        {5,0,10000},
        {10000,4,0}
    };
    Solution s;
    cout<<s.travelPlan(arr);
    return 0;
}