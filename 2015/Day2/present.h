#include <algorithm> // min
#include <sstream> // stringstream
#include <string>
#include <vector>

using namespace std;

class Present {
    public:
    int length;
    int width;
    int height;
    int smallestSide;
    int paperNeeded;
    int lw, wh, hl;

    Present(){
        length = 0;
        width = 0;
        height = 0;
        smallestSide = 0;
        paperNeeded = 0;
        lw = 0;
        wh = 0;
        hl = 0;
    }

    Present( string dimensions ) {
        stringstream ss( dimensions );

        vector< string > pieces;
        string aPart;
        while( getline( ss, aPart, 'x' ) ){
            pieces.push_back( aPart );
        }

        length = stoi( pieces[ 0 ] );
        width = stoi( pieces[ 1 ] );
        height= stoi( pieces[ 2 ] );
    }

    void calculateSides(){
        lw = length * width;
        wh = width * height;
        hl = height * length;

        smallestSide = min( min(lw, wh), hl);
    }

    void calculatePaperNeeded(){
        paperNeeded = 2*lw + 2*wh + 2*hl + smallestSide;
    }
};