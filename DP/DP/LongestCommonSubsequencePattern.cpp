// ==================== LONGEST COMMON SUBSEQUENCE - ALL PATTERNS
// ====================

// -- Top-Down/Memoization (initialize dp[n+1][m+1] with -1) --
int LCS(string &x, string &y, int n, int m, vector<vector<int>> &dp) {//subsequence
	if (n == 0 || m == 0)
		return 0;
	if (dp[n][m] != -1)
		return dp[n][m];
	if (x[n - 1] == y[m - 1])
		return dp[n][m] = 1 + LCS(x, y, n - 1, m - 1, dp);
	else
		return dp[n][m] = max(LCS(x, y, n - 1, m, dp), LCS(x, y, n, m - 1, dp));
}

// -- Bottom-Up/Tabulation --
int lcs_length(string &x, string &y) {
	int n = x.size(), m = y.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[n][m];
}

// -- Printing the LCS --(Not that freq asked)
string print_lcs(string &a, string &b) {
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	//LCS length fill dp table
	/*
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	*/
	string ans = "";
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans += a[i - 1];
			--i;
			--j;
		} else if (dp[i - 1][j] > dp[i][j - 1])//move towards greater
			--i;
		else
			--j;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

// -- Longest Common Substring - Top-Down/Memoization --
int lcs_substring_memo(string x, string y, int i, int j, vector<vector<int>> &dp) {
		if (i == 0 || j == 0)
				return 0;
		
		if (dp[i][j] != -1)
				return dp[i][j];
		
		if (x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + lcs_substring_memo(x, y, i - 1, j - 1, dp);
		} else {
				dp[i][j] = 0; // Reset to 0 when characters don't match
		}
		
		return dp[i][j];
}


// -- Longest Common Substring --
int lcs_substring_tab(string &x, string &y) {
	int n = x.size(), m = y.size(), res = 0;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				res = max(res, dp[i][j]);
			}
	return res;
}

// -- Shortest Common Supersequence (SCS) 
// Length: n+m-LCS
string print_scs(string &a, string &b) {
	int n = a.size(), m = b.size();
	//LCS building code
	// vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	// for (int i = 1; i <= n; ++i)
	// 	for (int j = 1; j <= m; ++j)
	// 		if (a[i - 1] == b[j - 1])
	// 			dp[i][j] = 1 + dp[i - 1][j - 1];
	// 		else
	// 			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	
	string ans = "";
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans += a[i - 1];
			--i;
			--j;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			ans += a[i - 1];
			--i;
		} else {
			ans += b[j - 1];
			--j;
		}
	}
	while (i > 0) {
		ans += a[i - 1];
		--i;
	}
	while (j > 0) {
		ans += b[j - 1];
		--j;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

// -- Min #Deletions and Insertions to Transform a→b --
void min_del_insert(string &a, string &b) {
	int lcs = lcs_length(a, b);
	cout << "Deletions: " << a.size() - lcs << endl;
	cout << "Insertions: " << b.size() - lcs << endl;
}

// -- Longest Repeating Subsequence (LRS) --
int longest_repeating_subseq(string &str) {
	//same characters should be repeating 
	// ex:"AABEBCDD"
	// AABEBCDD
	// 01234567
	// "ABD"(026) , "ABD"(147)  
	//LCS of string,same string but with condition i!=j**** 
	int n = str.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && str[i - 1] == str[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[n][n];
}

// -- Sequence Pattern Matching --
bool is_subsequence(string &a, string &b) {
	// true if 'a' is subsequence of 'b'
	return lcs_length(a, b) == a.size();
}

// -- Minimum insertions/deletions to make palindrome --
int min_inserts_to_palindrome(string &a) {
	string rev = a;
	reverse(rev.begin(), rev.end());
	return a.size() - lcs_length(a, rev);
}
// Same for deletions!

// -- Usage for each function --
// Use/modify above snippets as needed in your workspace!