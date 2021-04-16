#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution{
public:
    int IsLuckWord(string s)
    {
        vector<int> nums(26);
        for(int i=0;i<s.size();++i)
        {
            nums[s[i]-97]++;
        }
        sort(nums.begin(),nums.end());
        int temp;
        for(int i=0;i<25;++i)
        {
            if(nums[i]!=0)
            {
                temp=nums[i];
                break;
            }
        }
        int t=nums[25]-temp;
        if(isPrimer(t))
        {
            return t;
        }
        else
        {
            return 0;
        }
    }
private:
    bool isPrimer(int a)
    {
        if(a==2)
        {
            return true;
        }
        if(a==1)
        {
            return false;
        }
        for(int i=2;i<=sqrt(a);++i)
        {
            if(a%i==0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution sol;
    int res=sol.IsLuckWord(s);
    if(res!=0)
    {
        cout<<"Lucky Word"<<endl<<res<<endl;
    }
    else
    {
        cout<<"No Answer"<<endl<<0<<endl;
    }
    return 0;
}