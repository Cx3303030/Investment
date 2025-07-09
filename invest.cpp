#include"invest.h"

vector<ExchangeRate> rates;
map<string, Person> persons;
map<string, Share> shares;


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

Person::Person(const Person& other) {
	name = other.name;
	pTotals = other.pTotals;
	investments = other.investments;
}

double Person::getpTotal(string e) {
	double pt = 0;
	for (auto investment : investments) {
		pt += investment.getValue(e);
	}
	pTotals = pt;
	return pTotals;
}

void Share::invest(string investor, string currency, int number, double price) {
	Person person(investor);
	Invest investment(currency, number, price);
	if (persons.find(investor) == persons.end()) {
		persons[investor] = person;
	}
	if (investors.find(investor) == investors.end()) {
		investors[investor] = person;
	}
	persons[investor].investments.push_back(investment);
	cout << persons[investor].getpTotal("CNY") << endl;
	investors[investor] = persons[investor];
	cout << investors[investor].getpTotal("CNY") << endl;

}

double Share::getTotal(string e) {
	double total = 0;
	for (auto i = investors.begin(); i != investors.end(); i++) {
		total += i->second.getpTotal(e);
	}
	totals = total;
	return totals;
}


