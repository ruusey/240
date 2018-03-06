/* Copyright
 * Robert Usey
 * 2018 */
#include <iostream>
#include <cmath>
#include "complex.h"
#include <regex>
#include <assert.h>
#include <exception>
#include <algorithm>
#include <string>

//push ez button
static regex cpRegex_(
		"^\\({1}(\\s*)([+|-]*)(\\d)*(\\.)*(\\d)*(\\s)*[+|-]*(\\s)*(\\d)*(\\.)*(\\d)*(\\s)*[i]*(\\s)*\\){1}");

Complex::Complex() {

	this->r = 0.0;
	this->i = 0.0;
}
Complex::Complex(double i) {
	this->r = 0.0;
	this->i = i;
}
Complex::Complex(double r, double i) {
	this->r = r;
	this->i = i;
}
void Complex::real(double r) {
	this->r = r;
}
double Complex::real() const {
	return this->r;
}
void Complex::imag(double i) {
	this->i = i;
}
double Complex::imag() const {
	return this->i;
}
const Complex Complex::Add(int rhs) const {
	Complex temp(real() + rhs, imag());
	return temp;
}
const Complex Complex::Add(double rhs) const {
	Complex temp(real() + rhs, imag());
	return temp;
}
const Complex Complex::Add(const Complex& rhs) const {
	Complex temp(real() + rhs.real(), imag() + rhs.imag());
	return temp;
}
const Complex Complex::operator+(int rhs) const {
	return Add(rhs);
}
const Complex Complex::operator+(double rhs) const {
	return Add(rhs);
}
const Complex Complex::operator+(const Complex& rhs) const {
	return Add(rhs);
}
const Complex operator+(double lhs, const Complex& rhs) {
	return rhs.Add(lhs);
}
const Complex operator+(int lhs, const Complex& rhs) {
	return rhs.Add(lhs);
}
const Complex Complex::operator*(int rhs) const {
	return Mul(rhs);
}
const Complex Complex::operator*(double rhs) const {
	return Mul(rhs);
}
const Complex Complex::operator*(const Complex& rhs) const {
	return Mul(rhs);
}
const Complex operator*(double lhs, const Complex& rhs) {
	return rhs.Mul(lhs);
}
const Complex operator*(int lhs, const Complex& rhs) {
	return rhs.Mul(lhs);
}
const Complex Complex::Mul(int rhs) const {
	Complex temp(real() * rhs, imag() * rhs);

	return temp;
}
const Complex Complex::Mul(double rhs) const {
	Complex temp(real() * rhs, imag() * rhs);
	return temp;
}
const Complex Complex::Mul(const Complex& rhs) const {
	double r = (real() * rhs.imag()) + (imag() * rhs.real());
	double i = (real() * rhs.real()) - (imag() * rhs.imag());
	Complex temp(r, i);
	return temp;
}
const Complex Complex::ToComplex(string& in) {
	bool validComplex = false;
	//SEE IF OUR REGEX MATCHES THE INPUT
	try {
		validComplex = regex_match(in, cpRegex_);
		//IF NOT VALID COMPLEX THROW INVALID ARG EXCEPTION
		if (!validComplex)
			throw invalid_argument(in);
	} catch (const invalid_argument& exception) {
		cerr << "Invalid complex syntax exception. Your syntax for '"
				<< exception.what() << "' is invalid...";
		Complex temp = Complex();
		return temp;
	}
	//REMOVE WHITE SPACE AND PARENS TO MAKE PARSING EASIER
	string temp;
	for (char c : in)
		if (!isspace(c) && (c != '(') && (c != ')'))
			temp += c;
	in = temp;

	int index = in.find("+");
	if (index > -1) {
		string lhs = in.substr(0, index);
		string rhs = in.substr(index + 1, in.length() - 1);
		double r = atof(lhs.c_str());
		double i = atof(rhs.c_str());
		Complex temp(r, i);
		return temp;
	}
	index = in.find("-", 1);
	if (index > 0) {
		string lhs = in.substr(0, index);
		string rhs = in.substr(index, in.length() - 1);

		double r = atof(lhs.c_str());
		double i = atof(rhs.c_str());
		Complex temp(r, i);
		return temp;
	}
	index = in.find("i");
	if (index > -1) {
		string single = in.substr(0, index);
		if (single.length() == 0) {
			Complex temp(1.0);
			return temp;
		} else {
			double i = atof(single.c_str());
			if (i == 0.0) {
				Complex temp(-1.0);
				return temp;
			} else {
				Complex temp(i);
				return temp;
			}
		}
	} else {
		Complex temp(-1.0);
		return temp;
	}
}
ostream& operator <<(ostream &out, Complex &c) {
	out << c.ToString() << endl;
	return out;
}
istream& operator >>(istream &in, Complex &c) {
	string input;
	in >> input;
	c = Complex::ToComplex(input);
	return in;
}
const string Complex::ToString() const {
	//BASE CASES
	if (this->r == 0.0 && this->i == 0.0){
		return string("(0)");
	}else if(this->i == 1.0){
		return string("(i)");
	}

	string res = "(";
	char r[to_string(this->r).length() + 1];
	char i[to_string(this->i).length() + 1];
	snprintf(r, sizeof r, "%g", this->r);
	string rStr(r);
	snprintf(i, sizeof i, "%g", this->i);
	string iStr(i);
	if (this->r != 0.0) {
		res += rStr;
	}
	if (this->i == 0.0) {
		return res;
	} else if (this->i == 1.0) {
		res += "i";
		return res;
	} else if (this->i > 1.0 && this->r == 0) {
		res += iStr + "i";
	} else if (this->i > 1.0) {
		res += "+" + iStr + "i";
	} else if (this->i == -1.0) {
		res += "-i";
	} else {
		res += iStr + "i";
	}
	res = res + ')';
	return res;
}
bool Complex::LT(const Complex& rhs) const {
	return (modulus() < rhs.modulus());
}

