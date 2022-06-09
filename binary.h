#pragma once
#include <iostream>
#include <string>

class number
{
private:
	int number;
	std::string binary{};
public:
	void setnumber(int set);
	int getnumber() { return number; }
	std::string getBinary() { return binary; }
};

void input();
void end();