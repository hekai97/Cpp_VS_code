#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string profession(vector<pair<int,string>>& persons,vector<pair<int,int>>& instructions){
        int index=0;
        for(int i=0;i<instructions.size();++i)
        {
            while(index>=persons.size())
            {
                index%=persons.size();
            }
            if(persons[index].first==0)
            {
                if(instructions[i].first==0)
                {
                    index+=(persons.size()-(instructions[i].second%persons.size()));
                }
                else
                {
                    index+=(instructions[i].second%persons.size());
                }
            }
            else
            {
                if(instructions[i].first==0)
                {
                    index+=(instructions[i].second%persons.size());
                }
                else
                {
                    index+=(persons.size()-(instructions[i].second%persons.size()));
                }
            }
        }
        return persons[index].second;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,string>> persons;
    vector<pair<int,int>> instructions;
    for(int i=0;i<n;++i)
    {
        int a;
        string b;
        cin>>a>>b;
        persons.push_back(make_pair(a,b));
    }
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        instructions.push_back(make_pair(a,b));
    }
    Solution s;
    cout<<s.profession(persons,instructions);
    return 0;
}