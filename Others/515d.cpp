#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
 
typedef pair <int, int> P;
int n, m, re[maxn][maxn];
int nx[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char ch[maxn][maxn];
void init()
{
    memset(re, 0, sizeof(re));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 4; k++)
    {
        int tx = i + nx[k][0], ty = j + nx[k][1];
        if(tx >= 0 && tx < n && ty >= 0 && ty < m && ch[tx][ty] == '.')
            re[i][j]++;
    }
}
 
void tosort()
{
    queue <P> que;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(re[i][j] == 1 && ch[i][j] == '.')
        {
            P a; a.first = i; a.second = j;
            que.push(a);
        }
    }
 
    while(!que.empty())
    {
        P a = que.front(); que.pop();
        for(int i = 0; i < 4; i++)
        {
            int tx = a.first + nx[i][0], ty = a.second + nx[i][1];
 
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && ch[tx][ty] == '.')
            {
//                cout<<"tx = "<<tx<<"ty = "<<ty<<endl;
                for(int j = 0; j < 4; j++)
                {
                    int dx = tx + nx[j][0], dy = ty + nx[j][1];
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m && (--re[dx][dy] == 1) && ch[dx][dy] == '.')
                    {
                        P b; b.first = dx; b.second = dy;
                        que.push(b);
                    }
                }
                if(nx[i][0] == 0 && nx[i][1] == 1)
                {
                    ch[a.first][a.second] = '<';
                    ch[tx][ty] = '>';
                }
                if(nx[i][0] == 0 && nx[i][1] == -1)
                {
                    ch[a.first][a.second] = '>';
                    ch[tx][ty] = '<';
                }
                if(nx[i][0] == -1 && nx[i][1] == 0)
                {
                    ch[a.first][a.second] = 'v';
                    ch[tx][ty] = '^';
                }
                if(nx[i][0] == 1 && nx[i][1] == 0)
                {
                    ch[a.first][a.second] = '^';
                    ch[tx][ty] = 'v';
                }
                break;
            }
        }
    }
    int flag = 0;
     for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(ch[i][j] == '.')
            {
//                printf("ch[i][j] = ");
//                cout<<"i = "<<i<<"j = "<<j<<" = ";
//                cout<<ch[i][j]<<endl;
                printf("Not unique\n");
                flag = 1;
                return;
            }
        }
 
//    cout<<"--------"<<endl;
    for(int i = 0; i < n; i++)
        printf("%s\n", ch[i]);
 
}
 
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%s", ch[i]);
//        for(int i = 0; i < n; i++)
//            printf("%s\n",ch[i]);
//        printf("\n");
        init();
        tosort();
    }
    return 0;
}