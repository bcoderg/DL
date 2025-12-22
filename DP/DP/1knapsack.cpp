
0 / 1 knapsack type problem

6 variations

1)subset sum
2)equal sum partition
3)count of subset sum
4)minimum subset sum diff
5)target sum
6)# of subset and given diff



to check base condition:
1) check for smallest valid input************


// 0/1 knapsack

vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1)); // memoization
// only rec
int knapsack(int wt[], int val[], int W, int n) {

  if (n == 0 || wt == 0)
    return 0; // smallest valid input

  if (wt[n - 1] <= W) { // pick , not pick
    return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
               knapsack(wt, val, W, n - 1));
  }
  return knapsack(wt, val, W, n - 1);
}

return knapsack(wt, val, W, n); // call the function with initial values

// rec + memo
int knapsack(int wt[], int val[], int W, int n) {

  if (n == 0 || W == 0)
    return 0; // smallest valid input

  if (dp[n][W] != -1)
    return dp[n][W]; // memoization

  if (wt[n - 1] <= W) {
    return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                          knapsack(wt, val, W, n - 1));
  }
  return dp[n][W] = knapsack(wt, val, W, n - 1);
}

base case of recursion , becomes the initialization of TOP DOWN DP




TOP - DOWN DP ***

	for (int i = 1; i <= n; i++)
{
	for (int j = 1; j <= w; j++)
		{
			if (wt[i - 1] <= j)
			{
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]]   , dp[i - 1][j])
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

return dp[n][w];



//VARIATIONS OF KNAPSACK


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
vector<vector<bool>>dp(n + 1 , vector<bool>(sum + 1 , false) );

for (int i = 0; i <= n; i++)dp[i][0] = true;

for (int i = 1; i <= n; i++)
{
	for (int j = 1; j <= sum; j++)
		{
			bool taken = false;

			if (v[i - 1] <= j)taken = dp[i - 1][j - v[i - 1]];

			bool not_taken = dp[i - 1][j];

			dp[i][j] = taken || not_taken;
		}
}
return (dp[n][sum]);


2)Equal sum partition

same subset sum , but check with sum / 2

if one subset part = half , then other part gives other half

== > Equal sum partition



3)Count of subset with given sum
//whenever we see something like count no.of ways we do addition of all possible states

let sum = k

vector<vector<int>>dp(n + 1 , vector<int>(k + 1, 0));
for (int i = 0; i <= n; i++)dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			{
				if (nums[i - 1] <= j)
				{
					//if count no.of ways we do + 
					dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
	}

return dp[n][k];





4)Minimum subset sum difference

int minDifference(int arr[], int n)  {
	// Your code goes here
	int s = 0;
	for (int i = 0; i < n; i++)s += arr[i];
	int sum = s / 2;
	bool dp[n + 1][sum + 1];
	memset(dp , false , sizeof(dp));
	for (int i = 0; i <= n; i++)dp[i][0] = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i <= sum; i++)
	{
		if (dp[n][i])
		{
			ans = min(ans, s - 2 * i);
		}
	}
	return ans;
}



5)Count of subset with given difference

class Solution {
public:
int SubsetSumDifference(vector<int> &nums, int target) {
  int sum = 0, diff = target, n = nums.size();
  for (auto x : nums)
    sum += x;

  // s1 + s2 = sum
  // s1 - s2 = diff
  // ________________
  // 2s1 = sum + diff
  // s1 = (sum + diff)/2

  // ===> find no.of subsets with sum s1 = (sum+diff)/2;

  int k = (sum + diff);
  if (k & 1 || k < 0)
    return 0; // handling edge cases like k<0 , dp[][] cannot be created
  k /= 2;

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) // to handle inputs with all 0's add from j=0
    {
      if (nums[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  int ways = dp[n][k];
  return ways;
}
}
;

6)Target sum



same put + , - in front of numbers to get target sum

+ ones in s1
- ones in s2

same as above subset sum difference problem
