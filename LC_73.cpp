//该代码使用的了额外的O(mn)空间，属于一种不好的解决方案
//代码还可以进行优化，题目上说可以优化到常数级
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        deque<deque<bool>> visited(n,deque<bool>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==0&&!visited[i][j])
                {
                    setRC(matrix,visited,i,j);
                }
            }
        }
    }
private:
    void setRC(vector<vector<int>>& matrix,deque<deque<bool>>& visited,int x,int y)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            if(matrix[x][j]!=0&&!visited[x][j])
            {
                matrix[x][j]=0;
                visited[x][j]=true;
            }
        }
        for(int i=0;i<matrix.size();++i)
        {
            if(matrix[i][y]!=0&&!visited[i][y])
            {
                matrix[i][y]=0;
                visited[i][y]=true;
            }
        }
    }
};
int main()
{
    vector<vector<int>> matrix={
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution s;
    s.setZeroes(matrix);
    for(auto a:matrix)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}