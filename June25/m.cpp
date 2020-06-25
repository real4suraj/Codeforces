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
    string s;
    cin >> s;
    int n = sz(s);
    char ans[s.length()+3];
    bool f = 1;
    for(char c : s) f &= (c == '9');
    if(f){
        ans[0] = '1';
        for(int i = 0; i < n; ++i) ans[i + 1] = '0';
        ans[n] = '1';
        ans[n + 1] = '\0';
        cout << ans << endl;
        return;
    }
    int i = n / 2;
    int j = i;
    if(n & 1 ^ 1) i--;
    while(i >= 0 && s[i] == s[j]) i--, j++;
    if(i < 0 || s[i] < s[j]){
        i = n / 2;
        j = i;
        if(n & 1 ^ 1) i--;
        int c = 1;
        while(i >= 0){
            int dig = ((s[i] - '0') + c);
            c = dig / 10;
            s[i] = (dig % 10) + '0';
            s[j] = s[i];
            i--, j++;
        }
    }
    else {
        while(i >= 0){
            s[j] = s[i];
            i--, j++;
        }
    }
    cout << s << endl;

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



