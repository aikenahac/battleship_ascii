#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMessage(string asciiFile){
    string line;
    ifstream myfile (asciiFile);
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        cout << line << '\n';
      }
      myfile.close();
    }
    
    else cout << "Unable to open file";
}
