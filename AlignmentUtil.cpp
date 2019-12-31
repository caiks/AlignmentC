#include "AlignmentUtil.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits.h>

//using namespace Alignment;


// Rational

using namespace std;

long long absInt(long long x) {
    if (x >= 0) {
	return x;
    }
    else {
	return -x;
    }
}

void getFactors(long long num, vector<long long>& factorSet) {
    if (num != 1) {
	factorSet.push_back(num);
    }
    for (long long i = 2; i <= sqrt(static_cast<double>(num)); i++) {
	if (num%i == 0) {
	    factorSet.push_back(i);
	    factorSet.push_back(num / i);
	}
    }
}

void simplifyFun(long long& a, long long& b) {
    long long tempN = a;
    long long tempD = b;
    long long small, temp;
    vector<long long> factorSet;
    if (tempN == tempD) {
	a = 1;
	b = 1;
	return;
    }
    else if (tempN == -tempD) {
	a = -1;
	b = 1;
	return;
    }
    else if (tempN == 0) {
	b = 1;
	return;
    }


    if (absInt(tempN) < absInt(tempD)) {
	small = absInt(tempN);
    }
    else {
	small = absInt(tempD);
    }

    getFactors(small, factorSet);
    for (size_t i = 0; i < factorSet.size(); i++) {
	temp = factorSet[i];
	while (tempN%temp == 0 && tempD%temp == 0) {
	    tempN /= temp;
	    tempD /= temp;
	}
    }
    a = tempN;
    b = tempD;
}


//friend functions definitions
Rational operator+(const Rational& left, const Rational& right) {
    Rational temp;
    long long tempLD = left.getDenominator();
    long long tempRD = right.getDenominator();
    simplifyFun(tempLD, tempRD);
    temp.setDenominator(left.getDenominator()*tempRD);
    temp.setNumerator(left.getNumerator()*tempRD + right.getNumerator()*tempLD);
    temp.simplify();
    return temp;
}

Rational operator-(const Rational& left, const Rational& right) {
    return left + (-right);
}

Rational operator*(const Rational& left, const Rational& right) {
    Rational temp;
    Rational temp_2(right.getNumerator(), left.getDenominator());
    Rational temp_3(left.getNumerator(), right.getDenominator());
    long long a = temp_2.getDenominator();
    long long b = temp_2.getNumerator();
    long long c = temp_3.getDenominator();
    long long d = temp_3.getNumerator();
    temp.setNumerator(b*d);
    temp.setDenominator(a*c);
    return temp;
}

Rational operator/(const Rational& left, const Rational& right) {
    Rational temp_1(left.getNumerator(), left.getDenominator());
    Rational temp_2(right.getDenominator(), right.getNumerator());
    return temp_1*temp_2;
}

bool operator==(const Rational& left, const Rational& right) {
    return (left.numerator == right.numerator && left.denominator == right.denominator);
}

bool operator!=(const Rational& left, const Rational& right) {
    return !(left == right);
}

bool operator<(const Rational& left, const Rational& right) {
    long long lside = left.getNumerator()*right.getDenominator();
    long long rside = left.getDenominator()*right.getNumerator();
    return (lside < rside);
}

bool operator>(const Rational& left, const Rational& right) {
    long long lside = left.getNumerator()*right.getDenominator();
    long long rside = left.getDenominator()*right.getNumerator();
    return (lside > rside);
}

bool operator<=(const Rational& left, const Rational& right) {
    return ((left < right) || (left == right));
}

bool operator>=(const Rational& left, const Rational& right) {
    return ((left > right) || (left == right));
}

ostream& operator<<(ostream& out, const Rational& obj) {
    out << obj.numerator;
//    if (obj.numerator != 0 && obj.denominator != 1) {
//	out << "%" << obj.denominator;
	out << " % " << obj.denominator;
    //    }
    return out;
}

