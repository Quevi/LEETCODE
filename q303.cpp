//每次都要不time limit exceeded，要么是 memory limit exceeded。不知道再怎么改进。
#include <vector>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <memory>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums): arr(nums){
        n = nums.size();
        A = new int[n*n];
        for(int i = 0; i < n ; ++i){
        	for(int j = i; j < n; ++j){
	        	if(j == i) {
	        		A[n*i + j] = nums[i];
		       	}
	        	else A[n*i + j] = INT_MIN;  
        	}
        }
    }
    int sumRange(int i, int j) {
        if(A[n*i + j] != INT_MIN){
        	return A[n*i + j];
        }
        else{
        	A[n*i+j] = sumRange(i,(i+j)/2) + sumRange((i+j)/2+1,j);
        	return A[n*i+j];
        }
    }
private:
	int n;
	vector<int> arr;
	int* A;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(){
	vector<int> a{1,2,3,4,5,6,7,8,9,10};
	NumArray na(a);
	cout << na.sumRange(0,6) << endl;
}