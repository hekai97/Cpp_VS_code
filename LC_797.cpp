#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(0);
        dfs(res,temp,graph,0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res,vector<int>& temp,vector<vector<int>>& graph,int k){
        if(k==graph.size()-1)
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<graph[k].size();++i)
        {
            temp.push_back(graph[k][i]);
            dfs(res,temp,graph,graph[k][i]);
            temp.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> graph{
        {1,2},
        {3},
        {3},
        {}
    };
    vector<vector<int>> res=s.allPathsSourceTarget(graph);
    for(auto i=0;i<res.size();++i)
    {
        for(auto j=0;j<res[i].size();++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}