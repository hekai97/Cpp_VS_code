#include<iostream>
using namespace std;
class Solution
{
public:
    string ISBN(string isbn)
    {
        string res="";
        int temp=0;
        int p=1;
        int q;
        for(int i=0;i<11;i++)
        {
            if(isbn[i]!='-')
            {
                temp+=(isbn[i]-48)*p;
                p++;
            }
        }
        if(isbn[12]=='X')
        {
            q=10;
        }
        else
        {
            q=isbn[12]-48;
        }
        
        if(temp%11==q)
        {
            res="Right";
        }
        else if(temp%11!=10)
        {
            res=isbn;
            res.replace(12,12,to_string(temp%11));
        }
        else
        {
            res=isbn;
            res.replace(12,12,"X");
        }
        
        return res;
    }
};
int main()
{
    string s;
    Solution sol;
    cin>>s;
    cout<<sol.ISBN(s)<<endl;
    return 0;
}