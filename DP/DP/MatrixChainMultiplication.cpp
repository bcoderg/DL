// ==================== MATRIX CHAIN MULTIPLICATION - ALL PATTERNS ====================

// Questions: MCM, Printing MCM, Evaluate expression to true/Bool Parenthesization,
// Min/Max value of expression, Palindrome Partitioning, Scrambled String, Egg Dropping

// -- MCM IDENTIFICATION & FORMAT --
// Given 2 indices i,j we take some k and divide the problem into parts:
// i to k, k+1 to j (temp ans), (temp ans)
// f(i, j) = f(i, k), f(k+1, j) + some operation in them (like +, -, *, /, ^, min, max)

// Base code structure:
int solve(int arr[], int i, int j) {
	if (i > j)
		return 0;

	for (int k = i; k < j; k++) {
		int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j);
		// some operation on temp_ans
		// get ans from temp_ans based on question
	}
}

// ==================== MATRIX CHAIN MULTIPLICATION PROBLEM ====================

// Problem: Find minimum cost of multiplying matrices
// Input: Array arr[] of size n
// Example: arr[] = {40, 20, 30, 10, 30};
// 
// Matrices representation:
// A1: 40X20, A2: 20X30, A3: 30X10, A4: 10X30
// A1 * A2 * A3 * A4 = 40X20 * 20X30 * 30X10 * 10X30 = 26000
//
// Put brackets in all places, figure out minimum possible way to multiply them:
// (A1 * A2) * (A3 * A4)
// A1 * (A2 * A3) * A4  
// A1 * ((A2 * A3) * A4)
// (A1 * (A2 * A3)) * A4 (many such ways)
//
// Structure: arr[i-1] * arr[i]
// Start from index 1, end at n-1
//
// Steps:
// 1. Find right i, j condition
// 2. Find base condition  
// 3. Find k loop movement

// Recursive code
int solve(int arr[], int i, int j) {
	if (i >= j)
		return 0;

	int mn = INT_MAX;

	for (int k = i; k < j; k++) {
		int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		mn = min(mn, temp_ans);
	}
	return mn;
}

// Call: solve(arr, 1, n - 1);

// Memoization
vector<vector<int>> dp(n, vector<int>(n, -1));

int solve(int arr[], int i, int j) {
	if (i >= j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int mn = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		mn = min(mn, temp_ans);
	}

	return dp[i][j] = mn;
}

// MCM recursion with memoization (more optimized, by storing left,right part as cache)
vector<vector<int>> dp(n, vector<int>(n, -1));

int mcm(int i, int j) {
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];

	int mn = INT_MAX;
	for (int k = i; k < j; k++) {
		int left, right;
		if (dp[i][k] != -1)
			left = dp[i][k];
		else {
			left = mcm(i, k);
			dp[i][k] = left;
		}

		if (dp[k + 1][j] != -1)
			right = dp[k + 1][j];
		else {
			right = mcm(k + 1, j);
			dp[k + 1][j] = right;
		}

		int step = left + right + arr[i - 1] * arr[k] * arr[j];
		mn = min(mn, step);
	}
	return dp[i][j] = mn;
}

// ==================== PALINDROME PARTITIONING ====================

// Problem: Divide string into minimum no. of palindromic substrings
// Worst case: size of string n, then n-1 cuts can be made each of size 1
//
// Steps:
// 1. Fix i, j
// 2. Get base condition
// 3. k loop movement
//
// k runs from i to j-1, (i, k), (k+1, j)
// For each k, check if (i, k) is palindrome, then check if (k+1, j) is palindrome
// Get main ans from temp_ans
// Here if we make 1 cut at k, then 1 + solve(i, k) + solve(k+1, j)

// Recursion
int solve(string s, int i, int j) {
	if (i >= j) return 0;
	
	if (isPalindrome(s, i, j)) return 0;
	
	int mn = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = 1 + solve(s, i, k) + solve(s, k + 1, j);
		mn = min(mn, temp_ans);
	}
	return mn;
}

// Call: solve(s, 0, n - 1);

// Memoization
vector<vector<int>> dp(n, vector<int>(n, -1));
int solve(string s, int i, int j) {
	if (i >= j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	if (isPalindrome(s, i, j)) return 0;

	int mn = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = 1 + solve(s, i, k) + solve(s, k + 1, j);
		mn = min(mn, temp_ans);
	}
	return dp[i][j] = mn;
}

// isPalindrome function
bool isPalindrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int n = s.size();
solve(s, 0, n - 1);

