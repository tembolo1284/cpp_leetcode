// The API isBadVersion is defined for you.
bool isBadVersion(int version);

#include <iostream>

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 0;
        int upper = n;
        int mid;
        while (lower < upper) {
            mid = lower + (upper - lower) / 2;
            if (!isBadVersion(mid)) {
                lower = mid + 1;            
            } else {
                upper = mid;
            }
        }
        return lower;
    }
};

int main() {

    return 0;
}