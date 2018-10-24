// 传参数时传二维数组要指定第二维长度
#include <stdio.h>
#include <string.h>
#define maxn 50050

int n;
int qx[maxn], qy[maxn];
int qfro, qend;
char s[200][200];
int ans[200][200];
int dx[] = {0, -1, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 0};
int sx, sy, tx, ty;
void push(int x, int y) {
    qend++;
    qx[qend] = x;
    qy[qend] = y; 
}
// int pop()

int bfs(int sx, int sy) {
    memset(ans, 0x3f, sizeof(ans));
    qfro = 0;
    qend = 1;
    qx[1] = sx, qy[1] = sy;
    ans[sx][sy] = 0;
    while (qfro <= qend) {

        // printf("<");
        // for (int i = qfro; i <= qend; i++) {
        //     printf("No.%d x:%d y:%d", i, qx[i], qy[i]);
        // }
        // printf(">\n");
        
        qfro++;
        int xx = qx[qfro];
        int yy = qy[qfro];
        for (int i = 1; i <= 4; i++) {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            if (ans[xxx][yyy] <= ans[xx][yy] + 1) continue;
            if (xxx > n || xxx < 1 || yyy > n || yyy < 1) continue;
            if (s[xxx][yyy] == '#') continue;
            push(xxx, yyy);
            ans[xxx][yyy] = ans[xx][yy] + 1;
        }
    } 
    if (ans[tx][ty] > 10000) return(-1);
    return (ans[tx][ty]);
}

int main () {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (s[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }

        printf("%d\n", bfs(sx, sy));
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) printf("%d ", ans[i][j]);
        //     printf("\n");
        // }
    }


    return 0;
}