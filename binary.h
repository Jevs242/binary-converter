//Jose Velazquez
//BinaryConverter

#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

class number
{
private:

	//Variable

	int _number;
	std::string _binary{};
	std::string _word{};
public:

	//Contruct

	number(int setNumber) { _number = setNumber; }
	number(std::string setString) { _binary = setString; }
	number(std::string setWord , bool word) { _word = setWord; }

	//Function

	int getNumber() { return _number; }
	std::string getBinary() { return _binary; }
	std::string getWord() { return _word; }

	void numberToBinaryCall();
	void numberToBinaryFormula(int& number, std::string& binary);

	void binaryToNumberCall();
	void binaryToNumberFormula(int& number, std::string& binary);
	
	void stringToBinaryCall();

	void binaryToStringCall();
};

void menu();
void end();
void message(std::string message , std::string num1 , std::string num2);
int valid();
void validBinary(std::string binary , int opc);
void numberToBinary();
void binarytonumber();
void wordToBinary();
void binaryToWord();