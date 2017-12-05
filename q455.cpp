#include "Common.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

	    function<int(vector<int>::const_iterator, vector<int>::const_iterator)> sol = [&g,&s,&sol](vector<int>::const_iterator a, vector<int>::const_iterator b){
	    	//base case: 
	    	if(a == g.cend() || b == s.cend()) {
	    		cout << "end of recursion!!!"<<endl;
	    		return 0;
    		}
	    	//找到b中第一个比*a大的元素
	    	b = find_if(b, s.cend(), [a](int x){return x >= *a;});
	    	cout << "child: " << *a << endl;
	    	cout << "cookie: " << *b << endl;
	    	// cout << "The first cookie satisfying the first child is: " << *b << endl;

	    	// cout << "The rest of child is: " ;

	    	// cout << "a: " << *(++a) <<endl;
	    	// cout << "g.cbegin(): " << *g.cbegin() << endl;
	    	// cout << "g.cend(): " << *g.cend() << endl;
	    	// for(; a != g.cend(); ++a){ 
	    	// 	cout <<*a << " ";
	    	// 	cout << "g.cend() - a: "<< g.cend()-a;
	    	// }
	    	// cout << endl;
	    	cout << "The rest of children are: ";
	    	for(auto x = a + 1; x != g.cend(); ++x) cout << *x << " ";
	    	cout << endl;

	    	cout <<  "The rest of cookies are: ";
	    	for(auto x = b + 1; x != s.cend(); ++x) cout << *x << " ";
	    	cout << endl;



	    	// cout << "g is: ";
	    	// for(auto x:g){
	    	// 	cout << x << " ";
	    	// }
	    	// cout << endl;
	    	// // cout << "*g.cend()-1: " << *(g.cend()-1) << endl;

	    	if(b != s.cend()) return 1 + sol(a + 1, b + 1);
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
	// vector<int> a{1,2};
	// auto it = a.cbegin();
	// auto f = [it](vector<int>::const_iterator x){
	// 	cout << (it == x) << endl;
	// };
	// f(it);
}