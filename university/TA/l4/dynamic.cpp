#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef vector<vector<int>> Grid;

const int INF = 1e9;
int n, m, hr, hc, W;
Grid a, d, pr;

int id(int i, int j) { return i * W + j; }

void readInput() {
    fprintf(stderr, "Розміри схеми (рядків стовпців): ");
    scanf("%d %d", &n, &m);
    fprintf(stderr, "Будинок бабусі (рядок стовпець): ");
    scanf("%d %d", &hr, &hc);
    W = m + 1;
    a.assign(n + 1, vector<int>(m + 1, 0));
    fprintf(stderr, "Схема (%d рядків по %d чисел):\n", n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    fprintf(stderr, "\n");
}

void solveGirl() {
    d.assign(n + 1, vector<int>(m + 1, INF));
    pr.assign(n + 1, vector<int>(m + 1, -1));
    if (a[1][1]) d[1][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!a[i][j] || (i == 1 && j == 1)) continue;
            for (int k = 1; k <= 2; k++) {
                if (j - k >= 1 && d[i][j - k] + 1 < d[i][j]) d[i][j] = d[i][j - k] + 1, pr[i][j] = id(i, j - k);
                if (i - k >= 1 && d[i - k][j] + 1 < d[i][j]) d[i][j] = d[i - k][j] + 1, pr[i][j] = id(i - k, j);
            }
        }
}

vector<P> restorePath() {
    vector<P> g;
    for (int c = id(hr, hc); c != -1; c = pr[c / W][c % W]) g.push_back({c / W, c % W});
    reverse(g.begin(), g.end());
    return g;
}

void printGirl(const vector<P> &g) {
    printf("Шлях Червоної Шапочки - %d кроків\n", (int)g.size() - 1);
    for (size_t i = 0; i < g.size(); i++) printf("%s(%d,%d)", i ? "; " : "", g[i].first, g[i].second);
    puts("");
}

int solveWolf(const vector<P> &g, Grid &par, int &fin) {
    int T = 2 * (n + m) + 5;
    par.assign(T + 2, vector<int>(W * (n + 1), -1));
    auto co = [&](int t, int i, int j) { return t < (int)g.size() && g[t] == P(i, j); };
    if (a[1][1]) par[0][id(1, 1)] = id(1, 1);
    for (int t = 0; t <= T; t++) {
        if (par[t][id(hr, hc)] >= 0) { fin = id(hr, hc); return t; }
        for (int c = 0; c < (int)par[t].size(); c++) {
            if (par[t][c] < 0) continue;
            int i = c / W, j = c % W;
            if (co(t, i, j)) { if (par[t + 1][c] < 0) par[t + 1][c] = c; continue; }
            for (int k = 1; k <= 3; k++) {
                if (j + k <= m && a[i][j + k] && par[t + 1][id(i, j + k)] < 0) par[t + 1][id(i, j + k)] = c;
                if (i + k <= n && a[i + k][j] && par[t + 1][id(i + k, j)] < 0) par[t + 1][id(i + k, j)] = c;
            }
        }
    }
    return -1;
}

void printWolf(const Grid &par, int fin, int ft) {
    vector<int> seq(ft + 1);
    for (int t = ft, c = fin; t >= 0; t--) { seq[t] = c; c = par[t][c]; }
    int steps = 0;
    string s;
    for (int t = 0; t <= ft; t++) {
        char buf[32];
        sprintf(buf, "(%d,%d)", seq[t] / W, seq[t] % W);
        if (t == 0) s += buf;
        else if (seq[t] == seq[t - 1]) s += "+чекає";
        else s += string("; ") + buf, steps++;
    }
    printf("Шлях Сірого Вовка - %d кроків + %d раз(и) чекає\n%s\n", steps, ft - steps, s.c_str());
}

int main() {
    readInput();
    solveGirl();
    bool girlOk = a[hr][hc] && d[hr][hc] < INF;
    vector<P> g = {{1, 1}};
    if (girlOk) { g = restorePath(); printGirl(g); }
    else puts("Червона Шапочка дістатися не може");

    Grid par;
    int fin = -1, ft = solveWolf(g, par, fin);
    if (ft < 0) {
        puts("Сірий Вовк дістатися не може");
        if (girlOk) puts("Першою приходить Червона Шапочка");
        return 0;
    }
    printWolf(par, fin, ft);
    if (!girlOk || ft < d[hr][hc]) puts("Першим приходить Сірий Вовк");
    else puts("Червона Шапочка перша (Вовк при збігу чекає)");
}
