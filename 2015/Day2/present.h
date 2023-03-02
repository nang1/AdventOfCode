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
    int smallestArea;
    int paperNeeded;
    int lw, wh, hl;
    int ribbonNeeded;

    Present(){
        length = 0;
        width = 0;
        height = 0;
        smallestArea = 0;
        paperNeeded = 0;
        lw = 0;
        wh = 0;
        hl = 0;
        ribbonNeeded = 0;
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

        smallestArea = min( min(lw, wh), hl);
    }

    void calculatePaperNeeded(){
        paperNeeded = 2*lw + 2*wh + 2*hl + smallestArea;
    }

    void calcualteRibbon(){
        int smallestSide = length;
        int secondSmallest = length;

        if( width < smallestSide ) {
            smallestSide = width;
        } else {
            secondSmallest = width;
        }

        if( height < smallestSide ) {
            smallestSide = height;
        } else if ( height < secondSmallest ) {
            secondSmallest = height;
        }

        ribbonNeeded = (2*smallestSide + 2*secondSmallest) + (length*width*height);
    }
};