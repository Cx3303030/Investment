#include"invest.h"

int main() {
	map<string, Share> shares;
	while (1) {
		cout << "1-汇率录入  2-股票投资  3-投资查询  0-退出" << endl;
		int way;
		cin >> way;
		if (way == 1) {
			cout << "请输入汇率行数：" << endl;
			int num;
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "请依次输入基准货币，计价货币，汇率" << endl;
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
							<< FindRate("CNY", currency, persons[name].getpTotal()) << endl;
					}
					else {
						cout<< "查询的投资者不存在！" << endl;
					}
				}
				else if (mode == "STOCK") {
					if (shares.find(name) != shares.end()) {
						cout << name << "股合计" << currency << "为：" 
							<< FindRate("CNY",currency,shares[name].getTotal()) << endl;
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
		else if(way == 0){
			break;
		}
		else {
			cout << "请输入有效的模式数字！" << endl;
			continue;
		}
	}
	return 0;
}
