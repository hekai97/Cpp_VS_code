#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int start=image[sr][sc];
        if(start==newColor)
        {
            return image;
        }
        DFS(image,sr,sc,newColor,start);
        return image;
    }
    void DFS(vector<vector<int>>& image,int x,int y,int newColor,int nowColor)
    {
        if(x<0||y<0||x>=image.size()||y>=image[x].size()||image[x][y]!=nowColor)
        {
            return;
        }
        image[x][y]=newColor;
        DFS(image,x+1,y,newColor,nowColor);
        DFS(image,x-1,y,newColor,nowColor);
        DFS(image,x,y+1,newColor,nowColor);
        DFS(image,x,y-1,newColor,nowColor);
    }
};
int main()
{
    vector<vector<int>> image={{0,0,0},
                               {0,1,1}};
    Solution s;
    vector<vector<int>> res=s.floodFill(image,1,1,1);
    for(auto i=0;i<res.size();i++)
    {
        for(auto j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}