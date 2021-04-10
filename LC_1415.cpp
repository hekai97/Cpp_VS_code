#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        int count=0;
        string temp,ans;
        backtracking(n,k,count,temp,ans);
        return count==k?ans:"";
    }
private:
    void backtracking(int n,int k,int& count,string& temp,string& ans)
    {
        if(count==k)
        {
            return;
        }
        if(temp.size()==n)
        {
            count++;
            ans=temp;
            return;
        }
        for(char ch='a';ch<='c';++ch)
        {
            if(temp.size()&&temp.back()==ch)
            {
                continue;
            }
            temp.push_back(ch);
            backtracking(n,k,count,temp,ans);
            temp.pop_back();
        }
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    Solution s;
    cout<<s.getHappyString(n,k);
    return 0;
}