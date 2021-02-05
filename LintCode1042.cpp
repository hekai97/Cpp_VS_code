#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // Write your code here
        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                if(i-1>=0&&j-1>=0&&matrix[i][j]!=matrix[i-1][j-1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    vector<vector<int>> matrix={{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    Solution s;
    cout<<s.isToeplitzMatrix(matrix)<<endl;
    return 0;
}