#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int ID[18];
    int count=17;
    for(int i=0;i<num;i++)
    {
       size_t id;
       cin>>id;
        size_t temp=id;
        while(count>=0)
        {
            if(temp>=10){
                ID[count]=temp%10;
                temp/=10;
            }
            else
            {
                ID[count]=temp;
            }
            count--;
        }
        int res=(ID[0]*7+ID[1]*9+ID[2]*10+ID[3]*5+ID[4]*8+ID[5]*4+ID[6]*2+ID[7]*1+ID[8]*6+ID[9]*3+ID[10]*7+ID[11]*9+ID[12]*10+ID[13]*5+ID[14]*8+ID[15]*4+ID[16]*2)%11;
    }
    return 0;
}