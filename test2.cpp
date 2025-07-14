#include"invest.h"
//综合测试2-模拟正常输入环境
string test2() {
	int n = 3;
	while (n > 0) {
		string share_name1 = "A";
		string investor1 = "ZhangSan";           //CNY  25000
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
		string investor2 = "LiSi";               //JPY  220000  ;  CNY  10000
		string currency2 = "JPY";
		double price2 = 100;
		int number2 = 2200;
		if (shares.find(share_name2) == shares.end()) {
			Share share2(share_name2);
			shares[share_name2] = share2;
		}
		shares[share_name2].invest(investor2, currency2, number2, price2);
		n--;

		string share_name3 = "B";
		string investor3 = "ZhangSan";           //USD  28000  ;  CNY  200000
		string currency3 = "USD";
		double price3 = 14;
		int number3 = 2000;
		if (shares.find(share_name3) == shares.end()) {
			Share share3(share_name3);
			shares[share_name3] = share3;
		}
		shares[share_name3].invest(investor3, currency3, number3, price3);
		n--;

		string share_name4 = "A";
		string investor4 = "WangWu";              //USD  50000  ;  CNY  7000
		string currency4 = "USD";
		double price4 = 10;
		int number4 = 5000;
		if (shares.find(share_name4) == shares.end()) {
			Share share4(share_name4);
			shares[share_name4] = share4;
		}
		shares[share_name4].invest(investor4, currency4, number4, price4);
		n--;
	}

	int m = 2;
	while (m > 0) {
		string source1 = "CNY";
		string exchange1 = "JPY";
		double rate1 = 22;
		ExchangeRate Rate1(source1, exchange1, rate1);
		rates.push_back(Rate1);
		m--;

		string source2 = "CNY";
		string exchange2 = "USD";
		double rate2 = 0.14;
		ExchangeRate Rate2(source2, exchange2, rate2);
		rates.push_back(Rate2);
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
		string currency2 = "USD";
		result2 = shares[name2].getTotal(currency2);
		k--;
	}
	rates.clear();
	persons.clear();
	shares.clear();
	if (result1 - (200000 + 25000) < MINIMUM && result2 - ((25000 + 10000) * 0.14 + 50000) < MINIMUM) {
		return "pass";
	}
	else {
		cout << result1 << "\t" << result2 << endl;
		return "false";
	}
}