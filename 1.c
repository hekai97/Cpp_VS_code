#include <stdio.h>
int main()
{
 int a[100100]={0};
 int i, j, n;
 for(i=j=2;i<100100;) //打表：把所有可能的情况的结果都求出来，并存在数组里
  {
   if(j%2!=0)
   {
    j=j*3+1;
    a[i]++;
   }
   else
   {
    j=j/2;
    a[i]++;
    if(j==1)
    {
    i++;
    j=i;
    }
   }
  } 

  

     while(scanf("%d", &n)!=EOF)

  { 

   for(i=2;;i++)   //从小到大，把最小的那个i输出出来

   {

    if(a[i]==n)

    break;

   }

  printf("%d\n", i);

  }

 return 0;

}