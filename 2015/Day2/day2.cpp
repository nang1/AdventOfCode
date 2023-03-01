#include "present.h"
#include <iostream> // cout
#include <fstream> // fstream

int main( int argc, char *argv[] ) {
    
    if ( argc < 2 ) {
        cout << "Mising input file" << endl;
        return 1;
    } 
    
    /***** Read in everything first *****/
    fstream fileInput;
    fileInput.open( argv[1], ios::in );

    vector<string> inputList;
    string inputLine = "";
    while( getline( fileInput, inputLine ) ) {
        inputList.push_back( inputLine );
    }
    fileInput.close();

    vector<Present> presentList;
    int totalNeeded = 0;
    for( vector<string>::iterator it = inputList.begin(); it != inputList.end(); ++it ) {
        Present newPresent( *it );
        newPresent.calculateSides();
        newPresent.calculatePaperNeeded();
        //cout << "smallest side: " << newPresent.smallestSide << " present needs: " << newPresent.paperNeeded << endl;
        totalNeeded += newPresent.paperNeeded;
        presentList.push_back( newPresent );
    }

    cout << "Total square feet: " << totalNeeded << endl;

    return 0;
}