// Optimized Memoization
// Before calling recursive function, we can check if that is already present in dp table or not
// This avoids calling recursive function again and again for same i, j => reduces call stack size

vector<vector<int>> dp(n, vector<int>(n, -1));
int solve(string s, int i, int j) {
	if (i >= j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int mn = INT_MAX;
	for (int k = i; k < j; k++) {
		int left, right;
		if (dp[i][k] != -1)
			left = dp[i][k];
		else {
			left = solve(s, i, k);
			dp[i][k] = left;
		}

		if (dp[k+1][j] != -1)
			right = dp[k+1][j];
		else {
			right = solve(s, k + 1, j);
			dp[k + 1][j] = right;
		}

		int temp_ans = 1 + left + right;
		mn = min(mn, temp_ans);
	}
	return dp[i][j] = mn;
}

// ==================== EVALUATE EXPRESSION TO TRUE / BOOLEAN PARENTHESIZATION ====================

// Problem: Given T, F (True, False) and operators &, |, ^ (AND, OR, XOR)
// Find no. of ways to evaluate this expression to true
//
// Example: T | F&T^F
// (T | F)&(T^F) - 1 way
// (T) | (F & (T^F)) - 2 ways
//
// Steps:
// 1. Fix i, j
// 2. Get base condition
// 3. k loop movement
//
// k moves through the operators (&, |, ^)
// At each point we have: (left expression, operator, right expression)
//
// If operator is:
// & - no. of ways of left true * no. of ways of right true
// | - (no. of ways of left true * no. of ways of right false) +
//     (no. of ways of left false * no. of ways of right true)
//     // both false case, we should ignore
// ^ - (no. of ways of left true * no. of ways of right false) +
//     (no. of ways of left false * no. of ways of right true)
//     // since xor means opposite values
//
// Here we need to find no. of ways of left true, left false, right true, right false
// The parameters are i, j and true/false (whether to find for true or false)


// Recursive code
int solve(string s, int i, int j, bool isTrue) {
	if (i > j)
		return false;
	if (i == j) {
		// if char is T
		if (isTrue == true) {
			return s[i] == 'T';
		} else { // if char is false
			return s[i] == 'F';
		}
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int leftTrue = solve(s, i, k - 1, true);
		int leftFalse = solve(s, i, k - 1, false);
		int rightTrue = solve(s, k + 1, j, true);
		int rightFalse = solve(s, k + 1, j, false);

		if (s[k] == '|') {
			if (isTrue == true) {
				ans += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
			} else {
				ans += leftFalse * rightFalse;
			}
		} else if (s[k] == '&') {
			if (isTrue == true) {
				ans += leftTrue * rightTrue;
			} else {
				ans += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
			}
		} else if (s[k] == '^') {
			if (isTrue == true) {
				ans += (leftTrue * rightFalse) + (leftFalse * rightTrue);
			} else {
				ans += (leftTrue * rightTrue) + (leftFalse * rightFalse);
			}
		}
	}
	return ans;
}

// final_ans = solve(s, 0, n - 1, true); // in end we need to find no. of ways of true

// Memoization
// Here it varies with 3 parameters i, j and isTrue
// We can have a 3d dp table (i, j, k), where k is 0 or 1 (true or false)
// Or simply we can have a map with key as string of i, j, k

map<string, int> dp;
int solve(string s, int i, int j, bool isTrue) {
	if (i > j)
		return false;
	if (i == j) {
		// if char is T
		if (isTrue == true) {
			return s[i] == 'T';
		} else { // if char is false
			return s[i] == 'F';
		}
	}

	string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
	if (dp.find(key) != dp.end())
		return dp[key];

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int leftTrue = solve(s, i, k - 1, true);
		int leftFalse = solve(s, i, k - 1, false);
		int rightTrue = solve(s, k + 1, j, true);
		int rightFalse = solve(s, k + 1, j, false);

		if (s[k] == '|') {
			if (isTrue == true) {
				ans += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
			} else {
				ans += leftFalse * rightFalse;
			}
		} else if (s[k] == '&') {
			if (isTrue == true) {
				ans += leftTrue * rightTrue;
			} else {
				ans += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
			}
		} else if (s[k] == '^') {
			if (isTrue == true) {
				ans += (leftTrue * rightFalse) + (leftFalse * rightTrue);
			} else {
				ans += (leftTrue * rightTrue) + (leftFalse * rightFalse);
			}
		}
	}

	return dp[key] = ans;
}

// ==================== SCRAMBLED STRING ====================

// Question: Scrambled String
