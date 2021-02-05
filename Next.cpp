#include<iostream>
#include<vector>
const int MaxSize=100;
using namespace std;
class SqString{
    public:
    char data[MaxSize];
    int length;
    void StrAssign(SqString& s,char cstr[]){
        int i;
        for(i=0;cstr[i]!='\0';i++){
            s.data[i]=cstr[i];
        }
        s.length=i;
    }
    void GetNext(SqString t,int next[]){
        int j,k;
        j=0;
        k=-1;
        next[0]=-1;
        while(j<t.length-1){
            if(k==-1||t.data[j]==t.data[k]){
                j++;
                k++;
                next[j]=k;
            }
            else
            {
                k=next[k];
            }
        }
    }
    int KMP(SqString s,SqString t){
        int next[MaxSize],i=0,j=0;
        GetNext(t,next);
        while(i<s.length && j<t.length){
            if(j==-1||s.data[i]==t.data[j]){
                i++;
                j++;
            }
            else
            {
                j=next[j];
            }
        }
        if(j>=t.length){
            return (i-t.length+1);
        }
        else
        {
            return -1;
        }
        return 0;
    }
    void GetNextval(SqString t,int nextval[]){
        int j=0,k=-1;
        nextval[0]=-1;
        while(j<t.length){
            if(k==-1||t.data[j]==t.data[k]){
                j++;
                k++;
                if(t.data[j]!=t.data[k]){
                    nextval[j]=k;
                }
                else
                {
                    nextval[j]=nextval[k];
                }
            }
            else
            {
                k=nextval[k];
            }
            
        }
    }
};
int main(){
    /*SqString s;
    SqString t;
    int next[MaxSize];
    char sch[MaxSize]={'a','b','a','a','b','c','a','c'};
    char tch[MaxSize]={'a','b','c'};
    s.StrAssign(s,sch);
    t.StrAssign(t,tch);
    //s.GetNext(s,next);
    int res=s.KMP(s,t);
    cout<<res;*/
    SqString s;
    int next[MaxSize];
    int nextval[MaxSize];
    char ch[MaxSize]={'a','d','a','b','b','a','d','a','d','a'};
    s.StrAssign(s,ch);
    s.GetNext(s,next);
    s.GetNextval(s,nextval);
    for(int i=0;i<s.length;i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<s.length;i++){
        cout<<nextval[i]<<" ";
    }
    return 0;
}