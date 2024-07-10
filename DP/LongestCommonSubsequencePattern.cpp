

Longest Common SUb- Sequence

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



//Longest Common SUbstring 

//bottom up tabulation
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        if(x[i-1]==y[j-1])
        {
            dp[i][j]=1+dp[i-1][j-1];
            res=max(res,dp[i][j]);
        }
        else
        {
            dp[i][j]=0;
        }
    }
}
return res;

//top - down 
int lcs(n , m)
{
    if(n==0 || m==0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];

    if(x[n-1]==y[m-1])
    {
        dp[n][m]=1+lcs(n-1,m-1);
    }
    
    lcs(n-1,m);
    lcs(n,m-1);
    return dp[n][m];
}



********************************************************************************

//printing the LCS 

FILL IN SAME  FASHION BUT ADD THE PRINTING PART 

//WHILE processing table , if characters are unequal take max(top , left ) as value 
if(a[i-1]==b[j-1])
{
    dp[i][j]=1+dp[i-1][j-1]
}
else
{
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //top , left
}

// TO PRINT , WE NEED TO GO IN REVERSE ORDER 
// WE WILL START FROM THE END OF THE DP TABLE
// IF THE CHARACTERS ARE SAME , WE WILL ADD IT TO THE RESULT STRING
// ELSE WE WILL MOVE TO THE DIRECTION OF MAXIMUM VALUE IN THE DP TABLE


void print_lcs()
{
    string ans="";
    i=n , j=m;

    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"Longest Common Subsequence is : "<<ans<<endl; 

}

********************************************************************************

//Shortest common Super Sequence 
//Shortest common Super Sequence is the shortest string that has both the given strings as subsequences.

a="AGGTAB" 
B="GXTXAYB"

//Shortest common Super Sequence is : AGXGTXAYB 

===> ANS = write the repeated characters only once , so that length will be minimum 

find lcs length 

ans= n + m - lcs_length 



**Printing the Shortest common Super Sequence
build the dp matrix same as lcs 

just like printing lcs , 

//check for empty string case 
i=n , j=m;
stirng ans="";
while(i>0 && j>0)
{
    if(a[i-1]==b[j-1])
    {
        ans+=a[i-1];
        i--;j--;
    }
    else
    {
        if(dp[i-1][j] > dp[i][j-1])
        {
            ans+=a[i-1];
            i--;
        }
        else
        {
            ans+=b[j-1];
            j++;
        }
    }
}

//empty string case
while(i--)ans+=a[i];
while(j--)ans+=b[j];



********************************************************************************

Minimum number of deletions and insertions to transform one string into another

in strings a,b 

1)find lcs length 

bcoz lcs is common in both , lets keep it as it is  

2)delete extra in a 
3) insert needed in b

a ------------>  b 


a----> LCS ---> b 


********************************************************************************

Longest Repeating Subsequence

CHaracters should repeat in subsequence ,

take same string as a,b 

do LCS , but check condition if i==j , then skip that case 

checking characters equal , and their positions should be different


int n=str.size();
		    string a=str , b=str;
		    vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
		    int ans=0;
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=n;j++)
		        {
		            if(i!=j && a[i-1]==b[j-1])
		            {
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j]=max(dp[i][j-1] , dp[i-1][j]);
		            }
		            ans=max(ans , dp[i][j]);
		        }
		    }
		    return ans;


********************************************************************************
Sequence Pattern Matching

if a is subsequence of b or not ?

just do LCS of both , check the size of a==LCS ===>true 


********************************************************************************

Minimum insertions to make string palindrome 

get LCS( a , reverse(a) )

return n-LCS_length 

********************************************************************************

Minimum number of deletions to make a string palindrome

get LCS( a , reverse(a) )
return length of string - LCS_Length


to make palindrome (no.of insertions == no.of deletions)

*******************************************************************************














