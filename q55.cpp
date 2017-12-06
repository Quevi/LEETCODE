#include "Common.h"
class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 0) return 1;
    //     bool sol = 1;
    //     for(int i = 1; i < n; ++i){
    //     	if(!sol) sol = 0;
    //     	else if(){

    //     	}
    //     }   
    // }
bool canJump(vector<int>& A) {
	int n = A.size();
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i){
        reach = max(i + A[i], reach);
        cout << "i = " << i << endl;
        cout << "i + A[i] = " << i + A[i] << endl;
        cout << "reach = " << reach << endl;
    }
    return i == n;
}
};


int main(){
    Solution sol;
    vector<int> a{2,3,0,1};
    cout << sol.canJump(a) << endl;
}