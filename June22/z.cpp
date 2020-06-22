//Lord Escanor : Sin Of Pride
//When I was writing this, only God and I knew what the code meant,
//But now, only God knows.
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
    string a, b, c;
    read(a, b, c);
    int reqk = 3, reqs = 3;
    map<string, int> Mp;
    Mp[a]++;
    Mp[b]++;
    Mp[c]++;
    for(auto x : Mp){
        reqk = min(reqk, 3 - x.y);
    }
    map<char, vector<int>> Mp2;
    Mp2[a[1]].pb(a[0] - '0');
    Mp2[b[1]].pb(b[0] - '0');
    Mp2[c[1]].pb(c[0] - '0');
    for(auto x : Mp2){
        vi y = x.y;
        sort(all(y));
        int cnt = 1;
        for(int i = 1; i < sz(y); ++i){
            if(y[i] == y[i - 1] + 1) cnt++;
        }
        for(int i = 1; i < sz(y); ++i){
            if(y[i] - y[i - 1] == 2) cnt = max(cnt,2);
        }
       reqs = min(reqs, 3 - cnt);
    }
    cout << min(reqk, reqs) << endl;
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

