#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(const vector<int>& nums) {
		//construct a memo
		int n = nums.size();
    	int *memo = new int[n*(n+1)/2];
    	for(int i = 0; i < n; ++i){
    		for(int j = i; j < n; ++j){
    			if(i == j) memo[(2*n-i+1)*i/2+j-i] = nums[i];
    			else memo[(2*n-i+1)*i/2+j-i] = -1;
    		}
    	}

		//define a recursive procedure 
    	function<int(int, int)> f = [&nums, memo, n, &f](int i, int j){
    		//two base cases: 
			if(memo[(2*n-i+1)*i/2+j-i] >= 0) return memo[(2*n-i+1)*i/2+j-i];
			else if(j <= i+1)
				return max(nums[i],nums[j]);
			else{//two cases: rob i, or not rob i
				memo[(2*n-i+1)*i/2+j-i] = max(nums[i] + f(i+2, j), f(i+1, j));
	    		return memo[(2*n-i+1)*i/2+j-i];
			}
    	};

    	//call the recursion 

    	return f(0, n-1);
		//delete the memo
    }

};


