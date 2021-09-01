#include <iostream>
#include "Field.h"
#include <vector>
using namespace std;

int main() {
//    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> _2d_array{{1,0,3,4,5,0},{1,0,3,4,5,0},{1,0,3,4,5,0},{1,0,3,4,5,4},{9,0,2,2,1,1},{1,1,1,8,1,1}};
//    vector<vector<int>> _2d_array2{{1,6,3,4,3,6}, {1,3,3,4,5,4}, {6,2,3,4,3,4},{1,0,3,4,5,0},{1,0,3,4,5,0},{1,0,3,4,5,0}};
//    vector<vector<int>>  another;
//
//    Field my_field1 (_2d_array); //should call move?, but calls copy
//    my_field1 = move(another);//calls move
//
//    Field my_field ({{1,6,3,4,3,6}, {1,3,3,4,5,4}, {6,2,3,4,3,4},{1,0,3,4,5,0},{1,0,3,4,5,0},{1,0,3,4,5,0}});
//
//
//    cout << endl;
//    cout << "weight: " << my_field1.Weight(5,0,0,2) << endl;
//    cout << "path cost: " << my_field1.PathCost();
//    cout << endl;
//    cout << "weight: " << my_field.Weight(5,3,2,2) << endl;
//    cout << "path cost: " << my_field.PathCost();
    vector <int> InEachRow(const vector<vector<int>> input){

        vector<int> V;

        if (input.size() == 0 ){ return V;}

        unordered_map<int, int > lineOcc;

        unordered_set<int> occ;

        for(int i=0; i<input.size(); i++){ //row

            for(int j=0; j<input[0].size(); j++){ //col

                int val = input[i][j];

                lineOcc[val] = i;

            }}

        for(k=0; k<input.size(); k++){

            if (lineOcc.count(input[k])){

                V.push_back(input[k]);

            }

            return V;

        }





    }
}