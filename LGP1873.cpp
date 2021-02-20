#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    std::size_t maxHeight(vector<int>& height,int target){
        sort(height.begin(),height.end());
        std::size_t res;
        std::size_t bottom=0,up=height[height.size()-1];
        while(bottom<=up)
        {
            res=0;
            std::size_t mid=bottom+(up-bottom)/2;
            for(auto& c:height){
                if(c>mid){
                    res+=(c-mid);
                }
            }
            if(res==target)return mid;
            if(res>target)bottom=mid+1;
            else if(res<target)up=mid-1;
        }
        return up;
    }
};
int main(void)
{
    int n,target;
    cin>>n>>target;
    vector<int> height(n);
    for(int i=0;i<n;++i)
    {
        cin>>height[i];
    }
    Solution s;
    cout<<s.maxHeight(height,target);
    return 0;
}