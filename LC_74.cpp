#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size()-1;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][m]==target)
            {
                return true;
            }
            else if(matrix[i][m]>target)
            {
                for(int j=m;j>=0;j--)
                {
                    if(matrix[i][j]==target)
                    {
                        return true;
                    } 
                }
                return false;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    clock_t start,end;
    start=clock();
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<s.searchMatrix(matrix,3);
    cout<<endl;
    end=clock();
    cout<<end-start<<"ms"<<endl;
    return 0;
}