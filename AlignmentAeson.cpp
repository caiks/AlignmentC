#include "AlignmentAeson.h"
#include <cctype>

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




