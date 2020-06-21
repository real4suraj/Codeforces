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
    ll n;
    cin >> n;
    vector<ll> div;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            div.emplace_back(i);
            if(n / i != i) div.emplace_back(n / i);
        }
    }
    sort(all(div));
    for(auto e : div){
        ll val = n;
        while(val % e == 0) val /= e;
        if(val == 1){
            cout << e << endl;
            return;
        }
        else {
            break;
        }
    }
    if(div.size() == 0){
        cout << n << endl;
        return;
    }
    if(div.size() > 1){
        int o = 0, ev = 0;
        for(auto e : div) if(e & 1) o++; else ev++;
        if(o && ev){
            cout << 1 << endl;
            return;
        }
        else {
            if(ev != 0){
                cout << 2 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
    }
    else{
        cout << div[0] << endl;
    }

}

int main() {
    fastIO;
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif

    return 0;
}

