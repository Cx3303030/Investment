#include"invest.h"

int main() {

	cout << "test_rate0:\t" << test_rate0() << endl;
	cout << "test_rate1:\t" << test_rate1() << endl;
	cout << "test_rate2:\t" << test_rate2() << endl;
	cout << "test_invest:\t" << test_invest() << endl;
	cout << "test_person:\t" << test_person() << endl;
	cout << "test_share:\t" << test_share() << endl;
	cout << "test1:\t\t" << test1() << endl;
	cout << "test2:\t\t" << test2() << endl;

	while (1) {
		cout << "1-汇率录入  2-股票投资  3-投资查询  0-退出" << endl;
		int way;
		cin >> way;
		if (way == 1) {
			cout << "请输入汇率行数：" << endl;
			int num;
			cin >> num;
			cout << "请依次输入基准货币，兑换货币，汇率" << endl;
			for (int i = 0; i < num; i++) {
				string source, exchange;
				double rate;
				cin >> source >> exchange >> rate;
				ExchangeRate Rate(source, exchange, rate);
				rates.push_back(Rate);
			}
		}
		else if (way == 2) {
			cout << "请输入交易数量：" << endl;
			int num;
			cin >> num;
			cout << "请依次输入股票类型，投资者姓名，持股货币，持股数量，持股价格" << endl;
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
		}
		else if (way == 3) {
			cout << "请输入查询次数：" << endl;
			int num;
			cin >> num;
			cout << "请依次输入查询对象（PERSON/STOCK），对象名称，货币类型" << endl;
			for (int i = 0; i < num; i++) {
				string mode, name, currency;
				cin >> mode >> name >> currency;
				if (mode == "PERSON") {
					if (persons.find(name) != persons.end()) {
						cout << name << "合计" << currency << "资产为："
							<< persons[name].getpTotal(currency) << endl;
					}
					else {
						cout << "查询的投资者不存在！" << endl;
					}
				}
				else if (mode == "STOCK") {
					if (shares.find(name) != shares.end()) {
						cout << name << "股合计" << currency << "为："
							<< shares[name].getTotal(currency) << endl;
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
		}
		else if (way == 0) {
			break;
		}
		else {
			cout << "请输入有效的模式数字！" << endl;
			continue;
		}
	}
	return 0;
}
