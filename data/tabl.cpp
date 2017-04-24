#include <iostream>
#include <fstream>
#include <string>

struct results {
	std::string name;
	int score;
};

std::istream  & operator>>(std::istream & is, results & res) {
	is >> res.name >> res.score;
	return is;
}

std::ostream & operator<<(std::ostream & out, results & res) {
	out << res.name << " " << res.score << std::endl;
	return out;
}

bool createFileResult();

bool addNewResult(results res[], results newres, int const n);

int main() {
	results new_res;
	int const n = 10;
	results res[n];
	std::cin >> new_res;
	std::ifstream fin("results.txt");
	for(int i = 0; i < n; i++) {
		fin >> res[i];
	}
	if(addNewResult(res, new_res, n)) std::cout << "Вы вошли в топ 10!";
	else std::cout << "К сожаленью вы не вошли в топ 10(((";
	fin.close();
	std::ofstream fout("results.txt");
	for(int i = 0; i < n; i++) {
		fout << res[i];
	}
	fout.close();
}

bool addNewResult(results res[], results new_res, int const n) {
	int buff;
	for(int i = 0; i < n; i++) {
		if(res[i].score < new_res.score) {
			for(int j = n - 1; j > i; j--) {
				res[j] = res[j-1];
			}
			res[i] = new_res;
			return 1;
		}
	}
	return 0;
}

bool createFileResult() {
	std::ofstream fout("results.txt");
	results null_res;
	null_res.name = "name";
	null_res.score = 0;
	for(int i = 0; i < 10; i++) {
		fout << null_res;
	}
}