#include <iostream>
#include "interval_map.hpp" // Assuming the interval_map implementation is in this header file

int main() {
	interval_map<int, char> im('A');
	im.assign(1, 3, 'B');
	im.assign(5, 7, 'C');

	for (int i = 0; i < 10; ++i) {
		std::cout << "Key " << i << " -> " << im[i] << '\n';
	}

	return 0;
}