#include <iostream>
#include <vector>

int LinearSearch(std::vector<int> vec, int target) {

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == target) {
			return i;
		}
	}
	return -1;
}


int main() {
	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	int target = 4;

	int result = LinearSearch(vec, target);

	std::cout << "The result is: " << result << std::endl;
	return 0;
}