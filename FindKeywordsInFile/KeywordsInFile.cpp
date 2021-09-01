//implementation of the class KeywordsInFile

#include "KeywordsInFile.h"
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

KeywordsInFile::KeywordsInFile(string filename_with_keywords,string filename_with_text) // constructor
{
    char letter;
    string word;
    int lineCounter = 1;

    //read file with keywords and store them in unordered set
    ifstream readKeywords(filename_with_keywords); // open file with keywords
    while (readKeywords.get(letter)) // read each character
    {
        if (isalpha(letter)) // if character is letter, then concatenate to get word
        {
            word = word + letter;
        }else{
            keyWords.insert(word); //insert keyword in unordered_set
            word = "";
        }
    }
    if (word != "")
        keyWords.insert(word); //insert last word
    word = "";

    unordered_set<string> :: iterator itr; //create iterator for the set of keywords
    readKeywords.close(); //close file

    //read file with text, find keywords and store results in 2 unordered maps: totalOcc(total number of occurrences) & lineOcc(number of occurrences in each line)
    ifstream readTxt(filename_with_text); // open file with text
    while (readTxt.get(letter)) // read each character
    {
        if (isalpha(letter)) // if character is letter, then concatenate to get word
        {
            word = word + letter;
        }else{
            //insert word in unordered_map with total occurrences and line occurrences
            for (itr = keyWords.begin(); itr != keyWords.end(); itr++)
            {
                if (*itr == word && word != "")
                {
                    totalOcc[word]++; //unordered map that tracks how many words detected in total (key: keyword, value: number of times occurred)
                    lineOcc[word].push_back(lineCounter); //unordered map that tracks how many words detected in each line (key: keyword and value: vector of line numbers where word occurred)
                }
            }
            if (letter == '\n')
                lineCounter++; //detect new line and incremet line counter
            word = "";
        }
    }
    readTxt.close(); // close file
    for (itr = keyWords.begin(); itr != keyWords.end(); itr++)//insert last word
        if (*itr == word && word != "")
            totalOcc[word]++;
}

bool KeywordsInFile::KeywordFound(string keyword) // returns true if the specified keyword was found in the text. Returns false otherwise.
{
    if (totalOcc.count(keyword))
        return true;
    return false;
}

int KeywordsInFile::KeywordInLine(string keyword, int line_number) //returns the number of times the specified keyword was seen in the specified line of the text
{
    int found_lower_ind = 0;
    int found_upper_ind = 0;
    if (lineOcc.count(keyword)){
        found_upper_ind = upper_bound(lineOcc[keyword].begin(), lineOcc[keyword].end(), line_number) - lineOcc[keyword].begin();
        found_lower_ind = lower_bound(lineOcc[keyword].begin(), lineOcc[keyword].end(), line_number) - lineOcc[keyword].begin();
        return found_upper_ind - found_lower_ind;
    }
    return 0;
}

int KeywordsInFile::TotalOccurrences(string keyword) // returns the total number of the occurrences of the given keyword in the text
{
    if (totalOcc.count(keyword))
        return totalOcc.at(keyword);
    return 0;
}

ostream& operator << (ostream& out, KeywordsInFile obj) // allows to use object of the class with 'cout'
{
    for (auto p : obj.totalOcc)
        out << p.first << ": " << p.second << endl;
    return out;
}