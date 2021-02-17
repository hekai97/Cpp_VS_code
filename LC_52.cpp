#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        string temp(n,'.');
        vector<string> maps(n,temp);
        backtracking(res,maps,0,n);
        return res.size();
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
                &&((i+count<map[0].size()&&map[j][i+count]!='Q')||(i+count>=map[0].size())) 
                &&((i-count>=0&&map[j][i-count]!='Q')||(i-count<0)))                        
                {
                    count++;                          
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
                backtracking(res,map,row+1,n);
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
    cout<<s.totalNQueens(n);
    return 0;
}