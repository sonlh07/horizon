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
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL doubl e
#define EPS 1e-9
#define ll long long
using namespace std;
int n;
int a[N];

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n / 2; i++)
    if (i % 2 != 0) {
        swap(a[i], a[n - i + 1]);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    /**/ return 0;
}
