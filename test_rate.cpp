#include"invest.h"
string test_rate0() {
	string s = "CNY";
	string e = "USD";
	double r = 0.139;
	ExchangeRate rate(s, e, r);
	if (rate.source == s && rate.exchange == e && rate.rate == r) {
		return "pass";
	}
	else {
		return "false";
	}
}
//测试简单间接汇率换算
string test_rate1() {
	string source1 = "CNY";
	string exchange1 = "JPY";
	double rate1 = 22;
	ExchangeRate Rate1(source1, exchange1, rate1);
	rates.push_back(Rate1);

	string source2 = "CNY";
	string exchange2 = "USD";
	double rate2 = 0.14;
	ExchangeRate Rate2(source2, exchange2, rate2);
	rates.push_back(Rate2);
	
	rates.clear();
	if (findRateBFS("JPY", "USD") - 1.0 / 22 * 0.14 < MINIMUM) {
		return "pass";
	}
	else {
		return "false";
	}
}

//测试较复杂间接汇率换算
string test_rate2() {
	string source1 = "CNY";
	string exchange1 = "JPY";
	double rate1 = 20.465;
	ExchangeRate Rate1(source1, exchange1, rate1);
	rates.push_back(Rate1);

	string source2 = "CNY";
	string exchange2 = "USD";
	double rate2 = 0.139;
	ExchangeRate Rate2(source2, exchange2, rate2);
	rates.push_back(Rate2);

	string source3 = "USD";
	string exchange3 = "EUR";
	double rate3 = 0.853;
	ExchangeRate Rate3(source3, exchange3, rate3);
	rates.push_back(Rate3);

	string source4 = "GBP";
	string exchange4 = "JPY";
	double rate4 = 199.75;
	ExchangeRate Rate4(source4, exchange4, rate4);
	rates.push_back(Rate4);

	rates.clear();
	if (findRateBFS("GBP", "USD") - 199.75/20.465*0.139*0.853 < MINIMUM) {
		return "pass";
	}
	else {
		return "false";
	}
}