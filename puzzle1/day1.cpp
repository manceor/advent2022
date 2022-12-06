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

  // Initialize the running total to 0
  int total = 0;
  array<int, 2256> elfarr;
  fill(elfarr.begin(), elfarr.end(), 0);
  int i = 0; 
  // Read the file line by line
  std::string line;
  while (std::getline(file, line)) {
    // If the line is empty, reset the total and move to the next line
    if (line.empty()) {
      elfarr[i] = total;
      i++;
      total = 0;
      continue;
    }

    // Otherwise, add the current line to the running total
    total += std::stoi(line);
  }
  sort(elfarr.begin(), elfarr.end(), greater<int>());
  for (size_t i = 0; i < 2256; i++)
  {
    cout << elfarr[i] << endl;
  }
    cout << elfarr[0] + elfarr[1] + elfarr[2] << endl;
  // Close the file
  file.close();
}


int main(){

    process_file("data.txt");

}