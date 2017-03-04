#include "dictionary.h"

bool Translate(std::string const& en, std::string& ru)
{
	auto it = dictionary.find(en);
	if (it != dictionary.end())
	{
		ru = it->second;
		return true;
	}
	return false;
}