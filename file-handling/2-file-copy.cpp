// File I/O: Reading from one file and writing to another
// Demonstrates proper file handling with error checking and resource management

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string line;

  // Open source file for reading
  ifstream inputFile("input.txt", ios::in);
  if (!inputFile.is_open()) {
    cerr << "Error: Could not open input.txt for reading" << endl;
    return 1;
  }

  // Open destination file for writing
  ofstream outputFile("output.txt", ios::out);
  if (!outputFile.is_open()) {
    cerr << "Error: Could not open output.txt for writing" << endl;
    inputFile.close();
    return 1;
  }

  // Read line by line and write to output file
  cout << "Reading from input.txt and writing to output.txt..." << endl;
  int lineCount = 0;

  while (!inputFile.eof()) {
    getline(inputFile, line);
    if (!line.empty()) {
      outputFile << line << endl;
      lineCount++;
    }
  }

  // Close files (RAII - close explicitly for clarity)
  outputFile.close();
  inputFile.close();

  cout << "Successfully copied " << lineCount << " lines." << endl;
  cout << "Task completed!" << endl;

  return 0;
}
