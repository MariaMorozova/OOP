#pragma once

#include <string>
#include <map>

//класс по работе со словарем
//функция которая принимает ссылку на поток (инициализ. словаря)
//и функции из main

std::map<std::string, std::string> dictionary;
bool Translate(std::string const& en, std::string& ru);

