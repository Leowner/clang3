#include<stdio.h>
#include<string.h>
#define maxn 600000
// #define base 10
#define mod 921017


int totbug = 0;
int tot = 0;
int hashmap[maxn];  // 每个hash值在data链表中的位置

int data[maxn];
int datanext[maxn] // data中每个项的下一项在data数组中的位置，用来模拟链表

int ans[maxn];  // 每个data数组中的下标的ans值
int q[maxn];
int qfro, qend;
int dx[] = {0, -1, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 0};
int tmp[20];
int vis[20];


void dfs(int x, int cur) {
    if (x == 9) {
        int hashp = cur % mod;
        if (hashmap[hashp] != 0) totbug++;
        hashmap[hashp] = cur;
        return;
    }
    for (int i = 0; i <= 8; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(x + 1, cur * 10 + i);
        vis[i] = 0;
    }

}

void hash_pre(void) {
    int hash = 0;
    memset(vis, 0, sizeof(vis));
    dfs(1, 0);

}

int main () {
    // int ans = 1;
    // for (int i = 1; i <= 9; i++) ans *= i;
    // printf("%d", ans);
    hash_pre();
    int tothash = 0;
    for (int i = 1; i < 1000000; i++) {
        if (hashmap[i] != 0) tothash++;
    }
    printf("%d   %d", tothash, totbug);


    return 0;
}