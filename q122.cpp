class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() <= 1) return 0;

        int sum = 0;
        for(auto a = prices.cbegin() + 1; a != prices.cend(); ++a){
        	sum += max((*a - *(a - 1)),0);
        }

        return sum;
    }
};