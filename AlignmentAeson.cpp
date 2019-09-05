#include "AlignmentAeson.h"
#include <cctype>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

using namespace Alignment;
namespace js = rapidjson;

bool isdigit(const std::string& s)
{
    if (!s.size())
	return false;
    for (int i = 0; i < s.size(); i++)
	if (!std::isdigit(s[i]))
	    return false;
    return true;
}

bool isspace(const std::string& s)
{
    for (int i = 0; i < s.size(); i++)
	if (!std::isspace(s[i]))
	    return false;
    return true;
}

// stringsVariable :: String -> Variable
Variable Alignment::stringsVariable(const std::string& s)
{
    if (isdigit(s))
    {
	std::size_t p = 0;
	try
	{
	    int i = std::stoi(s, &p);
	    if (isspace(s.substr(p, std::string::npos)))
		return Variable(i);
	}
	catch (std::invalid_argument& e)
	{
	}
    }	
    if (s.size() >= 2 && s.front() == '<' && s.back() == '>' && s.find(",") != std::string::npos)
    {
	auto n = s.rfind(",");
	return Variable(stringsVariable(s.substr(1,n-1)), stringsVariable(s.substr(n+1, s.size()-n-2)));
    }
    return Variable(s);
}

// stringsValue :: String -> Value
Value Alignment::stringsValue(const std::string& s)
{
    std::size_t p = 0;
    try 
    {
	int i = std::stoi(s, &p);
	if (isspace(s.substr(p, std::string::npos)))
	    return Value(i);
    }
    catch (std::invalid_argument& e)
    {
    }
    try 
    {
	double d = std::stod(s, &p);
	if (isspace(s.substr(p, std::string::npos)))
	    return Value(d);
    }
    catch (std::invalid_argument& e)
    {
    }
    return Value(s);
}

// stringsRational :: String -> Rational
Rational Alignment::stringsRational(const std::string& s)
{
    try
    {
	long long n = std::stoll(s);
	long long d = 1;
	std::size_t p = s.find("%");
	if (p != std::string::npos)
	    d = std::stoll(s.substr(p + 1, std::string::npos));
	if (d > 0)
	    return Rational(n, d);
    }
    catch (std::invalid_argument& e)
    {
    }
    return Rational();
}

// rationalsString :: Rational -> String
std::string Alignment::rationalsString(const Rational& r)
{
    return std::to_string(r.getNumerator()) + " % " + std::to_string(r.getDenominator());
}

// systemsPersistent :: System -> SystemPersistent
void Alignment::systemsPersistent(const System& uu, std::ostream& out)
{
    out << "[";
    for (auto it = uu.map_u().begin(); it != uu.map_u().end(); ++it)
    {
	if (it != uu.map_u().begin())
	    out << ", ";
	out << "{\"var\": \"" << it->first << "\", \"values\": [";
	for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	{
	    if (it2 != it->second.begin())
		out << ", ";
	    out << "\"" << *it2 << "\"";
	}
	out << "]}";
    }
    out << "]";
}

// systemsPersistentSorted :: System -> SystemPersistent
void Alignment::systemsPersistentSorted(const System& uu, std::ostream& out)
{
    out << "[";
    auto uu1 = sorted(uu.map_u());
    for (auto it = uu1.begin(); it != uu1.end(); ++it)
    {
	if (it != uu1.begin())
	    out << ", ";
	out << "{\"var\": \"" << it->first << "\", \"values\": [";
	for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	{
	    if (it2 != it->second.begin())
		out << ", ";
	    out << "\"" << *it2 << "\"";
	}
	out << "]}";
    }
    out << "]";
}


std::unique_ptr<System> jssSystem(const js::Value& d)
{
    if (!d.IsArray())
	return std::make_unique<System>();
    auto uu = std::make_unique<System>();
    uu->map_u().reserve(d.Size());
    for (js::SizeType i = 0; i < d.Size(); i++)
    {
	const js::Value& a = d[i];
	if (!a.IsObject() || !a.HasMember("var") || !a["var"].IsString() || !a.HasMember("values") || !a["values"].IsArray())
	    return std::make_unique<System>();
	const js::Value& b = a["values"];
	ValSet ww;
	for (js::SizeType j = 0; j < b.Size(); j++)
	    if (b[j].IsString())
		ww.insert(stringsValue(b[j].GetString()));
	if (ww.size())
	    uu->map_u().insert_or_assign(stringsVariable(a["var"].GetString()), ww);
    }
    return uu;
}

// persistentsSystem :: SystemPersistent -> Maybe System
std::unique_ptr<System> Alignment::persistentsSystem(std::istream& is)
{
    js::IStreamWrapper isw(is);
    js::Document d;
    try 
    {
	d.ParseStream(isw);
    }
    catch (std::exception& e)
    {
	return std::make_unique<System>();
    }
    return std::move(jssSystem(d));
}

