#pragma once

#include <string>
#include <map>

//����� �� ������ �� ��������
//������� ������� ��������� ������ �� ����� (���������. �������)
//� ������� �� main

std::map<std::string, std::string> dictionary;
bool Translate(std::string const& en, std::string& ru);

