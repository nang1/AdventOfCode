#include <fstream>
#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) {
    
    if ( argc < 2 ) {
        cout << "Mising input file" << endl;
        return 1;
    } 
    
    fstream fileInput{ argv[1] };

    int floorNum = 0;
    char fileChar;
    int charPosition = 0;
    bool reachedBasement = false;

    while( fileInput >> fileChar ) {
        charPosition++;

        if( fileChar == '(' ) {
            floorNum++;
        } else if( fileChar == ')' ) {
            floorNum--;
        }

        /***** Answer to Part 2 *****/
        if( floorNum == -1 && !reachedBasement) {
            reachedBasement = true;
            cout << "The first time Santa reached the basement was at position: " << charPosition << endl;
        }
    }

    /***** Answer for Part 1 *****/
    cout << "Santa is on floor: " << floorNum << endl;
    return 0;
}