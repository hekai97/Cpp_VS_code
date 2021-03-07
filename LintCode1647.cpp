#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param n: The number of points
     * @param G: The description of graph
     * @param S: The point S
     * @param T: The point T
     * @return: output all the paths from S to T
     */
    vector<vector<int>> getPath(int n, vector<vector<int>> &G, int S, int T) {
        // Write your code here
        deque<bool> visited(n);
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(S);
        visited[S]=true;
        backtracking(res,temp,visited,G,T);
        sort(res.begin(),res.end());
        return res;
    }
private:
    void backtracking(vector<vector<int>>& res,vector<int>& temp,deque<bool>& visited,vector<vector<int>>& G,int t){
        if(temp.back()==t)
        {
            res.push_back(temp);
            return;
        }
        for(auto pairs:G)
        {
            if(!visited[pairs[1]]&&pairs[0]==temp.back())
            {
                visited[pairs[0]]=true;
                temp.push_back(pairs[1]);
                backtracking(res,temp,visited,G,t);
                temp.pop_back();
                visited[pairs[0]]=false;
            }
            else if(!visited[pairs[0]]&&pairs[1]==temp.back())
            {
                visited[pairs[1]]=true;
                temp.push_back(pairs[0]);
                backtracking(res,temp,visited,G,t);
                temp.pop_back();
                visited[pairs[1]]=false;
            }
        }
    }
};
int main()
{
    vector<vector<int>> G={
        {2,6},
        {3,6},
        {0,3},
        {2,5},
        {1,6},
        {3,4},
        {1,5},
        {2,3},
        {0,1},
        {3,5},
        {1,2},
        {0,2},
        {0,6},
        {1,4},
        {2,4},
        {4,5},
        {0,4},
        {5,6},
        {1,3},
        {0,5}
    };
    Solution s;
    vector<vector<int>> res=s.getPath(7,G,3,2);
    for(auto a:res)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}