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
#include <algorithm>

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
    Rational(long long numerator_, long long denominator_ = 1);
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

    void setNumerator(long long numerator_);
    long long getNumerator() const;
    void setDenominator(long long denominator_);
    long long getDenominator() const;
    double getDouble() const;

private:
    long long numerator;
    long long denominator;
    void simplify();
};

template<class T> std::set<T> sorted(const std::unordered_set<T>& qq)
{
    return std::set<T>(qq.begin(),qq.end());
}

template<class T> std::vector<T> sorted(const std::vector<T>& qq)
{
    auto rr = qq;
    std::sort(rr.begin(), rr.end());
    return rr;
}

template<class Key, class T> std::map<Key,T> sorted(const std::unordered_map<Key, T>& qq)
{
    return std::map<Key,T>(qq.begin(), qq.end());
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
	out << *it << std::endl;
    }
}

template<class T> void rpln(std::ostream& out, const std::set<T>& qq)
{
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	out << *it << std::endl;
    }
}

template<typename T> struct Tree
{
    std::vector<std::pair<T,Tree<T>>> _list;

    void sort()
    {
	struct {
	    bool operator()(std::pair<T, Tree<T>> a, std::pair<T, Tree<T>> b) const
	    {
		return a.first < b.first;
	    }
	} lesser;
	std::sort(_list.begin(), _list.end(), lesser);
	for (auto it = _list.begin(); it != _list.end(); ++it)
	    it->second.sort();
    }

};

template<typename T> int treesSize(const Tree<T>& tt)
{
    int s = 0;
    for (auto& pp : tt._list)
	s += 1 + treesSize(pp.second);
    return s;
}

// treesElements :: (Ord a, Ord (Tree a)) => Tree a -> Set.Set a
template<typename T> std::unique_ptr<std::vector<T>> treesElements(const Tree<T>& tt)
{
    auto qq = std::make_unique<std::vector<T>>();
    qq->reserve(treesSize(tt));
    for (auto& pp : tt._list)
    {
	qq->push_back(pp.first);
	auto ee = treesElements(pp.second);
	qq->insert(qq->end(), ee->begin(), ee->end());
    }
    return qq;
}

template<typename T> std::vector<std::vector<T>> treesPaths(const std::vector<T>& ll, const Tree<T>& xx)
{
    if (xx._list.size() == 0)
	return std::vector<std::vector<T>>{ll};
    std::vector<std::vector<T>> qq;
    for (auto it = xx._list.begin(); it != xx._list.end(); ++it)
    {
	auto jj = ll;
	jj.push_back(it->first);
	auto yy = treesPaths(jj, it->second);
	qq.insert(qq.end(), yy.begin(), yy.end());
    }
    return qq;
}

// treesPaths :: (Ord a, Ord (Tree a)) => Tree a -> [[a]]
template<typename T> std::vector<std::vector<T>> treesPaths(const Tree<T>& tt)
{
    return treesPaths(std::vector<T>(),tt);
}

// pairTreesUnion :: (Ord a, Ord (Tree a)) => Tree a -> Tree a -> Tree a
template<typename T> Tree<T> pairTreesUnion(const Tree<T>& ss,const Tree<T>& tt)
{
    if (tt._list.size() == 0)
	return ss;
    if (ss._list.size() == 0)
	return tt;
    auto rr = ss;
    for (int i = 0; i < tt._list.size(); i++)
    {
	bool found = false;
	for (int j = 0; !found && j < ss._list.size(); j++)
	    if (tt._list[i].first == ss._list[j].first)
	    {
		found = true;
		rr._list[j].second = pairTreesUnion(ss._list[j].second, tt._list[i].second);
	    }
	if (!found)
	    rr._list.push_back(tt._list[i]);
    }
    return rr;
}

// pathsTree :: (Ord a, Ord (Tree a)) => [[a]] -> Tree a
template<typename T> Tree<T> pathsTree(const std::vector<std::vector<T>>& qq)
{
    Tree<T> tt;
    for (auto& ll : qq)
    {
	if (ll.size() > 0)
	{
	    Tree<T> ss;
	    auto jj = ll;
	    jj.erase(jj.begin());
	    std::vector<std::vector<T>> rr{ jj };
	    ss._list.push_back(std::pair<T, Tree<T>>(ll[0], pathsTree(rr)));
	    tt = pairTreesUnion(tt, ss);
	}
    }
    return tt;
}


template<typename T> std::ostream& operator<<(std::ostream& out, const Tree<T>& tt)
{
    out << "{";
    for (auto it = tt._list.begin(); it != tt._list.end(); ++it)
    {
	if (it != tt._list.begin())
	    out << ",";
	out << "(" << it->first << "," << it->second << ")";
    }
    out << "}";
    return out;
}

#endif