#include<stdio.h>
#include<string.h>
#define maxn 1000000
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
int bas10[] = {0, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
int a[10][10];
int vis[20];

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
    memset(ans, 0x3f, sizeof(ans));
    ans[sss] = 0;
}

void bfs(void) {
    while (qfro <= qend) {
        int q = pop();
        int qkey = data[q];

        // printf("%d\n", qkey);

        int sx, sy, st;
        for (int i = 9; i >= 1; i--) {
            int xx = (i - 1) / 3 + 1;
            int yy = (i - 1) % 3 + 1;
            a[xx][yy] = qkey % 10;
            if (a[xx][yy] == 0) {
                sx = xx;
                sy = yy;
            }
            qkey /= 10;
        }
        st = (sx - 1) * 3 + sy;
        for (int i = 1; i <= 4; i++) {
            int xx = sx + dx[i];
            int yy = sy + dy[i];
            if (xx < 1 || xx > 3 || yy < 1 || yy > 3) continue;
            int tt = (xx - 1) * 3 + yy;
            int qkey = data[q];
            qkey = qkey - a[xx][yy] * bas10[tt] + a[xx][yy] * bas10[st];
            int qmod = qkey % mod;
            int qno = getkey(qmod, qkey);
            if (ans[qno] > ans[q] + 1) {
                ans[qno] = ans[q] + 1;
                push(qno);
            }
        }
    }
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
    sets();
    bfs();
    int T;
    scanf("%d", &T);
    int n, na;
    for (int i = 1; i <= T; i++) {
        n = 0;
        for (int i = 1; i <= 9; i++) {
            scanf("%d", &na);
            n *= 10;
            n += na;
        }
        int nmod = n % mod;
        int nkey = getkey(nmod, n);
        int ansppp = ans[nkey];
        if (ansppp == 1061109567) ansppp = -1;
        printf("Case #%d:%d\n", i, ansppp);
        // printf("%d", n);

    }
    return 0;
}