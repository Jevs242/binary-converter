#include "binary.h"

int main()
{
	input();
	std::cout << "\n\n";
	return 0;
}

void input()
{
	system("cls");
	number numbertobinary;
	int inputnumber;

	std::cout << ("What number you want to convert to binary number : ");
	std::cin >> inputnumber;

	numbertobinary.setnumber(inputnumber);

	std::cout << "\n";
	std::cout << "The binary number of ";
	std::cout << numbertobinary.getnumber() << " is " << numbertobinary.getBinary();
	std::cout << "\n\n";
	end();
}

void end()
{
	char inputEnd;
	std::cout << "Do you want to get other binary number? (Y/N) : ";
	std::cin >> inputEnd;
	switch (std::toupper(inputEnd))
	{
	case 'Y':
		input();
		break;
	case 'N':

		break;
	default:
		std::cout << "\nError : Y or N : ";
		break;
	}
}

void number::setnumber(int set)
{
	number = set;
	int result = number;
	
	while (result != 0)
	{
		binary = binary + std::to_string(result % 2);
		result = result / 2;
	}

	for (int i = 0 ;  i < binary.length()/2; i++)
	{
		std::swap(binary[i], binary[binary.length() - i - 1]);
	}
}

