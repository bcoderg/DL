
//MCM recursion
vector<vector<int>> dp(n,vector<int>(n,-1));

int mcm(int i , int j)
{
    if(i>=j)return 0;

    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int step=mcm(i,k)+mcm(k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,step);
    }
    return dp[i][j]=mn;
}
return mcm(1,n-1);
