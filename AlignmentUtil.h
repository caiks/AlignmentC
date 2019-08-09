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

template<class T> std::set<T> sorted(const std::unordered_set<T>& qq)
{
    return std::set<T>(qq.begin(),qq.end());
}

template<class T1,class T2> std::ostream& operator<<(std::ostream& out, const std::pair<T1,T2>& qq)
{
    out << "(" << qq.first << "," << qq.second << ")";
    return out;
}

template<class T> std::ostream& operator<<(std::ostream& out, const std::set<T>& qq)
{
    out << "{";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << *it;
    }
    out << "}";
    return out;
}

template<class T> std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& qq)
{
    out << "{";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << *it;
    }
    out << "}";
    return out;
}

template<class Key, class T> std::ostream& operator<<(std::ostream& out, const std::map<Key,T>& qq)
{
    out << "{";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << "(" << it->first << "," << it->second << ")";
    }
    out << "}";
    return out;
}

template<class Key, class T> std::ostream& operator<<(std::ostream& out, const std::unordered_map<Key,T>& qq)
{
    out << "{";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << "(" << it->first << "," << it->second << ")";
    }
    out << "}";
    return out;
}

template<class T, std::size_t N > std::ostream& operator<<(std::ostream& out, const std::array<T,N>& qq)
{
    out << "[";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << *it;
    }
    out << "]";
    return out;
}

template<class T> std::ostream& operator<<(std::ostream& out, const std::vector<T>& qq)
{
    out << "[";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << *it;
    }
    out << "]";
    return out;
}

template<class T> void rpln(std::ostream& out, const std::vector<T>& qq)
{
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	out << *it << endl;
    }
}


#endif