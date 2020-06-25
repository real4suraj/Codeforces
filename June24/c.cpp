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
    vector<string> s;
    for(int i = 0; i < n; ++i){
        string t;
        cin >> t;
        s.pb(t);
    }
    int x = -1, y = -1;
    for(int i = 1; i < n - 1; ++i){
        for(int j = 1; j < m - 1; ++j){
            if(s[i][j] != '*') continue;
            if(s[i][j - 1] != '*') continue;
            if(s[i][j + 1] != '*') continue;
            if(s[i - 1][j] != '*') continue;
            if(s[i + 1][j] != '*') continue;
            x = i, y = j;
        }
    }
    if(x < 0){
        cout << "NO\n";
        return;
    }
    vector<vector<int>> should(n, vector<int>(m, 0));
    should[x][y] = 1;
    int i,j;
    i = x - 1;
    while(i >= 0 && s[i][y] == '*') should[i][y] = 1, i--;
    i = x + 1;
    while(i < n && s[i][y] == '*')  should[i][y] = 1, i++;
    j = y - 1;
    while(j >= 0 && s[x][j] == '*') should[x][j] = 1, j--;
    j = y + 1;
    while(j < m && s[x][j] == '*')  should[x][j] = 1, j++;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '*' && !should[i][j]){
                //cout << i << " " << j << endl;
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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



