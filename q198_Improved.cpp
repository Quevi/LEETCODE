class Solution {
private:
    unordered_map<int,int>hash;
public:
    int rob(vector<int>& nums) {
        
        return dfs(nums,0);
        
    }
    
    int dfs(vector<int>& nums,int i){
        if(i>=nums.size())return 0;
        if(hash.find(i)!=hash.end())return hash[i];
        int ret=max(dfs(nums,i+2)+nums[i],dfs(nums,i+1));
        hash[i]=ret;
        return ret;
    }
};