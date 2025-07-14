#include"invest.h"
//综合测试1-模拟正常输入环境
string test1() {
	int n = 2;
	while (n > 0) {
		string share_name1 = "A";
		string investor1 = "ZhangSan";
		string currency1 = "CNY";
		double price1 = 25;
		int number1 = 1000;
		if (shares.find(share_name1) == shares.end()) {
			Share share1(share_name1);
			shares[share_name1] = share1;
		}
		shares[share_name1].invest(investor1, currency1, number1, price1);
		n--;

		string share_name2 = "A";
		string investor2 = "LiSi";
		string currency2 = "JPY";
		double price2 = 100;
		int number2 = 2200;
		if (shares.find(share_name2) == shares.end()) {
			Share share2(share_name2);
			shares[share_name2] = share2;
		}
		shares[share_name2].invest(investor2, currency2, number2, price2);
		n--;
	}
	
	int m = 1;
	while (m > 0) {
		string source1 = "CNY";
		string exchange1 = "JPY";
		double rate1 = 22;
		ExchangeRate Rate1(source1, exchange1, rate1);
		rates.push_back(Rate1);
		m--;
	}
	
	int k = 2;
	double result1, result2;
	while (k > 0) {
		string mode11 = "PERSON";
		string name1 = "ZhangSan";
		string currency1 = "CNY";
		result1 = persons[name1].getpTotal(currency1);
		k--;
		string mode12 = "STOCK";
		string name2 = "A";
		string currency2 = "CNY";
		result2 = shares[name2].getTotal(currency2);
		k--;
	}
	rates.clear();
	persons.clear();
	shares.clear();
	if (result1 - 25000 < MINIMUM && result2 - 35000 < MINIMUM) {
		return "pass";
	}
	else {
		cout << result1 << "\t" << result2 << endl;
		return "false";
	}
}
