#include <iostream>
#include <vector>

std::vector<double> averager(std::vector<double> vec, double k) {
	std::vector<double> result;
	
	for (int i = 0; i < k; i++) {
		double temp{ 0.0 };
		for (int j = i; j < (k+i); j++) {
			temp += vec[j];
		}
		temp = temp / k;
		result.push_back(temp);
	}

	return result;
}

int main() {
	std::vector<double> vec{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
	double k = 4.0;

	auto result = averager(vec, k);
	//[2,3,4]
	std::cout << "[";
	for (auto elem : result) {
		std::cout << elem << " ";
	}
	std::cout << "]" << std::endl;
}