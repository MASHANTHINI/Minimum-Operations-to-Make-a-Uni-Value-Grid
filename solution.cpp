class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int rem=arr[0]%x;
        for(auto i:arr){
            if(i%x!=rem)return -1;
        }
        int sz=arr.size();
        int median=arr[sz/2];
        int cnt=0;
        for(int i:arr){
            cnt+=abs(i-median)/x;
        }
        return cnt;
    }
};
