#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, k;
int c[N];
int lab[N];
vector <int> st[N];
bool f[N];
int id[N];

int get(int u) {
    if (lab[u] < 0) return u;
    lab[u] = get(lab[u]);
    return lab[u];
}

void uni(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] < lab[r2]) {
        lab[r2] = r1;
        lab[r1] = x;
    }
    else {
        lab[r2] = x;
        lab[r1] = r2;
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int r1 = get(u);
        int r2 = get(v);
        f[u] = true;
        f[v] = true;
        if (r1 != r2) {
            uni(r1, r2);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    if (f[i] && lab[i] < 0) {
        id[i] = ++cnt;
    }

    for (int i = 1; i <= n; i++)
    if (f[i]) {
        int root = id[get(i)];
        st[root].pb(c[i]);
    }

    int ret = 0;
    for (int i = 1; i <= cnt; i++) {
        //cout << "group : " << i << "\n";

        vector <int> tmp;
        for (int j = 0; j < st[i].size(); j++) {
            tmp.pb(st[i][j]);
         //   cout << st[i][j] << "\n";
        }

        int ans = 0;
        int last = 0;

        sort(tmp.begin(), tmp.end());
        tmp.pb(-1);
        for (int j = 0; j < tmp.size() - 1; j++)
        if (tmp[j] != tmp[j + 1]) {
            ans = max(ans, j - last + 1);
            last = j + 1;
        }
        ret += (st[i].size() - ans);
    }

    cout << ret;
    /**/ return 0;
}
