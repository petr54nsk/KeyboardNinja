#include <iostream>

class testee
{
private:
	int a;
	int b;
public:
	testee(int a_buff, int b_buff) {
		a = a_buff;
		b = b_buff;
	}
	int summ() {
		return a + b;
	}
	
};

int main() {
	int a = 10, b = 20;
	testee sum(a, b);
	std::cout << sum.summ() << std::endl;
	a = 15;
	b = 25;
	sum(a, b);
	std::cout << sum.summ() << std::endl;
}