// historiesPersistent :: History -> SystemPersistent
void Alignment::historiesPersistent(const History& hh, std::ostream& out)
{
    auto uu = historiesSystemImplied(hh);
    out << "{\"hsystem\":";
    systemsPersistentSorted(*uu,out);
    std::unordered_map<Variable, std::unordered_map<Value, int>> mm(uu->map_u().size());
    for (auto& vww : uu->map_u())
    {
	int i = 0;
	std::unordered_map<Value, int> ww(vww.second.size());
	for (auto& w : vww.second)
	    ww.insert_or_assign(w, i++);
	mm.insert_or_assign(vww.first, ww);
    }
    out << ", \"hstates\":[";
    bool first = true;
    for (auto iss = hh.map_u().begin(); iss != hh.map_u().end(); ++iss)
    {
	if (iss != hh.map_u().begin())
	    out << ",";
	out << "[";
	for (auto vu = iss->second.map_u().begin(); vu != iss->second.map_u().end(); ++vu)
	{
	    if (vu != iss->second.map_u().begin())
		out << ",";
	    out << mm[vu->first][vu->second];
	}
	out << "]";
    }
    out << "]}";
}

// historiesPersistentPretty :: History -> SystemPersistent
void Alignment::historiesPersistentPretty(int r, const History& hh, std::ostream& out)
{
    auto uu = historiesSystemImplied(hh);
    std::string p(r,'\t');
    out << "{\n" << p << "\t\"hsystem\":[\n";
    auto uu1 = sorted(uu->map_u());
    for (auto it = uu1.begin(); it != uu1.end(); ++it)
    {
	if (it != uu1.begin())
	    out << ",\n";
	out << p << "\t\t{\"var\": \"" << it->first << "\", \"values\": [";
	for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	{
	    if (it2 != it->second.begin())
		out << ", ";
	    out << "\"" << *it2 << "\"";
	}
	out << "]}";
    }
    std::unordered_map<Variable, std::unordered_map<Value, int>> mm(uu->map_u().size());
    for (auto& vww : uu->map_u())
    {
	int i = 0;
	std::unordered_map<Value, int> ww(vww.second.size());
	for (auto& w : vww.second)
	    ww.insert_or_assign(w, i++);
	mm.insert_or_assign(vww.first, ww);
    }
    out << "\n" << p << "\t],\n" << p << "\t\"hstates\":[\n";
    bool first = true;
    for (auto iss = hh.map_u().begin(); iss != hh.map_u().end(); ++iss)
    {
	if (iss != hh.map_u().begin())
	    out << ",\n";
	out << p << "\t\t[";
	for (auto vu = iss->second.map_u().begin(); vu != iss->second.map_u().end(); ++vu)
	{
	    if (vu != iss->second.map_u().begin())
		out << ",";
	    out << mm[vu->first][vu->second];
	}
	out << "]";
    }
    out << "\n" << p << "\t]\n" << p << "}";
}


// persistentsHistory :: HistoryPersistent -> Maybe History
std::unique_ptr<History> Alignment::persistentsHistory(std::istream& is)
{
    js::IStreamWrapper isw(is);
    js::Document d;
    try 
    {
	d.ParseStream(isw);
    }
    catch (std::exception& e)
    {
	return std::make_unique<History>();
    }
    if (!d.IsObject() || !d.HasMember("hsystem") || !d.HasMember("hstates"))
	return std::make_unique<History>();
    auto uu = jssSystem(d["hsystem"]);
    VarSet qq;
    std::unordered_map<Variable, ValList> mm(uu->map_u().size());
    for (auto& vww : uu->map_u())
    {
	qq.insert(vww.first);
	ValList ww(vww.second.begin(), vww.second.end());
	mm.insert_or_assign(vww.first, ww);
    }
    VarList ll(qq.begin(), qq.end());
    const js::Value& a = d["hstates"];
    if (!a.IsArray())
	return std::make_unique<History>();
    auto hh = std::make_unique<History>();
    hh->map_u().reserve(a.Size());
    for (js::SizeType i = 0; i < a.Size(); i++)
    {
	const js::Value& b = a[i];
	if (!b.IsArray() || b.Size() != ll.size())
	    return std::make_unique<History>();
	State ss;
	for (js::SizeType j = 0; j < b.Size(); j++)
	{
	    auto v = ll[j];
	    auto ww = mm[v];
	    const js::Value& c = b[j];
	    if (!c.IsInt() || c.GetInt() >= ww.size())
		return std::make_unique<History>();
	    ss.map_u().insert_or_assign(v,ww[c.GetInt()]);
	}
	hh->map_u().insert_or_assign(Id(i+1), ss);
    }
    return hh;
}