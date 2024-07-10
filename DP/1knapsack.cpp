
0 / 1 knapsack type problem

6 variations

1)
2)
3)
4)
5)
6)



to check base condition:
1) check for smallest valid input************



// 0/1 knapsack

// only rec
int knapsack(int wt[], int val[], int W, int n) {


if (n == 0 || wt == 0) return 0; // smallest valid input

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    return knapsack(wt, val, W, n - 1);
}



//rec + memo
int knapsack(int wt[], int val[], int W, int n) {


    if (n == 0 || wt == 0) return 0; // smallest valid input

    if (dp[n][W] != -1) return dp[n][W]; // memoization

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    return knapsack(wt, val, W, n - 1);
}



base case of recursion , becomes the initialization of TOP DOWN DP




    TOP - DOWN DP ***

    for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - val[i - 1]]   , dp[i - 1][j])
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

return dp[n][w];



VARIATIONS OF KNAPSACK
//

1)SUBSET SUM PROBLEM

weight, value of item = subarrray (here only 1 array )

                        if (ele > sum)
{
False , ignore
}
else
{
pick || not pick case
}


//memo
bool f(int n , vector<int>&v , vector<vector<int>>&memo , int sum)
{
if (sum == 0)return true;

    if (n == 0)return v[n] == sum;

    if (memo[n][sum] != -1)return memo[n][sum];

    bool taken = false;
    if (v[n] <= sum)taken = f(n - 1, v, memo, sum - v[n]);

    bool not_taken = f(n - 1, v, memo, sum);

    return memo[n][sum] = taken || not_taken;

}

return f(n - 1, v, memo, sum);

//bottom up
int n = v.size();
vector<vector<bool>>dp(n + 1 , vector<bool>(sum + 1 , 0) );

for (int i = 0; i <= n; i++)dp[i][0] = true;

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= sum; j++)
        {
            bool taken = false;

            if (v[i - 1] <= j)taken = dp[i - 1][j - v[i - 1]];

            bool not_taken = dp[i - 1][j];

            dp[i][j] = taken || not_taken;
            //  }
        }
    }
return (dp[n][sum]);


2)Equal sum partition





3)Count of subset with given sum 






4)Minimum subset sum difference






5)Count of subset with given difference





6)Target sum











