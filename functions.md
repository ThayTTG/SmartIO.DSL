🔧 Utility Functions
fileExists(fs::path path)

Checks whether a given path exists in the filesystem.
Returns true if the file or directory exists, otherwise false.

isDirectory(fs::path path)

Determines whether the given path refers to a directory.
Returns true if the path is a directory, otherwise false.

🔄 Conversion Helpers
toString(value)

Converts a numeric value to a std::string using std::to_string.

toFloat(value)

Converts a string representation of a number into a float using std::stof.

toInt(value)

Converts a string representation of a number into an int using std::stoi.

toLongInt(value)

Converts a string representation of a number into an unsigned long long using std::stoull.

🖨️ Console I/O
print(Args... args)

Prints multiple arguments to the standard output in a single line using fold expressions.

error(Args... args)

Prints multiple arguments to the standard error output in a single line.

input(const std::string& message)

Displays a message to the user and captures a full line of input from standard input.
Returns the entered string.

📁 File & Filesystem Operations
createFile(std::string path)

Creates a new file at the specified path if it does not already exist.
Displays a message indicating success or failure.

listFiles(std::filesystem::path& path)

Lists all entries in the specified directory.
Stores the entries internally and returns the total number of items found.

selectFile(std::filesystem::path path = std::filesystem::current_path())

Provides an interactive directory navigation system.
Allows the user to move between directories and select a file or directory.
Returns the selected path.

request(std::string path, int lineRequested = -1)

Reads content from a file.
If lineRequested is -1, returns the full content.
Otherwise, returns only the specified line number.

send(std::string path, std::string value, bool isAppend = true)

Writes data to a file.
Appends or overwrites content depending on the isAppend flag.
