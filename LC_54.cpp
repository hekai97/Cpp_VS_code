#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n=matrix.size(),m=matrix[0].size();
        int up=0,down=n-1,left=0,right=m-1;
        int count=0;
        while(count<n*m)
        {
            for(int i=left;i<=right;i++)
            {
                res.push_back(matrix[up][i]);
                count++;
                if(func(count,n*m))
                {
                    return res;
                }
            }
            for(int i=up+1;i<=down;i++)
            {
                res.push_back(matrix[i][right]);
                count++;
                if(func(count,n*m))
                {
                    return res;
                }
            }
            for(int i=right-1;i>=left;i--)
            {
                res.push_back(matrix[down][i]);
                count++;
                if(func(count,n*m))
                {
                    return res;
                }
            }
            for(int i=down-1;i>up;i--)
            {
                res.push_back(matrix[i][left]);
                count++;
                if(func(count,n*m))
                {
                    return res;
                }
            }
            up++;
            left++;
            right--;
            down--;
        }
        return res;
    }
    bool func(int a,int b)
    {
        if(a>=b)return true;
        return false;
    }
};
int main()
{
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution s;
    vector<int> res=s.spiralOrder(matrix);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}