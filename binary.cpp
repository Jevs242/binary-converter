//Jose Velazquez
//BinaryConverter

#include "binary.h"

int main()
{
	program.menu();
	std::cout << "\n\n";
	return 0;
}

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause() {
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
#endif
}

void Program::menu()
{ 
	int opc{0};
	std::cout << "1.Number to Binary | 2.Binary to Number | 3.Word to Binary | 4.Binary to Word | 5.Exit" << std::endl;
	opc = valid();
	switch (opc)
	{
	case 1:
		numberToBinary();
		break;
	case 2:
		binarytonumber();
		break;
	case 3:
		wordToBinary();
		break;
	case 4:
		binaryToWord();
	case 5:
		return;
	default:
		error("Error : 1 , 2 , 3 , 4 or 5");
		ClearScreen();
		menu();
		break;
	}
} 

void Program::end()
{
	char inputEnd;
	std::cout << "Do you want to get other binary number? (Y/N) : ";
	std::cin >> inputEnd;
	switch (std::toupper(inputEnd))
	{
	case 'Y':
		ClearScreen();
		menu();
		break;
	case 'N':

		break;
	default:
		error("Error : Y or N : ");
		end();
		break;
	}
}

void Program::message(std::string message, std::string num1, std::string num2)
{
	std::cout << "\n";
	std::cout << message;
	std::cout << num1 << " is: \n\n" << num2;
	std::cout << "\n\n";
	end();
}

void Program::error(std::string message)
{
	ClearScreen();
	std::cout << message << std::endl;
	Pause();
	ClearScreen();
}

int Program::valid()
{
	int num;

	while (true) {
		if (std::cin >> num) {
			break;
		}
		else {
			std::cout << "Enter a valid integer value!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}//I'm verficating the input
	return num;

}

void Program::validBinary(std::string binary , int opc)
{
	for (int i = 0; i < binary.length(); i++)
	{
		if (opc == 4 && binary.length() % 8 != 0)
		{
			error("Error : Some words are incomplete");
			menu();
		}//I'm verificating that the words are complete

		if (binary[i] == '0' || binary[i] == '1' || binary[i] == ' ')
		{
			continue;
		}//I'm verificating that binary only has 0 and 1
		else
		{
			error("Error : Only 0 or 1");
			switch (opc)
			{
			case 2:
				binarytonumber();
				break;
			case 4:
				binaryToWord();
				break;
			}
		}
	}
}

/// Number to Binary

void Program::numberToBinary()
{
	ClearScreen();
	int inputnumber;
	std::cout << ("What number you want to convert to binary number : ");
	inputnumber = valid();

	number numbertobinary(inputnumber);

	numbertobinary.numberToBinaryCall();

	message("The binary number of ", std::to_string(inputnumber) , numbertobinary.getBinary());
} 

void number::numberToBinaryCall()
{
	numberToBinaryFormula(_number, _binary);
} 

void number::numberToBinaryFormula(int& number ,std::string& binary)
{
	while (number != 0)
	{
		binary = binary + std::to_string(number % 2);
		number = number / 2;
	}//I'm converting the number to binary number

	for (int i = 0; i < binary.length() / 2; i++)
	{
		std::swap(binary[i], binary[binary.length() - i - 1]);
	}//I'm inverting the string
}

/// Binary to Number

void Program::binarytonumber()
{
	std::string binarynumber;
	std::cout << "What binary number you want to convert to decimal? ";
	std::cin >> binarynumber;
	validBinary(binarynumber,2);
	number inputnumber(binarynumber);

	inputnumber.binaryToNumberCall();

	message("The number of ", binarynumber, std::to_string(inputnumber.getNumber()));

} 

void number::binaryToNumberCall()
{
	binaryToNumberFormula(_number,_binary);
}

void number::binaryToNumberFormula(int& number, std::string& binary)
{
	for (int i = 0; i < binary.length() / 2; i++)
	{
		std::swap(binary[i], binary[binary.length() - i - 1]);
	}//I'm inverting the string

	int result = 0;

	for (int i = 0; i < binary.length(); i++)
	{
		int num = binary[i] - '0';
		result += num * pow(2, i);
	}//I'm converting the binary to number

	number = result;
}

/// Words to Binary

void Program::wordToBinary() {
	std::cout << ("What word you want to convert to binary number : ");
	std::string word{};
	std::cin.ignore();
	std::getline(std::cin,word);
	number inputword(word, true);
	
	inputword.stringToBinaryCall();

	message("The binary number of ", inputword.getWord(), inputword.getBinary());
}

void number::stringToBinaryCall()
{
	int ascii;
	std::string resultLettle;
	std::string resultWord;

	for (int i = 0; i < _word.length(); i++)
	{
		resultLettle = "";
		ascii = _word[i];
		
		numberToBinaryFormula(ascii, resultLettle);

		resultWord += "0" + resultLettle + " ";
	}//I'm converting the word to binary
	_binary = resultWord;
}

/// Binary to Words

void Program::binaryToWord()
{
	std::string binary{"01001000 01101001"};
	std::cout << ("What Binary you want to convert to Words : ");
	std::cin.ignore();
	std::getline(std::cin, binary);
	number inputBinary(binary);
	inputBinary.binaryToStringCall();

	message("The word of ", inputBinary.getBinary(), inputBinary.getWord());
}

void number::binaryToStringCall()
{
	std::string lineBinary{""};
	std::vector<std::string> arrayBinary;
	std::vector<int> arrayChar;
	for (int i = 0; i < _binary.length(); i++)
	{
		if (_binary[i] != ' ')
			lineBinary += _binary[i];
	} //I'm removing spaces from the string

	program.validBinary(lineBinary, 4);//I'm verifying that it only have 0 and 1

	for (int i = 0; i < lineBinary.length() / 8; i++)
	{
		arrayBinary.push_back("");
		arrayChar.push_back(0);
	} //I'm adding space in array (Vector)

	int position = 0;
	for (int i = 0; i < lineBinary.length(); i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			position++;
		}
		arrayBinary[position] += lineBinary[i];
	}//I'm passing the lineBinary to arrayBinary for separate the binary numbers

	for (int i = 0; i < arrayBinary.size(); i++)
	{
		binaryToNumberFormula(arrayChar[i], arrayBinary[i]);
	}//I'm converting the binary numbers to decimal numbers
	for (int i = 0; i < arrayBinary.size(); i++)
	{
		_word += char(arrayChar[i]);
	}//I'm converting the decimal numbers to Ascii
}
