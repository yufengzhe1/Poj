#include <iostream>
using namespace std;

int ans=33;
int map[4][4];

void init ()
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
  {
    char c;
    cin>>c;
    if(c=='b') map[i][j]=1;//bÊÇ1£¬wÊÇ0
    else map[i][j]=0;
  }
}

void turn (int i,int j)
{
  if(i>=0&&i<=3&&j>=0&&j<=3)
  {
    if(map[i][j]==0)  map[i][j]=1;
    else map[i][j]=0;
  }
}

void flip(int position)
{
  int i=position/4;
  int j=position%4;
  turn(i,j);
  turn(i-1,j);
  turn(i+1,j);
  turn(i,j-1);
  turn(i,j+1);
}
int finished()
{
  int sum=0;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    sum+=map[i][j];
  if(sum%16)
    return 0;
  else return 1;
}


void dfs(int pos,int step) {
  if (finished())
   if (ans>step) {
   ans=step;
   return;
  }
  if (pos>=16)
   return;
  dfs(pos+1,step);
  flip(pos);
  dfs(pos+1,step+1);
  flip(pos);
}
int main ()
{
  init();
  dfs(0,0);
  if(ans==33)
    cout<<"Impossible";
  else cout<<ans;
  return 0;
}
