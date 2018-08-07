/*假设陆地的海岸线是一条无限延长的直线，海岛是一个个的点，
现需要在海岸线上安装雷达，使整个雷达系统能够覆盖到所有的海
岛。雷达所能覆盖的区域是以雷达为圆心半径为d的圆，我们用指标
坐标系来描述，海岸线就是x轴，现在给出每个海岛的坐标与雷达的
半径d，请编写一个程序计算出最少需要多少个雷达才能够将所有海
岛全部覆盖？

输入：
输入将会有多组数据，每组数据第一行为n (1<=n<=1000)，d，n为海
岛个数，d为雷达半径，接下来n行，每行两个数描述海岛坐标。
以n==0，d==0表示输入结束

输出：
每组数据对应一行，输出最少需要的雷达个数，如果不能满足，
则输出-1，具体格式见样例。

样例输入：
3 2
1 2
-3 1
2 1

1 2
0 2

0 0

样例输出：
Case 1: 2
Case 2: 1

解题思路：
	  首先可以明确的是：只要存在任意一个海岛位置超出雷达最大覆盖半径（即y>d），则无解.
	  在所有海岛的 y<=d 的前提下去思考此问题，
	  那么此问题的切入点是需要知道【一个雷达要覆盖一个海岛，其可以安装范围是多少】
	  以海岛坐标(x,y)为圆心，用雷达覆盖半径d画圆，根据前提条件可知，
	  这个圆与x轴必定存在最少1个(y=d)、最多2个交点(y<d).
	  可以认为1个交点是2个交点重合的特殊情况，那么这2个交点在x轴上构成的线性区间，
	  可以看作海岛的被覆盖范围在x轴上的投影 (由此就可以把二维的几何问题转化成一维几何问题)
	  按照所有海岛的x轴坐标，从小到大依次计算每个海岛在x轴上的投影区间（投影可能存在重叠），
	  同时把每个雷达抽象成1个点，那么此问题就转化成：
	  【已知x轴上若干个区间（可能存在交集），现在要往这些区间内放若干个点，
	  问怎样放置这些点，使得每个区间内至少存在一个点，且所放置的点的总量尽可能最少】


	  可使用贪心算法求解：
	    根据每个区间的左端点坐标对所有区间从左到右排序:
		① 在左起第一个区间A 的右端点 A.R 放置一个点，总放置点数 P+1
		② 若下一个区间B 的左端点 B.L > A.R,
		    说明 区间A 与 区间B 无交集，此时在区间B 的右端点 B.R 放置一个点，总放置点数 P+1
		   否则说明 区间A 与 区间B 相交, 此时进一步判断，若 B.R < A.R，
			说明 区间B 在 区间A 的内部，此时把原本放置在 A.R 的点移动到 B.R（确保区间B有一个点），总放置点数不变
		③ 重复这个过程直到所有区间被遍历完成*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Island
{
  double x,y;//岛屿坐标
  double left;//左端点的x坐标
  double right;//右端点的x坐标
};

bool compare (Island a,Island b)
{
  return a.left<=b.left;
}

int main ()
{
  int n,d;
  static int Case=0;
  while((cin>>n>>d)&&n&&d)
  {
    bool isSolvable=true;//是否可解
    Island island[1000];
    for(int i=0;i<n;i++)
    {
      cin>>island[i].x>>island[i].y;
      if (island[i].y>d) isSolvable=false; //y坐标大于雷达半径时不可解
      island[i].left=island[i].x-sqrt(d*d-island[i].y*island[i].y);
      island[i].right=island[i].x+sqrt(d*d-island[i].y*island[i].y);
    }
    sort(island,island+n,compare);//将左端点x轴坐标从小到大排序
    int min_num=1;
    double right=island[0].right;
    for(int j=1;j<n;j++)
    {
      if (right<island[j].left) {min_num++;right=island[j].right;}//若下一个区间B 的左端点 B.L > A.R,加一
      else if(right>island[j].right) right=island[j].right;
      else {}
    }
    if(!isSolvable)
      cout<<"Case "<<++Case<<": "<<-1<<endl;
    else
      cout<<"Case "<<++Case<<": "<<min_num<<endl;
  }
  return 0;
}

