
#include<stdio.h>

int catdog(int m,int n)
{

    int s;
    if(n==m)
    {
        s=1;
    }
    if((n+1)==m)
    {
        s=1;
    }
    if(m==2*n)
    {
        s=n;
    }
    if(m>2*n)
    {
        s=-1;
    }
    if((m<2*n)&&(m!=n))
    {
        s=m-n;
    }
    return s;

}

int main()
{

    int n,m,s,t;
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        t=n;
        n=m;
        m=t;
    }
    s=catdog(m,n);
    printf("%d",s);
}