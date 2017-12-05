#include "Common.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

	    function<int(vector<int>::const_iterator, vector<int>::const_iterator)> sol = [&g,&s,&sol](vector<int>::const_iterator a, vector<int>::const_iterator b){
	    	//base case: 
	    	if(a == g.cend() || b == s.cend()) {
	    		return 0;
    		}
	    	//找到b中第一个比*a大的元素
	    	b = find_if(s.cbegin(), s.cend(), [a](int x){return x >= *a;});

	    	if(b != s.cend()) return 1 + sol(++a, ++b);
	    	else return 0;
	    	return 0;
	    };
    
    	return sol(g.cbegin(), s.cbegin());
    }
};

int main(){
	Solution sol;
	vector<int> a{10,9,8,7,10,9,8,7},b{10,9,8,7};
	cout << sol.findContentChildren(a,b) << endl;
}