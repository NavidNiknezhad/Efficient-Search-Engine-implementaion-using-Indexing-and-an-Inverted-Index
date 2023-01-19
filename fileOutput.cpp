#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main( )
{
    ofstream fout;
    fout.open("data_out.txt");

	if (fout.fail( ))    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    int x = 2;
	int y = 3;
    
    fout << "x + y = " << x+y;

	fout.close( );
    return 0;
}