//declaration of the class Field

#pragma once
#include <iostream>
#include <vector>

class Field {
private:
    int col, row; // dimensions
    std::vector<std::vector<int>> values; // values of matrix
    std::vector<std::vector<int>> sums; // sums of matrix's values from starting point
    std::vector<std::vector<int>> pathCost; // path costs from top-left corner of the field to the bottom-right corner
public:
    Field( const std::vector<std::vector<int>> & trg); // copy constructor
    Field( std::vector<std::vector<int>> && trg); // move constructor
    int Weight( int x1, int y1, int x2, int y2 ); // returns the sum of all elements in the rectangle defined by the points
    int PathCost(); // computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner
};


