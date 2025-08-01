#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

const double MINIMUM = 1e-6;

string test_rate0();
string test_rate1();
string test_rate2();
string test_invest();
string test_person();
string test_share();
string test1();
string test2();


void buildGraph();
double FindRate(string s, string e, double money);
double findRateBFS(string source, string target);

class ExchangeRate;
class Person;
class Share;

extern vector<ExchangeRate> rates;
extern map<string, Person> persons;
extern map<string, Share> shares;
extern map<string, map<string, double>> graph;  //管理间接汇率


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
	string getCurrency() { return currency; }
	double getPrice() { return price; }
	int getNumble() { return number; }
};

class Person {
private:
	string name;
	double pTotals;
public:
	vector<Invest> investments;
	Person() : name(""), pTotals(0.0) {}; 	
	Person(string name) : name(name), pTotals(0.0) {}
	Person(const Person& other);
	Person& operator = (const Person& other){
		name = other.name;
		pTotals = other.pTotals;
		investments = other.investments;
		return *this;
	}
	void invest(string currency, int number, double price);
	double getpTotal(string e);
	string getName() { return name; }
};

class Share {
private:
	string name;
	double totals;
public:
	map<string,Person> investors;
	Share():name(""),totals(0.0) {};
	Share(string name) :name(name),totals(0.0) {}
	void invest(string investor, string currency, int number, double price);
	double getTotal(string e);
	string getName() { return name; }
};
