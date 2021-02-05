#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    int temp;
    int res=1;
    vector<int> nums;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    temp=nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]==temp)
        {
            res++;
        }
        else
        {
            cout<<nums[i-1]<<" "<<res<<endl;
            temp=nums[i];
            res=1;
        }
    }
    cout<<nums[nums.size()-1]<<" "<<res<<endl;
    return 0;
}