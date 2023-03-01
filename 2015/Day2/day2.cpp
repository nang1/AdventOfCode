#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Present{
    int length;
    int width;
    int height;

    Present( ) {

    }
};

int main( int argc, char *argv[] ) {
    
    if ( argc < 2 ) {
        cout << "Mising input file" << endl;
        return 1;
    } 
    
    /***** Read in everything first *****/
    fstream fileInput;
    fileInput.open( argv[1], ios::in );

    vector<string> inputLines;
    string inputLine = "";
    while( getline( fileInput, inputLine ) ) {
        inputLines.push_back( inputLine );
    }
    fileInput.close();

    /***** Parse to get length, width, and height dimensions *****/



    return 0;
}