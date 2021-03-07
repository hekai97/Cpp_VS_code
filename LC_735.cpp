#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> mystack;
        vector<int> res;
        bool alive=true;
        for(int i=0;i<asteroids.size();++i)
        {
            if(asteroids[i]>0){
                mystack.push(asteroids[i]);
            }
            else if(asteroids[i]<0)
            {
                if(mystack.empty()||mystack.top()<0)
                {
                    mystack.push(asteroids[i]);
                }
                else
                {
                    while(!mystack.empty())
                    {
                        int temp=mystack.top();
                        if(temp<0)
                        {
                            alive=false;
                            mystack.push(asteroids[i]);
                            break;
                        }
                        if(abs(asteroids[i])==temp)
                        {
                            alive=false;
                            mystack.pop();
                            break;
                        }
                        else if(abs(asteroids[i])>temp)
                        {
                            alive=true;
                            mystack.pop();
                            continue;
                        }
                        else if(abs(asteroids[i])<temp)
                        {
                            alive=false;
                            break;
                        }
                    }
                    if(alive)mystack.push(asteroids[i]);
                }
            }
        }
        while(!mystack.empty())
        {
            res.push_back(mystack.top());
            mystack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    vector<int> asteroids={-2,-2,1,-2};
    Solution s;
    vector<int> res=s.asteroidCollision(asteroids);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    return 0;
}