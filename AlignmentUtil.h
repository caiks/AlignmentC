#ifndef ALIGNMENTUTIL_H
#define ALIGNMENTUTIL_H

#include <iostream>
#include <memory>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <vector>

// Rational from https://gist.github.com/sklaw/10473569
class Rational {
    friend Rational operator+(const Rational& left, const Rational& right);
    friend Rational operator-(const Rational& left, const Rational& right);
    friend Rational operator*(const Rational& left, const Rational& right);
    friend Rational operator/(const Rational& left, const Rational& right);
    friend bool operator==(const Rational& left, const Rational& right);
    friend bool operator!=(const Rational& left, const Rational& right);
    friend bool operator<(const Rational& left, const Rational& right);
    friend bool operator>(const Rational& left, const Rational& right);
    friend bool operator<=(const Rational& left, const Rational& right);
    friend bool operator>=(const Rational& left, const Rational& right);
    friend std::ostream& operator<<(std::ostream& out, const Rational& obj);
    friend std::istream& operator >> (std::istream& in, Rational& obj);

public:
    Rational();
    Rational(double x);
    Rational(int numerator_, int denominator_ = 1);

    Rational& operator=(const Rational& obj);
    Rational& operator+=(const Rational& obj);
    Rational& operator-=(const Rational& obj);
    Rational& operator*=(const Rational& obj);
    Rational& operator/=(const Rational& obj);
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);
    Rational operator+() const;
    Rational operator-() const;

    void setNumerator(int numerator_);
    int getNumerator() const;
    void setDenominator(int denominator_);
    int getDenominator() const;

private:
    int numerator;
    int denominator;
    void simplify();
};


template<class T> std::ostream& operator<<(std::ostream& _out, const std::set<T>& _qq)
{
    _out << "{";
    for (auto it = _qq.begin(); it != _qq.end(); ++it)
    {
	if (it != _qq.begin())
	    _out << ",";
	_out << *it;
    }
    _out << "}";
    return _out;
}

template<class T> std::ostream& operator<<(std::ostream& _out, const std::unordered_set<T>& _qq)
{
    _out << "{";
    for (auto it = _qq.begin(); it != _qq.end(); ++it)
    {
	if (it != _qq.begin())
	    _out << ",";
	_out << *it;
    }
    _out << "}";
    return _out;
}

template<class Key, class T> std::ostream& operator<<(std::ostream& _out, const std::map<Key,T>& _qq)
{
    _out << "{";
    for (auto it = _qq.begin(); it != _qq.end(); ++it)
    {
	if (it != _qq.begin())
	    _out << ",";
	_out << "(" << it->first << "," << it->second << ")";
    }
    _out << "}";
    return _out;
}

template<class Key, class T> std::ostream& operator<<(std::ostream& _out, const std::unordered_map<Key,T>& _qq)
{
    _out << "{";
    for (auto it = _qq.begin(); it != _qq.end(); ++it)
    {
	if (it != _qq.begin())
	    _out << ",";
	_out << "(" << it->first << "," << it->second << ")";
    }
    _out << "}";
    return _out;
}

template<class T, std::size_t N > std::ostream& operator<<(std::ostream& _out, const std::array<T,N>& _qq)
{
    _out << "[";
    for (auto it = _qq.begin(); it != _qq.end(); ++it)
    {
	if (it != _qq.begin())
	    _out << ",";
	_out << *it;
    }
    _out << "]";
    return _out;
}

template<class T> std::ostream& operator<<(std::ostream& _out, const std::vector<T>& _qq)
{
    _out << "[";
    for (auto it = _qq.begin(); it != _qq.end(); ++it)
    {
	if (it != _qq.begin())
	    _out << ",";
	_out << *it;
    }
    _out << "]";
    return _out;
}

#endif