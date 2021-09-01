//implementation of the class Field

#include "Field.h"
using namespace std;

Field::Field(const vector<vector<int>> & trg) {
    if (trg.size() == 0){
        throw out_of_range("empty vector provided");
    }
    row = trg.size();
    col = trg[0].size();
    values = trg;

    if (row >= 1) { //if size of 2d vector at least = 1
        //precalculation for Weigth method and pathCost method
        pathCost = sums = values; //copy all values to sums and pathCost
        //calculate sums of row 0, store in pathCost and sums
        for (int i = 1; i < col; i++) {
            pathCost[0][i] = sums[0][i] += sums[0][i - 1];
        }

        for (int i = 1; i < row; i++) {
            pathCost[i][0] = sums[i][0] += sums[i - 1][0]; //calculate sums of column 0, store in pathCost and sums
            for (int j = 1; j < col; j++) {
                sums[i][j] +=
                        sums[i - 1][j] - sums[i - 1][j - 1] + sums[i][j - 1]; //calculate the rest of values for sums
                pathCost[i][j] += min(pathCost[i - 1][j], pathCost[i][j - 1]);
            }
        }
    }
}

Field::Field(std::vector<std::vector<int>> && trg) {
    if (trg.size() == 0){
        throw out_of_range("empty vector provided");
    }
    row = trg.size();
    col = trg[0].size();
    values = move(trg);

    if (row >= 1) { //if size of 2d vector at least = 1
        //precalculation for Weigth method and pathCost method
        pathCost = sums = values; //copy all values to sums and pathCost
        //calculate sums of row 0, store in pathCost and sums
        for (int i = 1; i < col; i++) {
            pathCost[0][i] = sums[0][i] += sums[0][i - 1];
        }

        for (int i = 1; i < row; i++) {
            pathCost[i][0] = sums[i][0] += sums[i - 1][0]; //calculate sums of column 0, store in pathCost and sums
            for (int j = 1; j < col; j++) {
                sums[i][j] +=
                        sums[i - 1][j] - sums[i - 1][j - 1] + sums[i][j - 1]; //calculate the rest of values for sums
                pathCost[i][j] += min(pathCost[i - 1][j], pathCost[i][j - 1]);
            }
        }
    }
}


int Field::Weight( int x1, int y1, int x2, int y2 ){ // returns the sum of all elements in the rectangle defined by the points
    if (row == 0) {
        return 0;
    }
    if(y1 >= row || y2 >= row || x1 >= col || x2 >= col || 0 > y1 || 0 > y2 || 0 > x1 || 0 > x2 ) {
        throw out_of_range("Position is out of the range");
    }else{
        //calculate minimum values to determine starting point
        int minY = min(y1, y2);
        int minX = min(x1, x2);
        //calculate maximum values to determine ending point
        int maxY = max(y1, y2);
        int maxX = max(x1, x2);

        int result;
        if (minX == 0 && minY == 0){
            result =  sums[maxY][maxX];
        } else if (minY == 0){
            result = sums[maxY][maxX]  - sums[maxY][minX-1];
        } else if (minX == 0){
            result = sums[maxY][maxX] - sums[minY-1][maxX];
        } else {
            result = sums[maxY][maxX] + sums[minY-1][minX-1] - sums[minY-1][maxX] - sums[maxY][minX-1];
        }
        return result;
    }
}

int Field::PathCost() {  // returns the cost of the cheapest path from top-left corner to the bottom-right corner
    if (row == 0) {
        return 0;
    }
    return pathCost[row-1][col-1];
}