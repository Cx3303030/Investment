#include"invest.h"

vector<ExchangeRate> rates;
map<string, Person> persons;
map<string, Share> shares;
map<string, map<string, double>> graph;  

void buildGraph() {
    graph.clear();
    for (const auto& rate : rates) {
        graph[rate.source][rate.exchange] = rate.rate;
        graph[rate.exchange][rate.source] = 1.0 / rate.rate;  
    }
}

//返回两种货币之间的汇率，source为1，返回值为n倍target
double findRateBFS(string source, string target) {
    if (source == target) return 1.0;

    buildGraph();
    queue<pair<string, double>> q;
    map<string, bool> visited;
    q.push(make_pair(source, 1.0));
    visited[source] = true;

    while (!q.empty()) {
        pair<string, double> front = q.front();
        string current = front.first;
        double rate = front.second;
        q.pop();
        //遍历不同货币间的所有兑换情况
        for (map<string, double>::iterator it = graph[current].begin();
            it != graph[current].end(); ++it) {

            string next = it->first;
            double exchRate = it->second;

            if (!visited[next]) {
                double newRate = rate * exchRate;
                if (next == target) {
                    return newRate;
                }
                q.push(make_pair(next, newRate));
                visited[next] = true;
            }
        }
    }
    return 0.0;
}

double FindRate(string s, string e, double money) {
    double rate = findRateBFS(s, e);
    return money * rate;
}

//复制构造函数
Person::Person(const Person& other) {
	name = other.name;
	pTotals = other.pTotals;
	investments = other.investments;
}

//返回个人资产总值（需提供货币类型）
double Person::getpTotal(string e) {
	double pt = 0;
	for (auto investment : investments) {
		pt += investment.getValue(e);
	}
	pTotals = pt;
	return pTotals;
}
void Person::invest(string currency, int number, double price) {
	Invest investment(currency, number, price);
	investments.push_back(investment);
}
//股票投资
void Share::invest(string investor, string currency, int number, double price) {
	Person person(investor);
	if (persons.find(investor) == persons.end()) {
		persons[investor] = person;
	}
	if (investors.find(investor) == investors.end()) {
		investors[investor] = person;
	}
	persons[investor].invest(currency, number, price);
	investors[investor] = persons[investor];
}

double Share::getTotal(string e) {
	double total = 0;
	for (auto i = investors.begin(); i != investors.end(); i++) {
		total += i->second.getpTotal(e);
	}
	totals = total;
	return totals;
}


