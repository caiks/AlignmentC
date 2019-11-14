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
    std::vector<T> rr(qq);
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
    std::vector<std::pair<T,std::shared_ptr<Tree<T>>>> _list;

    void sort()
    {
	struct {
	    bool operator()(std::pair<T, std::shared_ptr<Tree<T>>> a, std::pair<T, std::shared_ptr<Tree<T>>> b) const
	    {
		return a.first < b.first;
	    }
	} lesser;
	std::sort(_list.begin(), _list.end(), lesser);
	for (auto it = _list.begin(); it != _list.end(); ++it)
	    if (it->second)
		it->second->sort();
    }

};

template<typename T> struct TreeNode
{
    std::shared_ptr<TreeNode<T>> _parent;
    T _element;
    std::vector<std::shared_ptr<TreeNode<T>>> _children;
};

template<typename T> int treesSize(const Tree<T>& tt)
{
    int s = 0;
    for (auto& pp : tt._list)
	s += 1 + (pp.second ? treesSize(*pp.second) : 0);
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
	if (pp.second)
	{
	    auto ee = treesElements(*pp.second);
	    qq->insert(qq->end(), ee->begin(), ee->end());
	}
    }
    return qq;
}

// treesNodes :: (Ord a, Ord (Tree a)) => TreeNode -> Tree a -> Set.Set TreeNode
template<typename T> std::unique_ptr<std::vector<std::shared_ptr<TreeNode<T>>>> treesNodes(const std::shared_ptr<TreeNode<T>>& p, const Tree<T>& tt)
{
    auto qq = std::make_unique<std::vector<TreeNode<T>>>();
    qq->reserve(tt._list.size());
    for (auto& pp : tt._list)
    {
	auto q = std::make_shared<TreeNode<T>>();
	q->_parent = p;
	q->_element = pp.first;
	if (pp.second)
	{
	    auto ee = treesNodes(q, *pp.second);
	    q->_children.insert(q->_children.end(), ee->begin(), ee->end());
	}
	qq->push_back(q);
    }
    return qq;
}

// treesNodes :: (Ord a, Ord (Tree a)) => Tree a -> Set.Set TreeNode
template<typename T> std::unique_ptr<std::vector<std::shared_ptr<TreeNode<T>>>> treesNodes(const Tree<T>& tt)
{
    return treesNodes(std::shared_ptr<TreeNode<T>>(), tt);
}


// funcsTreesMap :: (Ord a, Ord (Tree a), Ord b, Ord (Tree b)) => (a -> b) -> Tree a -> Tree b
template<typename S,typename T> std::unique_ptr<Tree<T>> funcsTreesMap(T (*pf)(const S&), const Tree<S>& ss)
{
    auto tt = std::make_unique<Tree<T>>();
    tt->_list.reserve(ss._list.size());
    for (auto& pp : ss._list)
    {
	if (pp.second)
	{
	    auto qq = funcsTreesMap(pf, *pp.second);
	    tt->_list.push_back(std::pair<T, std::shared_ptr<Tree<T>>>(pf(pp.first), std::move(qq)));
	}
	else
	    tt->_list.push_back(std::pair<T, std::shared_ptr<Tree<T>>>(pf(pp.first), std::shared_ptr<Tree<T>>()));
    }
    return tt;
}

// treesEnumeratePreOrder :: Int  -> Tree a -> (Tree (Int,a), Int)
template<typename T> std::pair<std::unique_ptr<Tree<std::pair<int,T>>>,int> treesEnumeratePreOrder(int k, const Tree<T>& tt)
{
    auto rr = std::make_unique<Tree<std::pair<int, T>>>();
    auto s = tt._list.size();
    rr->_list.reserve(s);
    int j = k + s;
    int i = k;
    for (auto& pp : tt._list)
    {
	if (pp.second)
	{
	    auto qq = treesEnumeratePreOrder(j, *pp.second);
	    j = qq.second;
	    rr->_list.push_back(std::pair<std::pair<int, T>, std::shared_ptr<Tree<std::pair<int, T>>>>(std::pair<int, T>(i++, pp.first), std::move(qq.first)));
	}
	else
	    rr->_list.push_back(std::pair<std::pair<int, T>, std::shared_ptr<Tree<std::pair<int, T>>>>(std::pair<int, T>(i++, pp.first), std::shared_ptr<Tree<std::pair<int, T>>>()));
    }
    return std::pair<std::unique_ptr<Tree<std::pair<int, T>>>, int>(std::move(rr),j);
}

template<typename T> std::unique_ptr<std::vector<std::vector<T>>> treesPaths(const std::vector<T>& ll, const Tree<T>& xx)
{
    if (xx._list.size() == 0)
	return std::unique_ptr<std::vector<std::vector<T>>>(new std::vector<std::vector<T>>{ ll });
    auto qq = std::make_unique<std::vector<std::vector<T>>>();
    for (auto it = xx._list.begin(); it != xx._list.end(); ++it)
    {
	auto jj = ll;
	jj.push_back(it->first);
	if (it->second)
	{
	    auto yy = treesPaths(jj, *it->second);
	    qq->insert(qq->end(), yy->begin(), yy->end());
	}
	else
	    qq->push_back(jj);
    }
    return qq;
}

// treesPaths :: (Ord a, Ord (Tree a)) => Tree a -> [[a]]
template<typename T> std::unique_ptr<std::vector<std::vector<T>>> treesPaths(const Tree<T>& tt)
{
    return treesPaths(std::vector<T>(),tt);
}

// pairTreesUnion :: (Ord a, Ord (Tree a)) => Tree a -> Tree a -> Tree a
template<typename T> std::unique_ptr<Tree<T>> pairTreesUnion(const Tree<T>& ss,const Tree<T>& tt)
{
    auto rr = std::make_unique<Tree<T>>(ss);
    if (tt._list.size() == 0)
	return rr;
    if (ss._list.size() == 0)
	return std::make_unique<Tree<T>>(tt);
    for (int i = 0; i < tt._list.size(); i++)
    {
	bool found = false;
	for (int j = 0; !found && j < ss._list.size(); j++)
	    if (tt._list[i].first == ss._list[j].first)
	    {
		found = true;
		if (ss._list[j].second && tt._list[i].second)
		{
		    auto uu = pairTreesUnion(*ss._list[j].second, *tt._list[i].second);
		    rr->_list[j].second = std::move(uu);
		}
		else if (tt._list[i].second)
		    rr->_list[j].second = tt._list[i].second;
	    }
	if (!found)
	    rr->_list.push_back(tt._list[i]);
    }
    return rr;
}

// pathsTree :: (Ord a, Ord (Tree a)) => [[a]] -> Tree a
template<typename T> std::unique_ptr<Tree<T>> pathsTree(const std::vector<std::vector<T>>& qq)
{
    auto tt = std::make_unique<Tree<T>>();
    for (auto& ll : qq)
    {
	if (ll.size() > 0)
	{
	    Tree<T> ss;
	    auto jj = ll;
	    jj.erase(jj.begin());
	    std::vector<std::vector<T>> rr{ jj };
	    auto uu = pathsTree(rr);
	    ss._list.push_back(std::pair<T, std::shared_ptr<Tree<T>>>(ll[0], std::move(uu)));
	    tt = pairTreesUnion(*tt, ss);
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
	out << "(" << it->first << ",";
	if (it->second)
	    out << *it->second;
	else
	    out << "{}";
	out << ")";
    }
    out << "}";
    return out;
}

#endif