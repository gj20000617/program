#include<bits/stdc++.h>
using namespace std;
struct queue_
{
    int x,y;//一个结构体，x，y是队列该位置放的点的x，y值（其实我还不是特别懂，结构体的意义_(:з」∠)_）
} que[160010];//这里一定要注意数组大小，我在这里RE了两次！！
int head=0,tail=1,get[401][401],n,m,sx,sy;
int fx[16]={2,-2,2,-2,-1,1,-1,1},fy[16]={1,1,-1,-1,2,2,-2,-2};
int main()
{
    cin>>n>>m>>sx>>sy;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            get[i][j]=-1;//初始化
    get[sx][sy]=0;//第一个点入队
    que[1].x=sx;
    que[1].y=sy;
    while(head<tail)
    {
        head++;//头指针加1
        int s=get[que[head].x][que[head].y]+1;//这个s是指扩展到新点时所需要的最少步数，就是上一个点的步数加1
        for(int i=0;i<8;++i)
        {
            int nx=que[head].x+fx[i],ny=que[head].y+fy[i];//扩展新点
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&get[nx][ny]==-1)//没有超出棋盘并且没有走过
            {
                tail++;
                que[tail].x=nx;
                que[tail].y=ny;//新点入队
                get[nx][ny]=s;//标记到达该点的最小步数
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            printf("%-5d", get[i][j]);
        cout<<endl;
    }
    system("pause");
    return 0;
}
