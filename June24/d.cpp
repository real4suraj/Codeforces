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

int n;
string s;

string sum(string &s, string &t){
    vi ans(max((int)s.size(), (int)t.size()) + 1, 0);
    for(int i = (int)s.size() - 1; i >= 0; --i) ans[(int)s.size() - 1 - i] += s[i] - '0';
    for(int i = (int)t.size() - 1; i >= 0; --i) ans[(int)t.size() - 1 - i] += t[i] - '0';
    int p = 0;
    for(int i = 0; i < (int)ans.size(); ++i){
        int dig = (p + ans[i]) % 10;
        p = (p + ans[i]) / 10;
        ans[i] = dig;
    }
    while(ans.back() == 0){
        ans.pop_back();
    }
    string u = "";
    while(!ans.empty()){
        u += (char)('0' + ans.back());
        ans.pop_back();
    }
    return u;
}

string gett(int i){
    string s1 = "";
    for(int x = 0; x < i; ++x) s1 += s[x];
    string s2 = "";
    for(int x = i; x < n; ++x) s2 += s[x];

    return sum(s1, s2);
 }

bool cmp(string &a, string &b){
    if((int)a.size() != (int)b.size()) return (int) a.size() < (int) b.size();
    return (a < b);
}
void solve() {
    cin >> n >> s;
    vi maybe;
    int k = 0;
    for(int i = n / 2; i < n && k < 3; ++i) if(s[i] != '0') maybe.pb(i), k++;
    k = 0;
    for(int i = n / 2; i >= 1 && k < 3; --i) if(s[i] != '0') maybe.pb(i), k++;

    vector<string> v;
    for(int i : maybe) v.pb(gett(i));
    sort(all(v), cmp);
    cout << v[0];
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



