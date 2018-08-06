#include <iostream>
using namespace std;

int handles[4][4]={0};

int main ()
{
   int step_num=0;
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
   {
     char ch;
     cin>>ch;
     if(ch=='+')   //输入+时，自增该位置与相应的行和列
     {
       handles[i][j]++;
       for(int k=0;k<4;k++)
       {
         handles[i][k]++;
         handles[k][j]++;
       }
     }
   }

   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)   //遍历数组
   {
     if(handles[i][j]%2)   //如果为基数，step_num加一
      step_num++;
   }
   cout<<step_num<<endl;    //输出步骤数
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
   {
     if(handles[i][j]%2)     //输出操作的的位置
      cout<<i+1<<' '<<j+1<<endl;
   }
}
