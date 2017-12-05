#include "Common.h"

class Solution {
private:
	map<pair<int, int>, int> memo;
public:
    int climbStairs(int n) {
        int cnt = 0, Start = 0;
        if(n%2) Start = 1;
        for(int x = Start; x <= n; x += 2){
        	cnt += f(x, (n - x)/2);
        }
        return cnt;
    }

    int f(int x, int y){
    	if(x == 0 || y == 0) return 1;
    	if(memo.find(make_pair(x,y)) != memo.end())
    		return memo[make_pair(x,y)];
    	else{
	    	int sum = 0;
	    	for(int i = 0; i <= y; ++i){
	    		sum += f(x - 1, i);
	    	}
	    	memo[make_pair(x,y)] = sum;
	  		return sum;
    	}
    }
};