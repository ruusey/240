/* Copyright
 * Robert Usey
 * 2018 */

#ifndef _YOUR_USERNAME_HERE_HW_2_5_COMPLEX_H_  // NOLINT
#define _YOUR_USERNAME_HERE_HW_2_5_COMPLEX_H_  // NOLINT

using namespace std;

class Complex {
public:

	Complex();
	Complex(double imag);
	Complex(double real, double imag);

	double real() const;
	double imag() const;

	void real(double real);
	void imag(double imag);

	double modulus() const;

	const Complex Add(const Complex& rhs) const;
	const Complex Add(double rhs) const;
	const Complex Add(int rhs) const;

	const Complex operator+(const Complex& rhs) const;
	const Complex operator+(double rhs) const;
	const Complex operator+(int rhs) const;

	const Complex Mul(const Complex& rhs) const;
	const Complex Mul(double rhs) const;
	const Complex Mul(int rhs) const;

	const Complex operator*(const Complex& rhs) const;
	const Complex operator*(double rhs) const;
	const Complex operator*(int rhs) const;

	const string ToString() const;

	friend const Complex operator+(double lhs, const Complex& rhs);
	friend const Complex operator+(int lhs, const Complex& rhs);
	friend const Complex operator*(double lhs, const Complex& rhs);
	friend const Complex operator*(int lhs, const Complex& rhs);
	friend istream& operator>>(istream& lhs, Complex& rhs);
	friend ostream& operator<<(ostream& lhs, const Complex& rhs);
	friend bool operator<(double lhs, const Complex& rhs);
	friend bool operator<(int lhs, const Complex& rhs);
	friend istream& operator>>(istream& lhs, Complex& rhs);

	static bool IsComplex(const string& in_string);
	static bool IsComplex(istream& in_stream);
	static const Complex ToComplex(string& in);

	bool LT(const Complex& rhs) const;
	bool LT(double rhs) const;
	bool LT(int rhs) const;
	bool operator<(const Complex& rhs) const;
	bool operator<(double rhs) const;
	bool operator<(int rhs) const;


private:
	double r;
	double i;
};

#endif
