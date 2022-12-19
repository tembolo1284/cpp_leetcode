#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy = std::min(buy, prices[i]);
            sell = std::max(sell, prices[i] - buy);
        }
        return sell;
    }
};

int main() {
    std::vector<int> prices1{ 7,1,5,3,6,4 };
    std::vector<int> prices2{ 7,6,4,3,1 };
    Solution sol;
    int result1 = sol.maxProfit(prices1);
    int result2 = sol.maxProfit(prices2);

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    return 0;
}