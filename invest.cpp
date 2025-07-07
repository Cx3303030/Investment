#include"invest.h"

vector<ExchangeRate> rates;
map<string, Person> persons;


double FindRate(string s, string e,double money) {
	if (s == e)return money;
	double n = money;
	for (int i = 0; i < rates.size(); i++) {
		ExchangeRate Rate = rates[i];
		if (Rate.source == s && Rate.exchange == e) {
			n *= Rate.rate;
			return n;
		}
		else if (Rate.source == e && Rate.exchange == s) {
			n /= Rate.rate;
			return n;
		}
	}
	return n;
}

double Share::totals = 0;

void Share::invest(string investor, string currency, int number, double price) {
	if (persons.find(investor) == persons.end()) {
		Person person(investor, currency, number, price);
		persons[investor] = person;
	}
	double total = FindRate(currency, "CNY", number * price);        //���⣺û����ǰ������ʻ�ֱ�ӵ���totals������
	totals += total;
	persons[investor].changeTotal(total);
}


