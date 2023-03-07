#include <algorithm> // unique, distance
#include <iostream> // cout
#include <fstream> // fstream
#include <vector>

using namespace std;

class Coordinate {
    public:
    int x;
    int y;

    Coordinate(){
        x = 0;
        y = 0;
    }

    Coordinate(int givenX, int givenY){
        x = givenX;
        y = givenY;
    }
};

bool sortCoordinates( Coordinate one, Coordinate two ) {
    if(one.x < two.x || (one.x==two.x && one.y < two.y))
        return true;
    return false;
}

bool compareCoordinates( Coordinate one, Coordinate two ) {
    if(one.x == two.x && one.y == two.y)
        return true;

    return false;
}

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

    // Based the following on this example
    // https://cplusplus.com/reference/algorithm/unique_copy/
    
    // Sort coordinates
    sort(inputList.begin(), inputList.end(), sortCoordinates);
    
    // Remove duplicates
    vector<Coordinate>::iterator it;
    it = unique(inputList.begin(), inputList.end(), compareCoordinates);

    // Resize vector to hold only the unique coordinates
    inputList.resize(distance(inputList.begin(), it));
    
    cout << inputList.size() << endl;

    return 0;
}