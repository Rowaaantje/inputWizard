#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "inputWizard.h"

void inputOptions(int switchInt) {

    switch (switchInt) {
    //  if input is list check if there are words in vector(list) 
    //  otherwise cout list first we give every words its according number 
    //  we use words[i-1] because the index of a vector starts from 0, not 1. 
    case 1:

        if (userInput == "ls")
        {
            if (words.empty()) // words.empty checks if the vector is empty.
            {
                std::cout << "there is nothing in the list" << std::endl;
            }
            else
            {
                for (unsigned int i = 1; i <= words.size(); i++)
                {
                    std::cout << "\n" << "[" << i << "]" << words[i - 1] << "\n" << std::endl;
                }
            }
        }
        break;

    // removes all strings from the vector(list).
    case 2: 

        if (userInput == "cl")
        {
            words.clear();
        }

        break;

    case 3:
        
        if (userInput == "clear"){
            std::cout << "\033c";
            std::cout << "Enter words: " << std::endl;
        }

        break;
    }
}

int main()
{
    std::cout << "Enter words: " << std::endl;

    //  This loop continues inserting words via words.push_back into vector containing string word
    //  if the word is not equal to "ls", "help" we increases the size of the vector(list) by one each time push_back is called.
    //  until "break" is written
    while (std::cin >> userInput) {
        if (userInput != "ls"){
            words.push_back(userInput);
        }
        
        if (userInput == "break")
            break;

        inputOptions(1);
        inputOptions(2);
        inputOptions(3);
    }
    return 0;
}