//+LNCT++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+------------------Lord Escanor : Sin Of Pride----------------------+//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++BHOPAL+//

#include <bits/stdc++.h>

#define fo(i, n) for (int i = 0; i < int(n); i++)
#define of(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define Fo(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

#define endl '\n'
#define deb(x) cout << #x << " " << x << endl;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}
template<typename... T>
void write(T&&... args) {
    ((cout << args << " "), ...);
}

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

void solve() {
    int n, m;
    read(n, m);
    ll r_mx, c_mn, x, r_mx2, r_sm, c_sm, res;
    r_mx = 0, r_mx2 = 0, r_sm = 0;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(r_mx <= x){
            r_mx2 = r_mx;
            r_mx = x;
        }
        else if(r_mx2 <= x){
            r_mx2 = x;
        }
        r_sm += x;
    }
    c_mn = INF;
    c_sm = 0;
    for(int i = 0; i < m; ++i){
        cin >> x;
        if(c_mn >= x){
            c_mn = x;
        }
        c_sm += x;
    }
    if(r_mx > c_mn){
        cout <<"-1\n";
        return;
    }
    res = r_sm * (ll)m;
    res += c_sm;
    res -= r_mx * (ll)m;
    if(r_mx < c_mn) res += r_mx - r_mx2;
    cout << res << endl;
    return;
}

int main() {
    fastIO;
//#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
#ifdef LOCAL
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif

    return 0;
}



