#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sum1 = 0 , sum2 = 0;
        for(auto i : s)
        {
            if(i == ' ')
            {
                sum1 = 0;
            }
            else
            {
                sum1++;
            }
            if(sum1 != 0)
            {
                sum2 = sum1;
            }
        }
        return sum2;
    }
};
int main()
{
    Solution a;
    string b;
    getline(cin,b);
    int res = a.lengthOfLastWord(b);
    cout<<res<<endl;
    return 0;
}