#include "Common.h"

class Solution {
private:
    vector<int> diff;
public:
    int maxSubArray(vector<int>& nums) {
        diff = nums;
        int a = FindMP(0, nums.size()-1);
        if(a == 0) return *max_element(nums.begin(),nums.end());
        return a;
    }
    int MaxMid(int s, int t){//s and t inclusive
        int n = (s+t)/2;
        int sum1 = 0, max1 = 0;
        for(int i = n; i >= s; --i){
            sum1 += diff[i];
            if(sum1 > max1) max1 = sum1;
        }
        int sum2 = 0, max2 = 0;
        for(int i = n + 1; i <= t; ++i){
            sum2 += diff[i];
            if(sum2 > max2) max2 = sum2;
        }
        return max1 + max2;
    }

    int FindMP(int i, int j){// i and j inclusive
        if(i == j) return max(0, diff[i]);
        else{
            int n = (i+j)/2;
            return max(max(FindMP(i,n), MaxMid(i,j)),FindMP(n+1,j));
        }
    }
};




int main(){
    Solution sol;
    vector<int> a{-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(a) << endl;
}