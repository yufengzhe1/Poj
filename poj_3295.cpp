
//题目链接：https://vjudge.net/problem/POJ-3295

#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

stack <int> a;
void push (char ch,int p,int q,int r,int s,int t)//压栈函数
{
  if (ch=='p')
    a.push(p);
  else if (ch=='q')
    a.push(q);
  else if (ch='r')
    a.push(r);
  else if (ch=='s')
    a.push(s);
  else if (ch=='t')
    a.push(t);
}

void logic (char ch)//逻辑判断
{
  int k1,k2;
  if (ch=='K')
  {
    k1=a.top();
    a.pop();
    k2=a.top();
    a.pop();
    if(k1==1&&k2==1)
      a.push(1);
    else a.push(0);
  }
  else if(ch=='A')
  {
    k1=a.top();
    a.pop();
    k2=a.top();
    a.pop();
    if(k1==1 || k2==1)
      a.push(1);
    else a.push (0);
  }
  else if (ch=='N')
  {
    k1=a.top();
    a.pop();
    k1=1-k1;
    a.push(k1);
  }
  else if (ch=='C')
  {
    k1=a.top();
    a.pop();
    k2=a.top();
    a.pop();
    if(k1==1&&k2==0)
      a.push(0);
    else a.push(1);
  }
  else if(ch=='E')
  {
    k1=a.top();
    a.pop();
    k2=a.top();
    a.pop();
    if(k1==k2)
      a.push(1);
    else a.push(0);
  }
}

int main ()
{
  int p,q,r,s,t;
  char str[200];
  while(cin>>str)
  {
    if(str[0]=='0')
      break;
    int num=0;   //计数变量
    for(p=0;p<2;p++)    //枚举32种情况
      for(q=0;q<2;q++)
        for(r=0;r<2;r++)
          for(s=0;s<2;s++)
           for (t=0;t<2;t++)
           {
             int l=strlen(str);
             int i;
             while(!a.empty())
             {
               a.pop();
             }
             for(i=l-1;i>=0;i--)
             {
               if(isupper(str[i]))  //大写字母时进行逻辑判断
               {
                 logic(str[i]);
               }
               else{push(str[i],p,q,r,s,t);}  //小写字母时进行压栈操作
             }
             num+=a.top();//计数
           }
   if(num==32)   //当32种情况全为真时输出 tautology
     cout<<"tautology"<<endl;
   else
     cout<<"not"<<endl;
  }
}




