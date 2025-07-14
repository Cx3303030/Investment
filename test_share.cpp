#include"invest.h"
string test_share() {
	string sn = "A";
	string pn = "XiaoMing";
	string c1 = "CNY";
	double p1 = 10;
	int n1 = 1500;
	Share share(sn);
	share.invest(pn, c1, n1, p1);
	if (share.getName() == sn && share.investors[pn].getName()==pn && share.investors[pn].investments[0].getCurrency() == c1
		&& share.investors[pn].investments[0].getPrice() == p1 && share.investors[pn].investments[0].getNumble() == n1) {
		return "pass";
	}
	else {
		return "false";
	}
}