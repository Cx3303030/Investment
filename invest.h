#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

double FindRate(string s, string e, double money);

class ExchangeRate;
class Person;
class Share;

extern vector<ExchangeRate> rates;
extern map<string, Person> persons;
extern map<string, Share> shares;

class ExchangeRate {
public:
	string source, exchange;
	double rate;
	ExchangeRate(string s, string e, double r) :source(s), exchange(e), rate(r) {
		if (s == e)r = 1;
	}
};

class Invest {
private:
	string currency;
	double price;
	int number;
public:
	Invest(): currency(""), number(0), price(0.0){};
	Invest(string currency, int number, double price) :
		currency(currency), number(number), price(price){}
	double getValue(string e) { return FindRate(currency, e, price * number); }
};

class Person {
private:
	string name;
	double pTotals;
public:
	vector<Invest> investments;
	Person() : name(""), pTotals(0.0) {}; 	
	Person(string name) : name(name), pTotals(0.0) {}
	double getpTotal(string e) { 
		double pt = 0;
		for (auto investment : investments) {
			pt += investment.getValue(e);
		}
		pTotals = pt;
		return pTotals;
	}
};

class Share {
private:
	string name;
	double totals;
	map<string,Person> investors;
public:
	Share():name(""),totals(0.0) {};
	Share(string name) :name(name),totals(0.0) {}
	void invest(string investor, string currency, int number, double price);
	double getTotal(string e) { 
		double total = 0;
		for (auto i = investors.begin(); i != investors.end();i++) {
			total += i->second.getpTotal(e);
		}
		totals = total;
		return totals;
	}
};
