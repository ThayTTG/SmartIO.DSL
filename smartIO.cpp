#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;
using string = std::string;
std::vector<fs::directory_entry> entries;

// Verify if a file exists and return a boolean (false or true)
bool fileExists(fs::path Path)
{return fs::exists(Path);}
bool isDirectory(fs::path Path)
{ return fs::is_directory(Path);}

// converts the value to String
auto toString = [](auto value)
{ return std::to_string(value); };
// converts the value to Float
auto toFloat = [](auto value)
{ return std::stof(value); };
// converts the value to Int
auto toInt = [](auto value)
{ return std::stoi(value); };
auto toLongInt = [](auto value)
{ return std::stoull(value); };

// Prints and concatenates strings and variables in a single line.
template <typename... Args>
void print(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

template <typename... Args>
void error(Args... args)
{
    (std::cerr << ... << args) << std::endl;
}

// Show a message, capture the line value and return them.
string input(const string &str)
{
    // initializes variables and show to user the text typed.
    string value;
    std::cout << str << std::endl;

    // capture the value, and if nothing is typed, the code still running.
    if (getline(std::cin, value))
    {
        return value;
    }
    return "";
}

// Create any type of value that is specified.
void createFile(string path)
{
    if (!fileExists(path))
    {
        std::ofstream file(path);
        file.close();
        print("File '", path, "' created with success.");
    }
    else
    {
        error("The file already exists.");
    }
}

size_t listFiles(fs::path& Path)
{
    int i = 1;
    entries.clear();
    if(fileExists(Path) && isDirectory(Path))
    {
        for (auto &entry : fs::directory_iterator(Path))
        {
        // returns the value to the vector
        entries.push_back(entry);
        print("[", i++, "]", entry.path().filename().string());

        if (entry.is_directory())
        {
            print("<DIR>");
        }
        print("\n");
        }
    }
    else
    {   
        error("ERROR: File does not exist.");
        return 0;
    }
    return entries.size();
}

fs::path selectFile(fs::path Path = fs::current_path())
{
    while (true)
    {
        print("Current path: ", Path, "\n\n");
        try
        {
            size_t entrySize = listFiles(Path);
            if(entrySize == 0){break;}
            print("\nType -1 to Return\n");
            print("\nType 0 to chose the current directory");
            print("\nOr type between 1 and ", entrySize, " to chose another directory\n");

            int choice = toInt(input(""));

            if (choice == -1)
            {
                Path = Path.parent_path();
                print("Returning...");
            }
            else if (choice == 0)
            {
                if (!entries.empty())
                {
                    print("Current directory chosed with success.");
                    return Path;
                }
                else
                {
                    print("Directory is empty.\n");
                }
            }
            else if (choice >= 1 && static_cast<size_t>(choice - 1) <= entrySize)
            {
                if (entries[static_cast<size_t>(choice-1)].is_directory())
                {
                    Path = entries[static_cast<size_t>(choice-1)].path();
                }
                else
                {
                    return entries[static_cast<size_t>(choice-1)].path();
                }
            }
            else
            {
                error("ERROR: Input Invalid.");
                print("REMEMBER: type between 1 and ", entrySize, " to chose another directory\n");
            }
        }
        catch (const fs::filesystem_error &e)
        {
            print("Access denied or invalid path.\n");
            Path = Path.parent_path();
        }
    }
    return Path;
}

// request a value from another file. returnes naturally the value like a string.
string request(fs::path Path, int lineRequested = -1)
{
    
    std::ifstream file(Path);
    string line, result = "";
    int currentLine = 1;

    while(isDirectory(Path))
    {
        print("You selected a directory, but expected a file. Please, choose a file:");
        Path = selectFile(Path);
    }

    if (!file.is_open())
    {
        error("ERROR: file not found.");
        return "";
    }
    else
    {
        print("File ", Path, " found. Reading content...");
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
        error("WARNING: line", lineRequested, " is out of range.");
    }
    return result;
}

void send(string path, string value, bool isAppend = true)
{
    auto mode = isAppend ? std::ios::app : std::ios::trunc;

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
        else
        {
            error("ERROR: Could not write to '", path, "'");
        }
    }
}