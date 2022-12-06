#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
void process_file(const std::string& filename) {
  // Open the file for reading
  std::ifstream file(filename);

  // Check if the file was opened successfully
  if (!file.is_open()) {
    // If not, print an error message and return
    std::cerr << "Error: unable to open file '" << filename << "'" << std::endl;
    return;
  }
  char a = 'A';
  char b = 'B';
  char c = 'C';
  char x = 'X';
  char y = 'Y';
  char z = 'Z';
  // Initialize the running total to 0
  int total = 0;
  // Read the file line by line
  std::string line;
  while (std::getline(file, line)) {
    int line_total = 0;
    // If the line is empty, reset the total and move to the next line
    char opp = line[0];
    char me = line[2];
    switch (me)
    {
    case 'X':
        switch (opp)
        {
        case 'A':
            line_total += 3;
            break;
        case 'B':
            line_total += 1;
            break;
        case 'C':
            line_total += 2;
        default:
            break;
        }
        
        break;
    case 'Y':
        
        switch (opp)
        {
        case 'A':
            line_total = 4;
            break;
        case 'B':
            line_total += 5;
            break;
        case 'C':
            line_total += 6;
            break;
        default:
            break;
        }
        break;
    case 'Z':
        switch (opp)
        {
        case 'A':
            line_total += 8;
            break;
        case 'B':
            line_total += 9;
            break;
        case 'C':
            line_total += 7;
        default:
            break;
        }
        break;

    default:
        break;
    }
    cout << opp << " " << me << " " << line_total << endl;
    total += line_total;
    // Otherwise, add the current line to the running total
  }
  cout << "The total is: " << total << endl;
  // Close the file
  file.close();
}


int main(){

    process_file("rps.txt");

}