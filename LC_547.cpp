#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0;
        vector<bool> visited(isConnected.size());
        for(auto i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                dfs(isConnected,visited,i);
                res++;
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int order){
        for(int j=0;j<isConnected[order].size();j++)
        {
            if(isConnected[order][j]==1&&!visited[j])
            {
                visited[j]=true;
                dfs(isConnected,visited,j);
            }
        }
    }
};
int main()
{
    vector<vector<int>> isConnected{
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    Solution s;
    cout<<s.findCircleNum(isConnected);
    return 0;
}