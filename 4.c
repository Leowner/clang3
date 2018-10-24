#include<stdio.h>
#include<string.h>
#define maxn 600000
// #define base 10
#define mod 921017


int totbug = 0;
int tot = 0;    // data的总数
int hashmap[maxn];  // 每个hash值在data链表中的位置

int data[maxn];     // 每个data数组的状态
int datanext[maxn]; // data中每个项的下一项在data数组中的位置，用来模拟链表

int ans[maxn];  // 每个data数组中的下标的ans值
int q[maxn];
int qfro, qend;
int dx[] = {0, -1, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 0};
int tmp[20];
int vis[20];

void bfs(void) {
    while (qfro <= qend) {
        
    }
}

void dfs(int x, int cur) {
    if (x == 10) {
        int hashp = cur % mod;
        if (hashmap[hashp] != 0) {
            int q;
            for (q = hashmap[hashp]; datanext[q] != 0; q = datanext[q]) {

            }
            tot++;
            data[tot] = cur;
            datanext[q] = tot;
            return;
        } else {
            tot++;
            hashmap[hashp] = tot;
            data[tot] = cur;
            return;
        }
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

void push(int x) {
    qend++;
    q[qend] = x;
}

int pop(void) {
    return(q[qfro++]);
}

int getkey(int hashp, int cur) {        // 得到某个数值和其hash值所对应的序号
    for (int p = hashmap[hashp]; p != 0; p = datanext[p]) {
        if (data[p] == cur) return p;
    }
}



void sets(void) {                   // 处理初始值
    int hashp = 123456780 % mod;
    int sss = getkey(hashp, 123456780);
    qfro = 1;
    qend = 0;
    push(sss);
}

int main () {
    // int ans = 1;
    // for (int i = 1; i <= 9; i++) ans *= i;
    // printf("%d", ans);
    hash_pre();
    // int tothash = 0;
    // for (int i = 1; i < 1000000; i++) {
    //     if (hashmap[i] != 0) tothash++;
    // }
    // printf("%d   %d", tothash, totbug);
    // printf("%d", tot);

    bfs();
    return 0;
}