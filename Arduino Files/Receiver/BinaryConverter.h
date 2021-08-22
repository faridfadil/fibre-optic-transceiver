#include <iostream> //so we can use std::string

class BinaryConverter
{
private:
	
	std::string* pointerMessage;
	std::string message = *pointerMessage;

	
	std::string* pointerFinalMessage;
	std::string finalMessage = *pointerFinalMessage;

public:
	BinaryConverter(std::string* inputMessage);
	std::string getMessage();
	std::string getFinalMessage();
	void messageToBinary();
	void binaryToMessage();
};

