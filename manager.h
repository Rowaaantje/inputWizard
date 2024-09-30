#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>

// In manager.h
class Manager {
public:
   // Declarations...
   void title();
   void openFile();
   void createFile();
   void inputOptions(int switchInt);
   void ignoreWords();

   std::string userInput;

private:
   std::vector<std::string> words;
   std::string filename;
   std::ifstream file;
   
   std::ofstream outFile;
};

#endif // MANAGER_H

// In manager.cpp or inputWizard.cpp
void Manager::title() {
    std::cout << "  ___   __    _  _______  __   __  _______  _     _  ___   _______  _______  ______    ______  "  << std::endl;
    std::cout << " |   | |  |  | ||       ||  | |  ||       || | _ | ||   | |       ||   _   ||    _ |  |      | " << std::endl;
    std::cout << " |   | |   |_| ||    _  ||  | |  ||_     _|| || || ||   | |____   ||  |_|  ||   | ||  |  _    |" << std::endl;
    std::cout << " |   | |       ||   |_| ||  |_|  |  |   |  |       ||   |  ____|  ||       ||   |_||_ | | |   |" << std::endl;
    std::cout << " |   | |  _    ||    ___||       |  |   |  |       ||   | | ______||       ||    __  || |_|   |" << std::endl;
    std::cout << " |   | | | |   ||   |    |       |  |   |  |   _   ||   | | |_____ |   _   ||   |  | ||       |" << std::endl;
    std::cout << " |___| |_|  |__||___|    |_______|  |___|  |__| |__||___| |_______||__| |__||___|  |_||______| " << std::endl;
}

void Manager::openFile() {

    std::cout << "\n" << "filename: "; // << std::endl
    std::cin >> filename;

    file.open(filename);

    // check if file not found then give failed promt
    if (file.fail())
    {
      throw std::runtime_error("File failed to open");
    }

    std::string line;
    int lines = 0;

    while (!file.eof()) // eof is gonna return true if we reached the end of the file otherwise false and then continue loop
    {
        getline(file, line); // read the next line in the file and store it in the line string
        lines++;
        std::cout  << "[" << lines << "]" << line << std::endl;
    }

    file.close(); // close acces to the file

    std::cout << "Total Lines: " << lines << std::endl;

    std::cout << "Enter words: " << std::endl;
}

void Manager::createFile() {
    std::cout << "\n" << "filename: "; // << std::endl
    std::cin >> filename;

    outFile.open(filename);

    if (outFile.fail())
    {
        throw std::runtime_error("File failed to open");
    }

    for (auto element : words) // eacht vector has his own line 
    {
        outFile << element << std::endl;
    }

    outFile.close();

    std::cout << "Enter words: " << std::endl;
}

void Manager::inputOptions(int switchInt)
{
    switch (switchInt)
    {
    //  if input is list check if there are words in vector(list)
    //  otherwise cout list first we give every words its according number
    //  we use words[i-1] because the index of a vector starts from 0, not 1.
    #pragma region showList
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
        #pragma endregion
    // removes all strings from the vector(list).
    #pragma region clearlist
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
        #pragma endregion

    #pragma region clearTerminal
    case 3:

        if (userInput == "clear")
        {
            std::cout << "\033c"; 
            std::cout << "Enter words: " << std::endl;
        }

        break;
        #pragma endregion

    #pragma region helpOptions
    case 4:

        if (userInput == "help")
        {
            std::cout << "\n" << "Available options:\n";
            std::cout << "[1] cnf.      {Create new file}\n";
            std::cout << "[2] of.       {Open File}\n";
            std::cout << "[3] ls.       {show list of str} \n";
            std::cout << "[4] cl.       {clear list of str} \n";
            std::cout << "[5] clear.    {clear terminal}\n";
            

        }

        break;
        #pragma endregion

    case 5:

        if(userInput == "cnf")
        {
            createFile();
        }
        break;

     case 6:

        if(userInput == "of")
        {
            openFile();
        }
        break;

    default:
        std::cout << "Invalid command: " << userInput << std::endl;
        break;

    }
}

void Manager::ignoreWords() {

   if (userInput != "ls" && userInput != "cl" && userInput != "clear"  && userInput != "help" && userInput != "cnf" && userInput != "of")
      {
         words.push_back(userInput);
      }
}

