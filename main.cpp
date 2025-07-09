#include"invest.h"

int main() {
	cout << "test1: " << test1() << endl;
	cout << "test2: " << test2() << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
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

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string mode, name, currency;
		cin >> mode >> name >> currency;
		if (mode == "PERSON") {
			if (persons.find(name) != persons.end()) {
				cout << persons[name].getpTotal(currency) << endl;
			}
			else {
				cout << "��ѯ��Ͷ���߲����ڣ�" << endl;
			}
		}
		else if (mode == "STOCK") {
			if (shares.find(name) != shares.end()) {
				cout << shares[name].getTotal(currency) << endl;
			}
			else {
				cout << "��ѯ�Ĺ�Ʊ�����ڣ�" << endl;
			}
		}
		else {
			cout << "��������ȷ�Ĳ�ѯ����" << endl;
			i--;
		}
	}
	return 0;
}
