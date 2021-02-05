#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(vector<int> a,vector<int>b)
{
    if(a[4]>b[4])return true;
    else if(a[4]<b[4])return false;
    else
    {
        if(a[1]>b[1])
        {
            return true;
        }
        else if(a[1]<b[1])
        {
            return false;
        }
        else
        {
            if(a[0]<b[0])
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        
    }
}
int main()
{
    vector<vector<int> > grades;
    int n;
    int chinese;
    int math;
    int english;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        cin>>chinese>>math>>english;
        temp.push_back(i+1);
        temp.push_back(chinese);
        temp.push_back(math);
        temp.push_back(english);
        temp.push_back(chinese+math+english);
        grades.push_back(temp);
    }
    sort(grades.begin(),grades.end(),cmp);
    for(int i=0;i<5;i++)
    {
        cout<<grades[i][0]<<" "<<grades[i][4]<<endl;
    }
    return 0;
}