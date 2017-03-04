#include "iostream"
#include <fstream>
#include <map>
#include "Function.h"
#include <algorithm>
//todo создать класс калькулятора и добавить тесты


bool CheckId(const std::string& id);
bool ParseName(const std::string& expr, std::string& left, std::string& right);
bool ParseFunction(char *operands, char& op, const std::string &expr, std::string& left, std::string& right);

int main()
{
	//unique_ptr shared_ptr загуглить
	//разгрузить функцию!!!!!!!
	setlocale(LC_ALL, "Russian");
	std::map<std::string, Identificator*> vars;

	std::ifstream istream("input5.txt");
	if (!istream.is_open())
	{
		std::cout << "input file not found" << std::endl;
		system("pause");
		return 1;
	}

	auto typeVar = typeid(Var).name(); //зачем
	auto typeFn = typeid(Function).name(); //зачем
	char operands[4] = { '+', '-', '*', '/' }; //todo создать константу вектор
	
	std::ofstream ostream("output.txt");
	while (!istream.eof())
	{		
		try
		{
			std::string cmd;
			istream >> cmd;

			if (cmd == "var")
			{
				std::string var;
				istream >> var;

				if (vars.find(var) != vars.end())
				{
					ostream << "Идентификатор " + var + " уже существует." << std::endl;
					continue;
				}

				if (CheckId(var))				
					vars[var] = new Var();	//todo ликвидировать new delete	
			}
			else if (cmd == "let")
			{
				std::string equation, var, var2;
				istream >> equation;

				if (ParseName(equation, var, var2))
				{
					if (CheckId(var))
					{
						if (vars.find(var2) != vars.end()) //копия
						{	
							vars[var] = new Var(vars[var2]->Calculate());
						}
						else
						{
							int ind = var2.find('.'); //форматирование
							if (ind != -1)
								var2[ind] = ',';

							if (vars.find(var) != vars.end())  //изменение значения
								vars[var]->SetValue(atof(var2.c_str()));
							else //инициализация
								vars[var] = new Var(atof(var2.c_str()));
						}
					}
				}
			}
			else if (cmd == "print")
			{
				std::string var;
				istream >> var;

				if (vars.find(var) == vars.end())
				{
					ostream << "Необъявленный идентификатор " + var + "." << std::endl;
					continue;
				}
				
				ostream << *vars[var] << std::endl;
			}
			else if (cmd == "printvars")
			{
				for (auto var : vars)				
					if (typeid(*var.second).name() == typeVar)
						ostream << var.first + ":" << *var.second << std::endl;				
			}
			else if (cmd == "fn")
			{
				std::string expr, fn, right;
				istream >> expr;

				if (ParseName(expr, fn, right))
				{
					if (vars.find(fn) != vars.end())
					{
						ostream << "Идентификатор " + fn + " уже существует." << std::endl;
						continue;
					}

					if (CheckId(fn))
					{
						char op;
						std::string var1, var2;
						bool bin = ParseFunction(operands, op, right, var1, var2);

						if (vars.find(var1) == vars.end())
						{
							ostream << "Необъявленный идентификатор " + var1 + "." << std::endl;
							continue;
						}
						if (bin && vars.find(var2) == vars.end())
						{
							ostream << "Необъявленный идентификатор " + var2 + "." << std::endl;
							continue;
						}

						if (bin)
						{
							auto dfsdf = vars[var1];
							auto sdgff = vars[var2];
							vars[fn] = new Function(vars[var1], op, vars[var2]);
						}
						else
							vars[fn] = new Function(vars[var1]);
					}
				}
			}
			else if (cmd == "printfns")
			{
				for (auto var : vars)
					if (typeid(*var.second).name() == typeFn)  //typeid?
						ostream << var.first + ":" << *var.second << std::endl;
			}
		}
		catch (std::exception ex)
		{
			ostream << ex.what() << std::endl;
		}
	}

	for (auto var : vars)
		delete var.second;

	istream.close();
	ostream.close();
	return 0;
}

bool CheckId(const std::string& id)
{
	return (id.length() > 0 && (id[0] <= '0' || id[0] >= '9'));
}

bool ParseName(const std::string& expr, std::string& left, std::string& right)
{
	int ind = expr.find('=');
	if (ind != -1)
	{
		left = expr.substr(0, ind);
		right = expr.substr(ind + 1, expr.length() - ind - 1).c_str();
		return true;
	}
	return false;
}

bool ParseFunction(char *operands, char& op, const std::string &expr, std::string& left, std::string& right)
{
	for (int i = 0; i < 4; ++i)
	{
		int ind = expr.find(operands[i]);
		if (ind != -1)
		{
			op = operands[i];
			left = expr.substr(0, ind);
			right = expr.substr(ind + 1, expr.length() - ind - 1).c_str();

			return true;
		}
	}

	left = expr;
	return false;
}