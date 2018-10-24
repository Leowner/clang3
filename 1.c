// memset 0x3f 1e9   0x7f inf  0xff -1 0x00 0
#include <stdio.h>
#include <string.h>
#define maxn 200


int n;
char s[maxn][maxn];
int sx, sy, tx, ty;
int dx[] = {0, -1, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 0};
int vis[maxn][maxn];
int xx, yy;

int min(int x, int y) {
    if (x < y) return x;
    return y;
}

int dfs(int x, int y) {
    // printf("<dfs %d %d> \n", x, y);
    if (x == tx && y == ty) return 0;
    vis[x][y] = 1;
    int tmp = n * n;
    for (int i = 1; i <= 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !vis[xx][yy] && s[xx][yy] != '#') {
            tmp = min(tmp, dfs(xx, yy) + 1);
        }
    }
    vis[x][y] = 0;
    return tmp;
} 

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
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
    int ans = dfs(sx, sy);
    printf("%d", ans);
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         printf("%c", s[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}