#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string temp(n,'.');
        vector<string> maps(n,temp);
        backtracking(res,maps,0,n);
        return res;
    }
private:
    void backtracking(vector<vector<string>>& res,vector<string>& map,int row,int n)
    {
        if(row==n)
        {
            res.push_back(map);
            return;
        }
        for(int i=0;i<n;++i)
        {
            bool a=true;
            int count=1;
            for(int j=row-1;j>=0;j--)
            {
                if(map[j][i]!='Q'   //上一行有Q
                &&((i+count<map[0].size()&&map[j][i+count]!='Q')||(i+count>=map[0].size())) //右斜上方有Q或者索引超出数组
                &&((i-count>=0&&map[j][i-count]!='Q')||(i-count<0)))                        //左斜上方有Q或者索引超出数组
                {
                    count++;                                                                //控制方向的变量，让其一直在一条直线上
                    a=true;
                }
                else
                {
                    a=false;
                    break;
                }
            }
            if(a)
            {
                map[row][i]='Q';
                backtracking(res,map,row+1,n);                                              //常规回溯
                map[row][i]='.';
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<vector<string>> res=s.solveNQueens(n);
    for(int i=0;i<res.size();++i)
    {
        for(int j=0;j<res[i].size();++j)
        {
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}