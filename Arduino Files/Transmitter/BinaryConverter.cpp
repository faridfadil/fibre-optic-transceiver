#include "BinaryConverter.h"
#include <iostream>

//set the message string variable to the input message in the constructor to eliminate the need of a setter function. 
BinaryConverter::BinaryConverter(std::string* pointerInputMessage)
{
    BinaryConverter::pointerMessage = pointerInputMessage;
}

//getter method to get the value of the message passed into the constructor.
std::string BinaryConverter::getMessage()
{
	return *BinaryConverter::pointerMessage;
}
//getter method to get the value of the final message- depending on its use, it will either output the binary sequence or an english message.
std::string BinaryConverter::getFinalMessage()
{
    return *BinaryConverter::pointerFinalMessage;
}

//we want to convert the string to a binary sequence of numbers and then store it in the finalMessage variable.
void BinaryConverter::messageToBinary()
{
    int n = BinaryConverter::getMessage().length();
    std::string bin = "";
    for (int i = 0; i <= n; i++)
    {
        int val = int(BinaryConverter::getMessage()[i]);

        
        while (val > 0)
        {
            (val % 2) ? bin.push_back('1') : bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());

        
    }
    BinaryConverter::finalMessage = bin;
}
//we want to convert the binary sequence of numbers back into a string. 
void BinaryConverter::binaryToMessage()
{
    int n = BinaryConverter::getMessage().length();
    std::string bin = "";
    for (int i = 0; i <= n; i++)
    {
        int val = int(BinaryConverter::getMessage()[i]);


        while (val > 0)
        {
            (val % 2) ? bin.push_back('1') : bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());


    }
    BinaryConverter::finalMessage = bin;
}