istream& operator >> (istream& in, Rational& obj) {
    string inputstr;
    long long num = 0;
    long long sign = 1;
    bool slashExist = false;
    bool dotExist = false;
    bool validInput = true;
    long long virtualDenominator = 1;
    cin >> inputstr;
    for (size_t i = 0; i < inputstr.size(); i++) {
	char temp = inputstr[i];
	if (temp == '.') {
	    if (dotExist == false && slashExist == false && i != 0) {
		dotExist = true;
	    }
	    else {
		validInput = false;
		break;
	    }
	}
	else if (temp == '/') {
	    if (dotExist == false && slashExist == false && i != 0) {
		slashExist = true;
		obj.setNumerator(sign*num);
		num = 0;
		sign = 1;
	    }
	    else {
		validInput = false;
		break;
	    }
	}
	else if (temp == '-') {
	    if (i == 0) {
		sign = -sign;
	    }
	    else if (inputstr[i - 1] == '/') {
		sign = -sign;
	    }
	    else {
		validInput = false;
		break;
	    }
	}
	else if (temp <= '9' && temp >= '0') {
	    if (dotExist) {
		if (virtualDenominator > INT_MAX / 10) {
		    throw std::out_of_range("operator>>(istream& in, Rational& obj)");
		    validInput = false;
		    break;
		}
		else {
		    virtualDenominator *= 10;
		}
	    }
	    if (num > INT_MAX / 10) {
		throw std::out_of_range("operator>>(istream&, Rational&)");
		validInput = false;
		break;
	    }
	    num *= 10;
	    num += inputstr[i] - '0';
	}
	else {
	    validInput = false;
	    break;
	}
    }

    if (validInput == false) {
	obj.setNumerator(0);
	obj.setDenominator(1);
	throw std::out_of_range("operator>>(istream&, Rational&)");
    }
    else {
	if (slashExist == true) {
	    obj.setDenominator(sign*num);
	}
	else if (dotExist) {
	    obj.setNumerator(sign*num);
	    obj.setDenominator(virtualDenominator);
	}
	else {
	    obj.setNumerator(sign*num);
	    obj.setDenominator(1);
	}
    }
    obj.simplify();
    return in;
}




//member function definition
Rational::Rational() {
    setNumerator(0);
    setDenominator(1);
}

Rational::Rational(double x) {
    long long i = 1;
    while (x*i - static_cast<long long>(x*i) != 0) {
	if (i > INT_MAX / 10) {
	    throw std::out_of_range("Rational::Rational(double)");
	    setNumerator(0);
	    setDenominator(1);
	    return;
	}
	else {
	    i *= 10;
	}
    }
    setNumerator((long long)x*i);
    setDenominator(i);
    simplify();
}

Rational::Rational(long long numerator_, long long denominator_) {
    setNumerator(numerator_);
    setDenominator(denominator_);
    simplify();
}

Rational::Rational(int numerator_, int denominator_) {
    setNumerator(numerator_);
    setDenominator(denominator_);
    simplify();
}

Rational& Rational::operator=(const Rational& obj) {
    setNumerator(obj.getNumerator());
    setDenominator(obj.getDenominator());
    return *this;
}

Rational& Rational::operator+=(const Rational& obj) {
    *this = *this + obj;
    return *this;
}

Rational& Rational::operator-=(const Rational& obj) {
    *this = *this - obj;
    return *this;
}

Rational& Rational::operator*=(const Rational& obj) {
    *this = *this*obj;
    return *this;
}

Rational& Rational::operator/=(const Rational& obj) {
    *this = *this / obj;
    return *this;
}
Rational& Rational::operator++() {
    *this = *this + 1;
    return *this;
}

Rational Rational::operator++(int) {
    Rational before = *this;
    *this = *this + 1;
    return before;
}

Rational& Rational::operator--() {
    *this = *this - 1;
    return *this;
}

Rational Rational::operator--(int) {
    Rational before = *this;
    *this = *this - 1;
    return before;
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    Rational temp;
    temp.setNumerator(-getNumerator());
    temp.setDenominator(getDenominator());
    return temp;
}

void Rational::setNumerator(long long numerator_) {
    numerator = numerator_;
}

long long Rational::getNumerator() const {
    return numerator;
}

void Rational::setDenominator(long long denominator_) {
    if (denominator_ == 0) {
	denominator = 1;
	numerator = 0;
	throw std::out_of_range("Rational::setDenominator");
    }
    else {
	denominator = denominator_;
    }
}

long long Rational::getDenominator() const {
    return denominator;
}

double Rational::getDouble() const {
    return (double)getNumerator()  / (double)getDenominator();
}

void Rational::simplify() {
    long long tempN = numerator;
    long long tempD = denominator;
    simplifyFun(tempN, tempD);
    setNumerator(tempN);
    setDenominator(tempD);
}

