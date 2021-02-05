#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int up=0,down=n-1,left=0,right=n-1;
        int count=1;
        while(count<=n*n)
        {
            for(int i=left;i<=right;i++)
            {
                res[up][i]=count;
                count++;
                if(func(count,n*n))
                {
                    return res;
                }
            }
            for(int i=up+1;i<=down;i++)
            {
                res[i][right]=count;
                count++;
                if(func(count,n*n))
                {
                    return res;
                }
            }
            for(int i=right-1;i>=left;i--)
            {
                res[down][i]=count;
                count++;
                if(func(count,n*n))
                {
                    return res;
                }
            }
            for(int i=down-1;i>up;i--)
            {
                res[i][left]=count;
                count++;
                if(func(count,n*n))
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
        if(a>b)return true;
        return false;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<vector<int>> res=s.generateMatrix(n);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}