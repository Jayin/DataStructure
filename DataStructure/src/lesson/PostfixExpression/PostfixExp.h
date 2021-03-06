#ifndef POSTFIXEXP_H_
#define POSTFIXEXP_H_

#include <vector>
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

namespace PostExp {

static string input() {
	string tmp;
	cin >> tmp;
	return tmp;
}

static int get_level(char c) {
	if (c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else // `*` and `/`
		return 2;
}
// 输出后缀表达式
static string get_postfixExp() {
	string raw = input();
	int len = raw.size();
	stack<char> opt;
	vector<string> res;
	string tmp;
	string result;
	for (int i = 0; i < len; i++) {

		if ((raw[i] >= '0' && raw[i] <= '9') || raw[i] == '.') {
			if (i + 1 < len
					&& ((raw[i + 1] >= '0' && raw[i + 1] <= '9')
							|| raw[i + 1] == '.')) {
				tmp += raw[i];
			} else {
				tmp += raw[i];
				res.push_back(tmp);
				tmp.clear();
			}
		} else if (raw[i] == '(') {
			opt.push(raw[i]);
		} else if (raw[i] == ')') {
			while (!opt.empty() && opt.top() != '(') {
				res.push_back(string(1, opt.top()));
				opt.pop();
			}
			//pop the '('
			opt.pop();
		} else {
			//operation
			if (opt.empty()) {
				opt.push(raw[i]);

			} else {
				if (get_level(raw[i]) > get_level(opt.top())) {
					opt.push(raw[i]);
				} else {
					res.push_back(string(1, opt.top()));
					opt.pop();
					opt.push(raw[i]);
				}
			}
		}
	}
	while (!opt.empty()) {
		res.push_back(string(1, opt.top()));
		opt.pop();
	}
	len = res.size();
	for (int i = 0; i < len; i++) {
		result += res[i] + " ";
	}
	return result;
}

// helper for debug
static void print(vector<double> res, stack<char> opt) {
	cout << "res-->";
	for (vector<double>::iterator it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "opt-->";
	while (!opt.empty()) {
		cout << opt.top() << " ";
		opt.pop();
	}
	cout << endl;
}

static double deal_with(vector<double> &res, stack<char> &opt) {
	char opteration = opt.top();
	opt.pop();
	double b = res.back();
	res.pop_back();
	double a = res.back();
	res.pop_back();
	double result = 0;
	if (opteration == '+') {
		result = a + b;
	} else if (opteration == '-')
		result = a - b;
	else if (opteration == '/')
		result = a / b;
	else if (opteration == '*')
		result = a * b;
	return result;
}

//计算表达式的值
static double cal_postfixExp() {
	string raw = input();
	int len = raw.size();
	stack<char> opt;
	vector<double> res;
	string tmp;
	for (int i = 0; i < len; i++) {
		if ((raw[i] >= '0' && raw[i] <= '9') || raw[i] == '.') {
			if (i + 1 < len
					&& ((raw[i + 1] >= '0' && raw[i + 1] <= '9')
							|| raw[i + 1] == '.')) {
				tmp += raw[i];
			} else {
				tmp += raw[i];
				res.push_back(strtod(tmp.c_str(), NULL));
				tmp.clear();
			}
		} else if (raw[i] == '(') {
			opt.push(raw[i]);
		} else if (raw[i] == ')') {
			while (!opt.empty() && opt.top() != '(') {
				double t = deal_with(res, opt);
				res.push_back(t);
			}
			//pop the '('
			opt.pop();
		} else {
			//operation
			if (opt.empty()) {
				opt.push(raw[i]);

			} else {
				if (get_level(raw[i]) > get_level(opt.top())) {
					opt.push(raw[i]);
				} else {
					double t = deal_with(res, opt);
					res.push_back(t);
					opt.push(raw[i]);
				}
			}
		}
	}
	while (!opt.empty()) {
		double t = deal_with(res, opt);
		res.push_back(t);
	}
	return res.back();
}

}

#endif /* POSTFIXEXP_H_ */
