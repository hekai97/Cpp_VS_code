#include<iostream>
#include <stdlib.h>
using namespace std;
int a[1000005];
bool sub[1000005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int t=abs(a[i]-a[j]);
            sub[t]=1;
        }
    }
    int k=n;
    while(1){
        if(sub[k]==0){
        cout<<k;
        return 0;
        }
    k++;
    }
    return 0;
}