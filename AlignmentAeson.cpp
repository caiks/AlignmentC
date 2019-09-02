#include "AlignmentAeson.h"
#include <cctype>
#include "rapidjson/document.h"

using namespace Alignment;

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
	return Variable(std::stoi(s));
    if (s.size() >= 2 && s.front() == '<' && s.back() == '>' && s.find(",") != std::string::npos)
    {
	std::cout << "pair" << std::endl;
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





