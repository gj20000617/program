#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t 100
int main()
{
    int N,a[t]={0},MAX,c1,c2,C,i,m;
    char b[t];
    printf("请输入快递总数：\n");
    scanf("%d",&N);
    printf("请输入快递路线：\n");
    for(i=1;i<N*2;i=i+2){
        scanf("%d%d",&a[i],&a[i+1]);
    }

    getchar();
    printf("请输入快递网络信息：\n");
    gets(b);

    char *p,*s;
    s=b;
    p=s;
    while (*p!='\0'){
        if ( *p!=' ')
        *s++=*p;
        p++;
    }
    *s='\0';

    i=0;m=0;
    for (i=0;b[i]!='\0';i++){
        if(b[i]!=' ') b[m++]=b[i];
    }

    MAX=0;
    for(i=1;i<N*2;i=i+2){

        for(m=0;b[m]!='\0';m=m+1){
            if ((a[i]==b[m]-'0')) c1=m;
            if ((a[i+1]==b[m]-'0')) c2=m;
        }
        if (c1<c2) C=c2-c1;
            else C=strlen(b)-c1+c2;

        if (C>MAX) MAX=C;
    }

    printf("最长运输时间为：%d\n",MAX);
    system("pause");
    return(0);
}


