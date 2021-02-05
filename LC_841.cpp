#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        DFS(rooms,visited,0);
        for(auto c:visited)
        {
            if(c==false)
            {
                return false;
            }
        }
        return true;
    }
    void DFS(vector<vector<int>>& rooms,vector<bool>& visited,int num)
    {
        // if(visited[num]==true)
        // {
        //     return;
        // }
        if(!visited[num])
        {
            visited[num]=true;
            //vector<int> nextroom=rooms[num];
            for(auto a:rooms[num])
            {
                DFS(rooms,visited,a);
            }
        }
    }
};
int main()
{
    vector<vector<int>> rooms={{1,3},{3,0,1},{2},{0}};
    Solution s;
    cout<<s.canVisitAllRooms(rooms);
    return 0;
}