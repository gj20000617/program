#include <bits/stdc++.h>
using namespace std;
int a[32][32],b[32][32];
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};//第一个表示不动，是充数的，后面的四个分别是上下左右四个方向（总之就是上下左右走的表示，和01迷宫的做法一样）
int n,i,j;
void dfs(int p,int q){
    int i;
    if (p<0||p>n+1||q<0||q>n+1||a[p][q]!=0) return;//如果搜过头或者已经被搜过了或者本来就是墙的就往回
    a[p][q]=1;//染色
    for (i=1;i<=4;i++) dfs(p+dx[i],q+dy[i]);//向四个方向搜索（似乎是，在外面加了一圈0后，就可以把外面的全部连起来，然后一起染色成1了）
}
int main(){
    cin>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            cin>>b[i][j];
            if (b[i][j]==0) a[i][j]=0;
            else a[i][j]=2;
        }
    dfs(0,0);//搜索 从0，0开始搜（在外面加了一圈0）
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++)
        if (a[i][j]==0) cout<<2<<' ';//如果染过色以后i，j那个地方还是0，说明没有搜到，就是周围有墙，当然就是被围住了，然后输出2
        else cout<<b[i][j]<<' ';//因为被染色了，本来没有被围住的水和墙都染成了1，所以就输出b[i][j]
        cout<<'\n';//换行
    }
    system("pause");
}
