
can pick a item any no. of times 

if(v[i-1]<=j)
{
    dp[i-1][j] , dp[i][j-v[i-1]]  //stay at same index 
}
else
{
    dp[i][j]=dp[i-1][j];
}




