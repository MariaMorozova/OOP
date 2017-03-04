#pragma once
#include <string>
#include <algorithm>
#include <set>

bool CheckWord(const std::set<std::string>& filtr, std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);

	return filtr.find(word) == filtr.end();		
}