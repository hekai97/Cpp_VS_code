#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
    int dfs(vector<vector<int>>& grid, int x, int y) 
    {
        if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] != 1)
        {
            return 0;
        }
        grid[x][y] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int i = 0; i != 4; ++i) 
        {
            int nx = x + di[i];
            int ny = y + dj[i];
            ans += dfs(grid, nx, ny);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i)
        {
            for (int j = 0; j != grid[0].size(); ++j)
                {
                    int res=dfs(grid,i,j);
                    ans = max(ans,res);
                }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> grid;
    vector<int> t;
    int temp;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> temp;
            t.push_back(temp);
        }
        grid.push_back(t);
    }
    Solution s;
    int ans = s.maxAreaOfIsland(grid);
    cout << ans << endl;
    return 0;
}