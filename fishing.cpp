#include <iostream>
#include <fstream>
#include <string>



int main()
{
	std::ifstream river("river.txt");
	std::ofstream bascket("bascket.txt", std::ios::app);
	std::string fish_kind;
	std::string buffer;
	int count = 0;
	char ans;
	do {
		std::cout << "What kind of fish you fish? ";
		std::cin >> fish_kind;

		while (!river.eof()) {
			river >> buffer;
			if (fish_kind == buffer) {
				bascket << buffer << std::endl;
				count++;
			}
		}
		river.seekg(0);
		std::cout << "One more? (y/n): ";
		std::cin >> ans;
	} while (ans=='y');
	std::cout << "You cath: " << count << " fish.";
	
	bascket.close();
	river.close();
}