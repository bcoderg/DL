#include <bits/stdc++.h>
using namespace std;
#define int long long
#define se set<int> s
#define ve vector<int> v;
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long int
#define f float
#define d double
#define pb push_back
#define mii map<int, int>
#define msi map<string, int>
#define mci map<char, int>
#define all(p) (p).begin(), (p).end()
#define allr(p) (p).rbegin(), (p).rend()
#define vvi vector<vector<int>>
#define print(v)                                                               \
  for (auto &x : v) {                                                          \
    cout << x << " ";                                                          \
  }                                                                            \
  cout << "\n";
#define nl "\n";
const int N = 0;

void badhri() {
  int n;
  cin >> n;
  ve
      // int b[n];
      for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    v.pb(p);
  }

  vector<int> dp(n, -1);

  dp[0] = v[0];
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= i + 2; j++) {
      dp[i] = min(dp[i], abs(dp[i - 1] - v[j]));
    }
  }

  cout << dp[n - 1];

  // cout<<nl;
}

signed main() {

  fast int t = 1;

  // cin>>t;

  while (t--) {
    badhri();
  }
}