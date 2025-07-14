#include"invest.h"
string test_person() {
	string name = "XiaoMing";
	string c1 = "CNY";
	double p1 = 10;
	int n1 = 1500;
	Person p(name);
	p.invest(c1, n1, p1);
	if (p.getName() == name && p.investments[0].getCurrency() == c1
		&& p.investments[0].getPrice() == p1 && p.investments[0].getNumble() == n1) {
		return "pass";
	}
	else {
		return "false";
	}
}