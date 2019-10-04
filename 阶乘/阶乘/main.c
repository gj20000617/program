#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x;
    double sum=1;
    printf("Please input data£º\n");
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        sum=sum*i;
    }
    printf("%d!=%lf\n",x,sum);
    system("pause");
    return 0;
}
