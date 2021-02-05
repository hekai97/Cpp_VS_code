#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3]={0};
        for(auto num:nums)
        {
            a[num]++;
        }
        int i=0;
        int temp=a[i];
        for(auto &num:nums)
        {
            if(temp!=0)
            {
                num=i;
                temp--;
            }
            else
            {
                while(temp==0)
                {
                    i++;
                    if(i<3)
                    {
                        temp=a[i];
                    }
                }
                num=i;
                temp--;
            }
        }
    }
};
int main()
{
    vector<int> a={2,0};
    Solution b;
    b.sortColors(a);
    for(auto c:a)
    {
        cout<<c<<endl;
    }
    return 0;
}