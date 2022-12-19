#include <iostream>
#include <vector>

class Solution{
public:
    int maxProfit(std::vector<int>&prices) {
        int maxProfit = 0;
        int size = prices.size();
        for (int i = 1; i < size; i++) {
            maxProfit += std::max(0, prices[i] - prices[i - 1]);
        }
        return maxProfit;
    }
};


int main() {
    std::vector<int> prices1{7,1,5,3,6,4};
    std::vector<int> prices2{1,2,3,4,5};
    Solution sol;

    int result1 = sol.maxProfit(prices1);
    int result2 = sol.maxProfit(prices2);

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    return 0;
}