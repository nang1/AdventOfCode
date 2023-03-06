#include <iostream> // cout
#include <fstream> // fstream
// #include <sstream> // stringstream
#include <string>
#include <vector>

using namespace std;

class Coordinate {
    public:
    int x;
    int y;

    Coordinate(int givenX, int givenY){
        x = givenX;
        y = givenY;
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

    vector<Coordinate> inputList;
    char inputChar;
    int santaX = 0;
    int santaY = 0;

    // Start Santa at coordinate (x,y) = (0,0)
    Coordinate starting(santaX, santaY);
    inputList.push_back(starting);

    // For each character, adjust x or y coordinate and push to vector
    while( fileInput >>  inputChar ) {
        if(inputChar == '>')
            santaX++;
        else if(inputChar == '<')
            santaX--;
        else if(inputChar == '^')
            santaY++;
        else
            santaY--;

        Coordinate newCoordinate(santaX, santaY);
        inputList.push_back( newCoordinate );
    }
    fileInput.close();

    // Remove duplicate coordinates
    for( vector<Coordinate>::iterator it = inputList.begin(); it != inputList.end(); ++it ) {
        Coordinate currentCoord( *it );
    }

    return 0;
}