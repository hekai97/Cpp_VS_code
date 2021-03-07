#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string Decrypt(string ciphertext,string key){
        int nkey=key.size();
        vector<int> keys;
        string res="";
        for(auto& ch:key)
        {
            if(isupper(ch)){
                ch=tolower(ch);
            }
            keys.push_back(ch-97);
        }
        for(int i=0;i<ciphertext.size();++i)
        {
            int temp=ciphertext[i]-keys[i%nkey];
            if(islower(ciphertext[i]))
            {
                if(temp<97)
                {
                    temp=ciphertext[i]+26-keys[i%nkey];
                }
            }
            else if(isupper(ciphertext[i])){
                if(temp<65)
                {
                    temp=ciphertext[i]+26-keys[i%nkey];
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
int main()
{
    string key,ciphertext;
    cin>>key>>ciphertext;
    Solution s;
    string plaintext=s.Decrypt(ciphertext,key);
    cout<<plaintext;
    return 0;
}