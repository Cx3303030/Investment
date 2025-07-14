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
		cout << "1-����¼��  2-��ƱͶ��  3-Ͷ�ʲ�ѯ  0-�˳�" << endl;
		int way;
		cin >> way;
		if (way == 1) {
			cout << "���������������" << endl;
			int num;
			cin >> num;
			cout << "�����������׼���ң��һ����ң�����" << endl;
			for (int i = 0; i < num; i++) {
				string source, exchange;
				double rate;
				cin >> source >> exchange >> rate;
				ExchangeRate Rate(source, exchange, rate);
				rates.push_back(Rate);
			}
		}
		else if (way == 2) {
			cout << "�����뽻��������" << endl;
			int num;
			cin >> num;
			cout << "�����������Ʊ���ͣ�Ͷ�����������ֹɻ��ң��ֹ��������ֹɼ۸�" << endl;
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
			cout << "�������ѯ������" << endl;
			int num;
			cin >> num;
			cout << "�����������ѯ����PERSON/STOCK�����������ƣ���������" << endl;
			for (int i = 0; i < num; i++) {
				string mode, name, currency;
				cin >> mode >> name >> currency;
				if (mode == "PERSON") {
					if (persons.find(name) != persons.end()) {
						cout << name << "�ϼ�" << currency << "�ʲ�Ϊ��"
							<< persons[name].getpTotal(currency) << endl;
					}
					else {
						cout << "��ѯ��Ͷ���߲����ڣ�" << endl;
					}
				}
				else if (mode == "STOCK") {
					if (shares.find(name) != shares.end()) {
						cout << name << "�ɺϼ�" << currency << "Ϊ��"
							<< shares[name].getTotal(currency) << endl;
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
		}
		else if (way == 0) {
			break;
		}
		else {
			cout << "��������Ч��ģʽ���֣�" << endl;
			continue;
		}
	}
	return 0;
}
