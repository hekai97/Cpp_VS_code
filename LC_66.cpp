#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;i--)
        {
            digits[i]+=1;
            if(digits[i]==10)
            {
                digits[i]=0;
                if(i==0&&digits[i]==0)
                {
                digits[i]+=1;
                digits.push_back(0);
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};
int main()
{
    Solution a;
    vector<int> b = {0,0,1};
    vector<int> c=a.plusOne(b);
    for(int i = 0;i<c.size();i++)
    {
        cout<<b[i]<<endl;
    }
    return 0;
}