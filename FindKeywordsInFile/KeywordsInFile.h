//declaration of the class KeywordsInFile

#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class KeywordsInFile {
private:
    std::unordered_set<std::string> keyWords; // keywords
    std::unordered_map<std::string, int> totalOcc; // total number of occurrences (key: keyword, value: number of times occurred)
    std::unordered_map<std::string, std::vector<size_t> > lineOcc; // map with key: keyword and value: vector of line numbers where word occurred
public:
    KeywordsInFile() = delete; // disabled default constructor
    KeywordsInFile(std::string filename_with_keywords,std::string filename_with_text); // constructor
    bool KeywordFound(std::string keyword); // returns true if the specified keyword was found in the text. Returns false otherwise.
    int KeywordInLine(std::string keyword,int line_number); //returns the number of times the specified keyword was seen in the specified line of the text
    int TotalOccurrences(std::string keyword); // returns the total number of the occurrences of the given keyword in the text
    friend std::ostream& operator << (std::ostream&, KeywordsInFile); // allows to use object of the class with 'cout'
};





