class Solution {
 public:
 long mod=1e9+7;
    long res=0;
    vector<vector<long>>dp;
    vector<int>dirs={-1,0,1,0,-1};
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<long>(n,-1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dp[i][j]==-1){
                    // if sequence starting from i,j is not counted yet,so start from here
                    helper(i,j,grid,m,n);
                }
        return res;
    }
    long helper(int r,int c,vector<vector<int>>& grid,int &m,int &n){
            // if we have visited this cell then just return the number of sequences
        if(dp[r][c]!=-1)
            return dp[r][c];
            // sequence with length 1 starting from (i,j)
       long ans=1;
       for(int i=0;i<4;i++){
            int nr=r+dirs[i],nc=c+dirs[i+1];
            if(nr<0 || nc<0 || nr>=m || nc>=n)
                continue;
            if(grid[nr][nc]>grid[r][c]){
			// sequence cnt will be same as of (nr,nc) cell 
                ans=(ans+helper(nr,nc,grid,m,n))%mod;
            } 
        }
            // add cnt of sequences starting from this cell to result
       res=(res+ans)%mod;
       dp[r][c]=ans;
       return ans;
  }
};