bool Complex::LT(double rhs) const {
	Complex temp(rhs, 0.0);
	return (modulus() < temp.modulus());
}

bool Complex::LT(int rhs) const {
	Complex temp(rhs, 0.0);
	return (modulus() < temp.modulus());
}

bool Complex::operator <(const Complex& rhs) const {
	return this->LT(rhs);
}

bool Complex::operator <(double rhs) const {
	return this->LT(rhs);
}

bool Complex::operator <(int rhs) const {
	return this->LT(rhs);
}

bool Complex::IsComplex(const string& in_string) {
	return regex_match(in_string, cpRegex_);
}

bool Complex::IsComplex(istream& in_stream) {
	string complex;
	//READ CHARACTERS FROM ISTREAM UNTIL THERE ARE
	//NO MORE THEN ASSIGN IT TO A VARIABLE, PUT THE CHARACTER BACK, APPEND IT TO OUR RESULT STRING
	while (true) {
		char c = in_stream.get();
		if (c == 0) {
			in_stream.putback(c);
			break;
		}
		complex += c;
		in_stream.putback(c);
	}
	string test;
	in_stream >> test;
	cout << test;
	return IsComplex(complex);
}
double Complex::modulus() const {
	//THAT MOD THING FROM INSTRUCTION
	double i_ = this->i * this->i;
	double r_ = this->r * this->r;
	return sqrt(r_ + i_);
}
//FOR TESTING - all cases here work
//int main() {
//	string temp = "(i)";
//	cout << "Type a correctly formatted complex #" << endl;
//
//	cout << Complex::ToComplex(temp).ToString() << endl;
//	Complex r(4.2, 5.5);
//	Complex s(18.9, 31.7);
//
//	cout << "Testing ToString" << endl;
//	cout << "Complex s: " << s.ToString() << endl;
//	cout << "Complex r: " << r.ToString() << endl;
//
//	cout << "Testing addition (r+s)" << endl;
//	cout << (r + s).ToString() << endl;
//	cout << "Testing addition (r+5)" << endl;
//	cout << (r + 5).ToString() << endl;
//	cout << "Testing addition (r+3.14)" << endl;
//	cout << (r + 3.14).ToString() << endl;
//	cout << "Testing multiplication (r*s)" << endl;
//	cout << (r * s).ToString() << endl;
//	cout << "Testing multiplication (r*5)" << endl;
//	cout << (r * 5).ToString() << endl;
//	cout << "Testing multiplication (r*3.14)" << endl;
//	cout << (r * 3.14).ToString() << endl;
//	cout << "Testing less than (r<s)" << endl;
//	cout << (r < s) << endl;
//	cout << "Testing less than (r<5)" << endl;
//	cout << (r < 5) << endl;
//	cout << "Testing less than (r<9999.98)" << endl;
//	cout << (r < 9999.98) << endl;
//	cout << "Testing IsComplex" << endl;
//
//	string cmxTest1 = "(   +15.123 -  4.1i)";
//	string cmxTest2 = "( -15.123 )";
//	string cmxTest3 = "( -  4.1i)";
//	string cmxTest4 = "(-i)";
//	string cmxTest5 = "(22.12)";
//	cout << cmxTest1 << endl;
//	cout << Complex::IsComplex(cmxTest1) << endl;
//	cout << cmxTest2 << endl;
//	cout << Complex::IsComplex(cmxTest2) << endl;
//	cout << cmxTest3 << endl;
//	cout << Complex::IsComplex(cmxTest3) << endl;
//	cout << cmxTest4 << endl;
//	cout << Complex::IsComplex(cmxTest4) << endl;
//	cout << cmxTest5 << endl;
//	cout << Complex::IsComplex(cmxTest5) << endl;
//}
