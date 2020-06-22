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
    string s, t, p;
    read(s, t, p);
    if((int)s.length() > (int)t.length()){
        cout << "NO\n";
        return;
    }
    if((int)s.length() + (int)p.length() < (int)t.length()){
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    for(int i = 0; i < (int)t.length() && cnt < (int)s.length(); ++i){
        if(t[i] == s[cnt]){
            cnt++;
        }
    }
    if(cnt != (int)s.length()){
        cout << "NO\n";
        return;
    }
    map<char, int> Mp;
    for(int i = 0; i < (int)t.length(); ++i){
        Mp[t[i]]++;
    }
    for(int i = 0; i < (int)s.length(); ++i){
        if(Mp.find(s[i]) == Mp.end()){
            cout << "NO\n";
            return;
        }
        Mp[s[i]]--;
        if(Mp[s[i]] == 0){
            Mp.erase(s[i]);
        }
    }
    for(int i = 0; i < (int) p.length(); ++i){
        if(Mp.find(p[i]) != Mp.end()){
            Mp[p[i]]--;
            if(Mp[p[i]] == 0){
                Mp.erase(p[i]);
            }
        }
    }
    if((int)Mp.size() == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }


}

int main() {
    fastIO;
//#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
#ifdef LOCAL
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif

    return 0;
}

