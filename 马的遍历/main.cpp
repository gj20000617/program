#include<bits/stdc++.h>
using namespace std;
struct queue_
{
    int x,y;//һ���ṹ�壬x��y�Ƕ��и�λ�÷ŵĵ��x��yֵ����ʵ�һ������ر𶮣��ṹ�������_(:�١���)_��
} que[160010];//����һ��Ҫע�������С����������RE�����Σ���
int head=0,tail=1,get[401][401],n,m,sx,sy;
int fx[16]={2,-2,2,-2,-1,1,-1,1},fy[16]={1,1,-1,-1,2,2,-2,-2};
int main()
{
    cin>>n>>m>>sx>>sy;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            get[i][j]=-1;//��ʼ��
    get[sx][sy]=0;//��һ�������
    que[1].x=sx;
    que[1].y=sy;
    while(head<tail)
    {
        head++;//ͷָ���1
        int s=get[que[head].x][que[head].y]+1;//���s��ָ��չ���µ�ʱ����Ҫ�����ٲ�����������һ����Ĳ�����1
        for(int i=0;i<8;++i)
        {
            int nx=que[head].x+fx[i],ny=que[head].y+fy[i];//��չ�µ�
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&get[nx][ny]==-1)//û�г������̲���û���߹�
            {
                tail++;
                que[tail].x=nx;
                que[tail].y=ny;//�µ����
                get[nx][ny]=s;//��ǵ���õ����С����
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
