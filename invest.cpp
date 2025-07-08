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

void Share::invest(string investor, string currency, int number, double price) {
	Person person(investor);
	Invest investment(currency, number, price);
	person.investments.push_back(investment);
	if (persons.find(investor) == persons.end()) {
		persons[investor] = person;
	}
	if (investors.find(investor) == investors.end()) {
		investors[investor] = person;
	}
}


