#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

double FindRate(string s, string e, double money);

class ExchangeRate;
class Person;

extern vector<ExchangeRate> rates;
extern map<string, Person> persons;

class ExchangeRate {
public:
	string source, exchange;
	double rate;
	ExchangeRate(string s, string e, double r) :source(s), exchange(e), rate(r) {
		if (s == e)r = 1;
	}
};

class Person {
private:
	string name, currency;
	double price;
	int number;
	double pTotals;
public:
	Person() : name(""), currency(""), number(0), price(0.0), pTotals(0.0) {}; 	
	Person(string name, string currency, int number, double price) :
		name(name), currency(currency), number(number), price(price), pTotals(0.0) {}
	void changeTotal(double number) {
		pTotals += number;
	}
	double getpTotal() { return pTotals; }
};

class Share {
private:
	string name;
	static double totals;
public:
	Share() {};
	Share(string name) :name(name) {}
	double getTotal() { return totals; }
	void invest(string investor, string currency, int number, double price);
};
