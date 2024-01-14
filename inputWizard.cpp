#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "inputWizard.h"


void title()
{
    std::cout << "  ___   __    _  _______  __   __  _______  _     _  ___   _______  _______  ______    ______  " << std::endl;
    std::cout << " |   | |  |  | ||       ||  | |  ||       || | _ | ||   | |       ||   _   ||    _ |  |      | " << std::endl;
    std::cout << " |   | |   |_| ||    _  ||  | |  ||_     _|| || || ||   | |____   ||  |_|  ||   | ||  |  _    |" << std::endl;
    std::cout << " |   | |       ||   |_| ||  |_|  |  |   |  |       ||   |  ____|  ||       ||   |_||_ | | |   |" << std::endl;
    std::cout << " |   | |  _    ||    ___||       |  |   |  |       ||   | | ______||       ||    __  || |_|   |" << std::endl;
    std::cout << " |   | | | |   ||   |    |       |  |   |  |   _   ||   | | |_____ |   _   ||   |  | ||       |" << std::endl;
    std::cout << " |___| |_|  |__||___|    |_______|  |___|  |__| |__||___| |_______||__| |__||___|  |_||______| " << std::endl;
}
void inputOptions(int switchInt)
{
    switch (switchInt)
    {
    //  if input is list check if there are words in vector(list)
    //  otherwise cout list first we give every words its according number
    //  we use words[i-1] because the index of a vector starts from 0, not 1.
    case 1:

        if (userInput == "ls")
        {
            if (words.empty()) // words.empty checks if the vector is empty.
            {
                std::cout << "there is nothing in the list " << std::endl;
            }
            else
            {
                for (unsigned int i = 1; i <= words.size(); i++) // a and i a is amount of words i amount of strings
                {
                    std::cout << "[" << i << "]" << words[i - 1] << " ";
                }
            }
        }
        break;

    // removes all strings from the vector(list).
    case 2:

        if (userInput == "cl")
        {
            if (words.empty())
            {
                std::cout << "No strings in the vector " << std::endl;
            }
            else
            {
                int strAmount = words.size();//get word count before deleting it 
                words.clear();
                std::cout << "You removed " << strAmount << " strings " << std::endl;
            }
        }

        break;

    case 3:

        if (userInput == "clear")
        {
            std::cout << "\033c"; 
            std::cout << "Enter words: " << std::endl;
        }

        break;

    case 4:

        if (userInput == "help")
        {
            std::cout << "\n" << "Available options:\n";
            std::cout << "[1] ls.       {show list of str} \n";
            std::cout << "[2] cl.       {clear list of str} \n";
            std::cout << "[3] clear.    {clear terminal}\n";
        }

        break;

    }
}
int main()
{
    title();
    std::cout << "\n"
    << "Enter words: " << std::endl;

    //  This loop continues inserting words via words.push_back into vector containing string word
    //  if the word is not equal to "ls" we increases the size of the vector(list) by one each time push_back is called.
    //  until "break" is written
    while (std::cin >> userInput)
    {
        if (userInput != "ls" && userInput != "cl" && userInput != "clear"  && userInput != "help")
        {
            words.push_back(userInput);
        }

        inputOptions(1);
        inputOptions(2);
        inputOptions(3);
        inputOptions(4);

        if (userInput == "break")//exit program 
        break;
    }
    return 0;
}