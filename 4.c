#include<stdio.h>
#include<string.h>
#define maxn 400040

int tot = 0;
int a[maxn];
int ans[maxn];
int q[maxn];
int qfro, qend;
int dx[] = {0, -1, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 0};
int tmp[20];

void push_val(int val) {
    qend++;
    tot++;
    a[tot] = val;
    q[qend] = tot;
}
void change(int x) {
    int val = a[x];
    int ti;
    for (ti = 9; ti >= 1; ti--) {
        a[10 - ti] = val % 10;
        if (val % 10 == 0) break;
        val /= 10;
    }
    int tx = (ti - 1) / 3 + 1;
    int ty = (ti - 1) % 3 + 1;
    for (int i = 1; i <= 4; i++) {
        int xx = tx + dx[i];
        int yy = ty + dy[i];
        if (xx < 1 || xx > 3 || yy < 1 || yy > 3) continue;

    }

} 
void bfs(void) {
    while (qfro <= qend) {
        qfro++;
        change(q[qfro]);
    }
}

int main () {
    // int ans = 1;
    // for (int i = 1; i <= 9; i++) ans *= i;
    // printf("%d", ans);
    a[1] = 123456780;
    qfro = 0;
    qend = 1;
    q[1] = 1;
    bfs();


    return 0;
}