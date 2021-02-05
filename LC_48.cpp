#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int temp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix.size();j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size()/2;j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[i][matrix.size()-j-1];
                matrix[i][matrix.size()-j-1]=temp;
            }
        }
    }
};
int main()
{
    vector<vector<int>> a={{1,2,3},{4,5,6},{7,8,9}};
    Solution b;
    b.rotate(a);
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<a.size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}