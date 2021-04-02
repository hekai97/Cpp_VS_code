#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();++i)
        {
            int j;
            for(j=matrix[i].size()-1;j>=0;j--)
            {
                if(target==matrix[i][j])
                {
                    return true;
                }
                else if(target>matrix[i][j])
                {
                    break;
                }
                else if(target<matrix[i][j])
                {
                    continue;
                }
            }
            if(j==-1)
            {
                return false;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> matrix={
        {5},
        {6}
    };
    Solution s;
    cout<<s.searchMatrix(matrix,6);
    return 0;
}