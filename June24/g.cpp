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
    int n, q;
    read(n, q);
    deque<int> d;
    int mx_val = -1;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        d.pb(a);
        mx_val = max(mx_val, a);
    }
    map<int, pair<int, int>> ans;
    int mx_idx = 0;
    while(true){
        int first = d.front();
        d.pop_front();
        int second = d.front();
        d.pop_front();

        if(first == mx_val){
            d.push_front(second);
            d.push_front(first);
            break;
        }
        mx_idx++;
        ans[mx_idx] = {first, second};

        if(second > first){
            swap(first, second);
        }
        d.push_front(first);
        d.push_back(second);
    }

    vi a(n);
    for(int i = 0; i < n; ++i){
        a[i] = d.front();
        d.pop_front();
    }
    for(int i = 0; i < q; ++i){
        ll m;
        cin >> m;
        if(m <= mx_idx){
            cout << ans[m].first << " " << ans[m].second << endl;
        }
        else{
            cout << mx_val << " " << a[(m - (mx_idx + 1)) % (n - 1) + 1] << endl;
        }
    }
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



