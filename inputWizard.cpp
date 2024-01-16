#include "inputWizard.h"

int main()
{
    Manager manager;
    
    manager.title();

    std::cout << "\n"
    << "Enter words: " << std::endl;

    //  This loop continues inserting words via words.push_back into vector containing string word
    //  if the word is not equal to "ls" we increases the size of the vector(list) by one each time push_back is called.
    //  until "break" is written
    while (std::cin >> manager.userInput)
    {
        manager.ignoreWords();

        manager.inputOptions(1);
        manager.inputOptions(2);
        manager.inputOptions(3);
        manager.inputOptions(4);
        manager.inputOptions(5);
        manager.inputOptions(6);


        if (manager.userInput == "break")//exit program 
        break;
    }
    return 0;
}