#include <fstream>
#include <iostream>
#include<string>
using namespace std;

int main( )
{
  ifstream fin;
  fin.open("data_in.txt");
  if (fin.fail( )) {
        cout << "Input file opening failed.\n";
        exit(1);
    }

  string word;   
  
  while (!fin.eof()) {
    fin >> word;
    cout << word <<endl;
  }

  fin.close( );
 return 0;
}
