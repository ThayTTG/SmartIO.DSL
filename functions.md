### 🔧 Utility Functions
**fileExists()**

_Checks whether a given path exists in the filesystem.
Returns true if the file or directory exists, otherwise false._

**isDirectory()**

_Determines whether the given path refers to a directory.
Returns true if the path is a directory, otherwise false._

### 🔄 Conversion Helpers

**toString()**

_Converts a numeric value to a std::string using std::to_string._

**toFloat()**

_Converts a string representation of a number into a float using std::stof._

**toInt()**

_Converts a string representation of a number into an int using std::stoi._

**toLongInt()**

_Converts a string representation of a number into an unsigned long long using std::stoull._

### 🖨️ Console I/O
**print()**

_Prints multiple arguments to the standard output in a single line using fold expressions._

**error()**

_Prints multiple arguments to the standard error output in a single line._

**input()**

_Displays a message to the user and captures a full line of input from standard input.
Returns the entered string._

### 📁 File & Filesystem Operations

**createFile()**

_Creates a new file at the specified path if it does not already exist.
Displays a message indicating success or failure._

**listFiles()**

_Lists all entries in the specified directory.
Stores the entries internally and returns the total number of items found._

**selectFile()**

_Provides an interactive directory navigation system.
Allows the user to move between directories and select a file or directory.
Returns the selected path._

**request()**

_Reads content from a file.
If lineRequested is -1, returns the full content.
Otherwise, returns only the specified line number._

**send()**

_Writes data to a file.
Appends or overwrites content depending on the isAppend flag._
