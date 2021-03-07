#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void Mine(vector<vector<char>>& source){
        const vector<vector<int>> direction{
            {-1,-1},
            {-1,0},
            {-1,1},
            {0,-1},
            {0,1},
            {1,-1},
            {1,0},
            {1,1}
        };
        for(int i=0;i<source.size();++i)
        {
            for(int j=0;j<source[i].size();++j)
            {
                if(source[i][j]=='*')
                {
                    for(int k=0;k<direction.size();++k)
                    {
                        if(i+direction[k][0]<source.size()&&i+direction[k][0]>=0&&j+direction[k][1]<source[i].size()&&j+direction[k][1]>=0)
                        {
                            if(!isalnum(source[i+direction[k][0]][j+direction[k][1]]))
                            {
                                if(source[i+direction[k][0]][j+direction[k][1]]!='*')
                                {
                                    source[i+direction[k][0]][j+direction[k][1]]='1';
                                }
                            }
                            else
                            {
                                source[i+direction[k][0]][j+direction[k][1]]+=1;
                            }
                        }
                    }
                }
            }
        }
        for(auto &a:source)
        {
            for(auto &b:a)
            {
                if(b=='?')
                {
                    b='0';
                }
            }
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> source(n,vector<char>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>source[i][j];
        }
    }
    Solution s;
    s.Mine(source);
    for(auto a:source)
    {
        for(auto b:a)
        {
            cout<<b;
        }
        cout<<endl;
    }
    return 0;
}