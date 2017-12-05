#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<int> diff;
public:
    int maxProfit(vector<int>& prices) {
        //construct difference vector
        // cout << "hello!!!" << endl;
        if (prices.size() == 0) {
        	// cout << "prices.size(): " << prices.size() <<endl;
        	return 0;
	        // cout << "hello again!" << endl;
	    }
        else diff = vector<int>(prices.size(),0);
        for(auto b = prices.begin()+1, b1 = diff.begin() + 1; b != prices.end(); ++b, ++b1){
        	cout << "*b: " << *b <<endl;
        	*b1 = *b - *(b-1);
        	cout << "*b becomes: " << *b << endl;
        }

        cout << "diff: ";
        for(auto x:diff){
        	cout << x << " ";
        }
        cout << endl;

        return FindMP(0, diff.size()-1);
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
    	return max(max1,max2);
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
	vector<int> a{};
	cout << sol.maxProfit(a) << endl;
}