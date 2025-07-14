#include"invest.h"
string test_invest() {
	string c = "CNY";
	int n = 1500;
	double p = 10.1;
	Invest i(c, n, p);
	if (i.getCurrency() == c && i.getNumble() == n &&
		i.getPrice() == p && i.getValue(c) == n * p) {
		return "pass";
	}
	else {
		return "false";
	}
}