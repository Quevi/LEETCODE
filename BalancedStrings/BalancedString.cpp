class Solution {
public:
    int balancedStringSplit(string s) {
        int numOfBalancedString = 0;
        int i = 0;
        while(i < s.size()){
            greedyBalancedString(i, s);
            ++i;
            ++numOfBalancedString;
        }
        return numOfBalancedString;
    }

    void greedyBalancedString(int& i, string& s){
    //this method move cursor until number of L equals number of R
        int numOfL = 0, numOfR = 0;

        while(numOfL != numOfR && i < s.size() && !(numOfL == 0 && numOfR == 0)){
            ++i;
            if(s[i] == 'L')
                numOfL++;
            else
                numOfR++;
        }
    }
};