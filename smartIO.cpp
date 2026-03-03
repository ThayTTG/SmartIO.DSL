#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using string = std::string;

//Verify if a file exists and return a boolean (false or true)
bool fileExists(string path) {return fs::exists(path);}

//converts the value to String
auto toString = [](auto value){return std::to_string(value);};
//converts the value to Float
auto toFloat = [](auto value){return std::stof(value);};
//converts the value to Int
auto toInt = [](auto value){return std::stoi(value);};

// Prints and concatenates strings and variables in a single line. 
template <typename... Args> 
void print(Args... args) { (std::cout << ... << args) << std::endl; }

//Show a message, capture the line value and return them. 
string input(const string &str)
{
    // initializes variables and show to user the text typed.
    string value, Default = "";
    std::cout << str << std::endl;

    // capture the value, and if nothing is typed, the code still running.
    if (getline(std::cin, value))
    {
        return value;
    }
    return Default;
}

//Create any type of value that is specified.
void createFile(string &path)
{
    if (!fileExists(path))
    {
        std::ofstream file(path);
        file.close();
        print("File '", path, "' created with success.");
    }
    else
    {
        string overwrite = input("The file already exists. Would you like to overwrite it? (Y/N)");
        while (true)
        {
            if (overwrite == "Y" || overwrite == "y")
            {
                std::ofstream file(path, std::ios::trunc);
                file.close();
                print("File '", path, "' overwrited with success.");
                break;
            }
            else if (overwrite == "N" || overwrite == "n")
            {
                print("Ok, canceling creation process...");
                break;
            }
            else
            {
                overwrite = input("ERROR: Invalid Input. Try Y or N to continue.");
                continue;
            }
        }
    }
}

// request a value from another file. returnes naturally the value like a string.
string request(string path, int lineRequested)
{
    std::ifstream file(path);
    string line, result = "";
    int currentLine = 1;

    if (!file.is_open())
    {
        print("ERROR: file not found.");
        string create = input(" Would you like to create one file with this name? Type Y or N.");
        while (true)
        {
            if (create == "Y" || create == "y")
            {
                print(result);
                break;
            }
            else if (create == "N" || create == "n")
            {
                print("Oky. continuing the process...");
                break;
            }
            else
            {
                print("ERROR: invalid input. Try Again.");
                create = input("Type 'Y' or 'N': ");
                continue;
            }
        }
    }
    else
    {
        print("File ", path, " found. Reading content...");
    }

    // while is possible to get the file path and
    while (getline(file, line))
    {
        if (lineRequested == -1)
        {
            result += line + "\n";
        }
        else if (currentLine == lineRequested)
        {
            result = line;
            print(result);
            break;
        }
        currentLine++;
    }

    // if the line requested does'nt exists, the program send an error message.
    if (lineRequested > 0 && result == "")
    {
        print("WARNING: line", lineRequested, " is out of range.");
    }
    return result;
}


void send(string path, string value, bool isAppend = true)
{
    auto mode = isAppend ? std::ios::app : std::ios::trunc;
    int count = 0;

    while (true)
    {
        // access the file and write based on the selected mode.
        std::ofstream file(path, mode);

        if (file.is_open())
        {
            file << value << "\n";
            file.flush();
            file.close();
            print("Data sent to '", path, "' with success.");
            break;
        }
        else if (count < 2)
        {
            print("ERROR: Could not write to '", path, "'. Maybe you named it wrong?\n\n");
            path = input("Put the file's name again: ");
            count++;
        }
        else
        {
            print("FAIL: Could not write to '", path, "'. If the error percists, try restarting the program.");
            break;
        }
    }
}

string matchFile()
{
    string line = "";
    return line;
}

/*
string access(string path)
{
    std::ofstream file()
}
*/