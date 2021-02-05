#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        vector<vector<int>> res(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                if(i==0&&j==0)
                {
                    res[0][0]=grid[0][0];
                }
                else if(i==0)
                {
                    res[i][j]=res[i][j-1]+grid[i][j];
                }
                else if(j==0)
                {
                    res[i][j]=res[i-1][j]+grid[i][j];
                }
                else
                {
                    res[i][j]=min(res[i-1][j],res[i][j-1])+grid[i][j];
                }
                
            }
        }
        return res[res.size()-1][res[0].size()-1];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid={{1,3,1},{1,5,1,},{4,2,1}};
    cout<<s.minPathSum(grid);
    return 0;
}