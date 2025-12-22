
can pick an item any no.of times

    if (v[i - 1] <= j) {
  dp[i - 1][j], dp[i][j - v[i - 1]] // stay at same index i , after pick as well
}
else {
  dp[i][j] = dp[i - 1][j];
}

// Rod Cutting problem
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

int cutRod(int price[], int n) {
  // code here
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i <= j) {
        // max of cut , not cut
        // if cut: add price (i.e profit)   , reduce that length can still stay
        // at same index if not cut: same as prev index value
        dp[i][j] = max(dp[i][j - i] + price[i - 1], dp[i - 1][j]);
        // if given lengths ===> length[i]
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][n];
}

// if given lengths ===> lenght[i]
int len[n], price[n];
// dp[n+1][length+1]     //length can ve different from n as well
int dp[n + 1][n + 1];
memset(dp, 0, sizeof(dp));

for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= n; j++) {
    if (len[i - 1] <= j) {
      dp[i][j] = max(dp[i][j - len[i - 1]] + price[i - 1], dp[i - 1][j]);
    } else {
      dp[i][j] = dp[i - 1][j];
    }
  }
}

// Coin change
max no.of ways

int coins[n];
int sum = 0;
vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

for (int i = 0; i <= n; i++)
  dp[i][o] = 1; // 0 sum with any no.of coins is possible

for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= sum; j++) {
    if (coins[i - 1] <= j) {
      dp[i][j] = dp[i][j - val[i - 1]] + dp[i - 1][j];
    } else {
      dp[i][j] = dp[i - 1][j];
    }
  }
}

// coin change 2
// minimum no.of coins required for target sum
int n, sum;
int coins[n];
vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
for (int i = 1; i <= n; i++)
  dp[i][0] = 0;
for (int i = 1; i <= sum; i++)
  dp[0][i] = INT_MAX - 1; // to avoid integer overflow INT_MAX+1 becomes
                          // INT_MIN(in C++ int range is -2^31 to 2^31-1)

for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= sum; j++) {
    if (coins[i - 1] <= j) {
      dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j])
    } else {
      dp[i][j] = dp[i - 1][j];
    }
  }
}
