#include"invest.h"

int main() {
	
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string name, investor, currency;
		double price;
		int number;
		cin >> name >> investor >> currency >> number >> price;
		if (shares.find(name) == shares.end()) {
			Share share(name);
			shares[name] = share;
		}
		shares[name].invest(investor, currency, number, price);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string source, exchange;
		double rate;
		cin >> source >> exchange >> rate;
		ExchangeRate Rate(source, exchange, rate);
		rates.push_back(Rate);
	}

	int nm;
	cin >> nm;
	for (int i = 0; i < nm; i++) {
		string mode, name, currency;
		cin >> mode >> name >> currency;
		if (mode == "PERSON") {
			if (persons.find(name) != persons.end()) {
				cout << persons[name].getpTotal(currency) << endl;
			}
			else {
				cout << "查询的投资者不存在！" << endl;
			}
		}
		else if (mode == "STOCK") {
			if (shares.find(name) != shares.end()) {
				cout << shares[name].getTotal(currency) << endl;
			}
			else {
				cout << "查询的股票不存在！" << endl;
			}
		}
		else {
			cout << "请输入正确的查询对象！" << endl;
			i--;
		}
	}
	return 0;
}
