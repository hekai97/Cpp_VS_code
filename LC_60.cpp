#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = i * factorial[i - 1];
        };
        k--;
        int startnum=k/factorial[n-1]+1;
        int remaning=k%factorial[n-1]+1;
        string temp;
        vector<int> now;
        string reSS;
        vector<bool> used(10);
        int count=0;
        try{
            dfs(temp,n,now,count,remaning,used,startnum);
        }
        catch(string s)
        {
            reSS=s;
        }
        return reSS;
    }
private:
    void dfs(string temp,int n,vector<int>& now,int& count,int k,vector<bool>& used,int start)
    {
        if(temp.size()==n)
        {
            count++;
            //res.push_back(temp);
            if(count==k)
            {
                throw temp;
            }
            return;
        }
        else
        {
            for(int i=start;i<=n;i++)
            {
                if(used[i])
                {
                    continue;
                }
                temp+=to_string(i);
                now.push_back(i);
                used[i]=true;
                dfs(temp,n,now,count,k,used,1);
                used[i]=false;
                now.pop_back();
                temp.pop_back();
            }
        }
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    Solution s;
    cout<<s.getPermutation(n,k);
    return 0;
}