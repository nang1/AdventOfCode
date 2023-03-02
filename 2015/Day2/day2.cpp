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
    int totalPaper = 0;
    int totalRibbon = 0;
    for( vector<string>::iterator it = inputList.begin(); it != inputList.end(); ++it ) {
        Present newPresent( *it );
        newPresent.calculateSides();
        newPresent.calculatePaperNeeded();
        newPresent.calcualteRibbon();
        //cout << "smallest side: " << newPresent.smallestArea << " present needs: " << newPresent.paperNeeded << endl;
        totalPaper += newPresent.paperNeeded;
        totalRibbon += newPresent.ribbonNeeded;
        presentList.push_back( newPresent );
    }

    cout << "Total paper square feet: " << totalPaper << endl;
    cout << "Total ribbon feet: " << totalRibbon << endl;

    return 0;
}