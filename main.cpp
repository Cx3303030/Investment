#include"invest.h"

int main() {
	map<string, Share> shares;
	while (1) {
		cout << "1-����¼��  2-��ƱͶ��  3-Ͷ�ʲ�ѯ  0-�˳�" << endl;
		int way;
		cin >> way;
		if (way == 1) {
			cout << "���������������" << endl;
			int num;
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "�����������׼���ң��Ƽۻ��ң�����" << endl;
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
							<< FindRate("CNY", currency, persons[name].getpTotal()) << endl;
					}
					else {
						cout<< "��ѯ��Ͷ���߲����ڣ�" << endl;
					}
				}
				else if (mode == "STOCK") {
					if (shares.find(name) != shares.end()) {
						cout << name << "�ɺϼ�" << currency << "Ϊ��" 
							<< FindRate("CNY",currency,shares[name].getTotal()) << endl;
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
		else if(way == 0){
			break;
		}
		else {
			cout << "��������Ч��ģʽ���֣�" << endl;
			continue;
		}
	}
	return 0;
}
