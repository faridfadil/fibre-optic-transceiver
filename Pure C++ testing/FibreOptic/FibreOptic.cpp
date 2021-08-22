#include <iostream>
#include <bitset>
//#include "TickSystem.h"
#include "BinaryConverter.h"

std::string message = "momo";
BinaryConverter myBinary(message);

//main entry point of application
int main()
{
	std::cout << myBinary.getMessage() << std::endl;
	myBinary.messageToBinary();
	std::cout << myBinary.getFinalMessage() << std::endl;

	//std::string finalMessage = myBinary.getFinalMessage();
	
}

