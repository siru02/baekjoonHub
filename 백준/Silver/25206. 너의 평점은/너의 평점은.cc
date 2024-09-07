#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string str, char delimiter) {
	std::istringstream iss(str); //문자열을 표준입력으로 받도록 처리한다
	std::string buf;

	std::vector<std::string> result;

	while (std::getline(iss, buf, delimiter)) {
		result.push_back(buf);
	}
	return result;
}

int main() {
	double avg = 0;
	double credit = 0;
	double score = 0;
	std::string input;
	std::vector<std::string>::iterator it;
	for (int i = 0; i < 20; i++) {
		std::getline(std::cin, input);
		std::vector<std::string> result;
		result = split(input, ' ');
		double tmp = std::stod(*(result.begin() + 1));
		it = result.begin() + 2;
		if (*it != "P")
			credit += tmp;
		if (*it == "A+") {
			score = 4.5;
		}
		else if (*it == "A0") {
			score = 4.0;
		}
		else if (*it == "B+") {
			score = 3.5;
		}
		else if (*it == "B0") {
			score = 3.0;
		}
		else if (*it == "C+") {
			score = 2.5;
		}
		else if (*it == "C0") {
			score = 2.0;
		}
		else if (*it == "D+") {
			score = 1.5;
		}
		else if (*it == "D0") {
			score = 1.0;
		}
		else{
			score = 0;
		}
		avg += score * tmp;
	}
	std::cout << avg / credit;
}