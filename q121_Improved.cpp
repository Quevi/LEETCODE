class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <=1 ) return 0;
        int result = 0;
        int priceB = prices[0];
        for (int i=1; i< prices.size(); i++) {
            int gain = prices[i] - priceB;
            if (gain > result) result = gain;
            if (prices[i] < priceB) priceB = prices[i];
        }
        return result;
    }
};