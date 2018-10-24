// lowbit 压缩行循环
#include <stdio.h>
#include <string.h>
#define maxn 50

int n;
int a[maxn];
int cvis[10][maxn];
int ans;

void dfs(int p) {
    if (p == n + 1) {
        ans++;
        return;
    }

    for (a[p] = 1; a[p] <= n; a[p]++) {

        if (cvis[1][a[p]] == 1)
            continue;
        if (cvis[2][a[p] + p] == 1)
            continue;
        if (cvis[3][a[p] + n - p] == 1)
            continue;

        cvis[1][a[p]] = 1;
        cvis[2][a[p] + p] = 1;
        cvis[3][a[p] + n - p] = 1;

        dfs(p + 1);

        cvis[3][a[p] + n - p] = 0;
        cvis[2][a[p] + p] = 0;
        cvis[1][a[p]] = 0;
    }
}

int main() {
    while (scanf("%d", &n) == 1) {
        ans = 0;
        dfs(1);
        printf("%d\n", ans);
    }

    return 0;
}