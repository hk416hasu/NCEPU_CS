#include<iostream>
#include<algorithm>
#define MAX 200
#define INF 0x7fffffff
using namespace std;

int m[MAX+1][MAX+1][2];
int v[MAX+1];
int out[MAX+1];
char op[MAX+1];
int ans=-INF;
int minf,maxf;
int n;
void MinMax(int i,int s,int j)
{
    int e[5];
    int a=m[i][s][0];
    int b=m[i][s][1];
    int r=(i+s-1)%n+1;//多边形的实际顶点编号
    int c=m[r][j-s][0];
    int d=m[r][j-s][1];
    if(op[r]=='t')
    {
        minf=a+c;
        maxf=b+d;
    }
    else
    {
        e[1]=a*c;
        e[2]=a*d;
        e[3]=b*c;
        e[4]=d*b;
        minf=e[1];
        maxf=e[1];
        for(int k=2; k<5; k++)
        {
            maxf=max(maxf,e[k]);
            minf=min(minf,e[k]);
        }
    }
}

int main()
{
    scanf("%d",&n);
    getchar();
    for(int i=1; i<=n; i++)
    {
        scanf("%c %d",&op[i],&v[i]);
        m[i][1][1]=v[i];
        m[i][1][0]=v[i];
        getchar();
    }
    for(int j=2; j<=n; j++)//迭代链的长度
    {
        for(int i=1; i<=n; i++) //迭代首次删掉的边
        {
            for(int s=1; s<j; s++) //迭代断开位置
            {
                MinMax(i,s,j);
                if(s==1)
                {
                    m[i][j][0]=minf;
                    m[i][j][1]=maxf;
                }
                else
                {
                    m[i][j][1]=max(maxf,m[i][j][1]);
                    m[i][j][0]=min(minf,m[i][j][0]);
                }
            }

        }
    }
    int i;
    int cnt=0;
    for(i=1; i<=n; i++)
    {
        if(m[i][n][1]>ans)
        {
            ans=m[i][n][1];
        }
    }
    for(i=1; i<=n; i++)
    {
        if(m[i][n][1]==ans)
        {
            cnt++;
            out[cnt]=i;
        }
    }
    printf("%d\n",ans);
    for(i=1; i<cnt; i++)
    {
        printf("%d ",out[i]);
    }
    printf("%d\n",out[i]);
    return 0;
}

// 4
// t -7 t 4 x 2 x 5