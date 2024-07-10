

Longest Common Subsequence

//rec 
int LCS(string x, string y, int n, int m) {
    if (n == 0 || m == 0) return 0; // smallest valid input

    if (x[n - 1] == y[m - 1])
    {
        return 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
    }
}


//memo 
int dp[n][m];
memset(dp, -1, sizeof(dp));


int LCS(string x, string y, int n, int m) {
    if (n == 0 || m == 0) return 0; // smallest valid input

    if (dp[n][m] != -1) return dp[n][m]; // memoization

    if (x[n - 1] == y[m - 1])
    {
        return dp[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return dp[n][m] = max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
    }
}   





//bottom - up tabulation 

vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        if(x[i-1]==y[j-1])
        {
            dp[i][j]=1+dp[i-1][j-1];
        }
        else
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

return dp[n][m];







