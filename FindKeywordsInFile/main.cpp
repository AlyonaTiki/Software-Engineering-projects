////#include <iostream>
//////#include "KeywordsInFile.h"
//////using namespace std;
////
//////int main() {
//////    cout << "test# 1 : 'idea' "<< endl;
//////    KeywordsInFile test("keywords.txt","text.txt");
//////    cout << "KeywordFound: "<< test.KeywordFound("idea") << endl;
//////    cout << "KeywordInLine: "<< test.KeywordInLine("Idea",2 )<< endl;
//////    cout << "TotalOccurrences: "<<test.TotalOccurrences("idea")<< endl;
//////    cout << test << endl;
//////
//////    cout << "test# 2 : 'vary' "<< endl;
//////    KeywordsInFile test2("keywords.txt","text.txt");
//////    cout << "KeywordFound: "<< test2.KeywordFound("vary") << endl;
//////    cout << "KeywordInLine: "<< test2.KeywordInLine("vary",6 )<< endl;
//////    cout << "TotalOccurrences: "<<test2.TotalOccurrences("vary")<< endl;
//////    cout << test2;
////
////
////////////////// find pairs that give sum
//////    unordered_set<int> s;
//////    s.insert(4);
//////    s.insert(3);
//////    s.insert(5);
//////    int x = 10;
//////    int foo [6] = { 10, 6, 5, 4, 5, 2 };
//////    unordered_map<int, int> m;
//////    for (int i = 0; i < 6; ++i){
//////        s.insert(foo[i]);
//////        if (s.count(x-foo[i])){
//////            cout << foo[i] << " " << x-foo[i] << endl;
//////        }
//////    }
////
//////    vector<int> vec = { 2, 0, 6, 1, 5, 3, 7 };
//////    int target = 6;
//////    unordered_set<int> S(vec.begin(), vec.end());
//////
//////    for (int i=0; i<vec.size(); i++) {
//////
//////        S.insert(vec[i]);
//////
//////        if (S.count(target - vec[i])) {
//////
//////            if (vec[i] != target - vec[i]) {
//////
//////                cout << vec[i] << " " << target - vec[i] << endl;
//////
//////            }
//////
//////        }
//////    }
//////    vector<int> vec = { 2, 0, 6, 1, 5, 3, 7 };
//////
//////        return 0;
////
/////////////////// find in string
//////    unordered_set<int> set1;
//////    unordered_set<int> set2;
//////    string s1 = "abd";
//////    string s2 = "aaabbbreebbbnmk66d";
//////
//////    for (int i = 0; i < s2.length(); ++i) {
//////        set2.insert(s2[i]);
//////    }
////// int foundCounter = 0;
//////    for (int i = 0; i < s1.length(); ++i) {
//////        if (set2.count(s1[i])){
//////            foundCounter++;
//////        } else {
//////            foundCounter--;
//////        }
//////    }
//////    if (foundCounter == s1.length()){
//////        cout << "found";
//////    } else {
//////        cout << " not found";
//////    }
////
////
/////////////////// find in range
//////    int range = 2;
//////    int counterFound;
//////    int arr [6] = { 10, 6, 5, 4, 5, 2 };
//////    unordered_set<int> s;
//////    for (int i = 0; i < 2; ++i) {
//////        s.insert(arr[i]);
//////    }
//////    for (int i = 0; i < range; ++i) {
//////        s.erase(arr[i]);
//////        if (s.count(arr[i])){
//////            counterFound++;
//////        }
//////    }
//////    s.count()
////
/////////////////// map insert, delete, print
//////        map["GeeksforGeeks"] = 10;
//////        map.insert(make_pair("e", 2.718));
////
//////        map.erase()
////
//////        for (auto x : umap)
//////            cout << x.first << " " << x.second << endl;
////
//////        or
////
//////        unordered_map<string, double>:: iterator itr;
//////        for (itr = umap.begin(); itr != umap.end(); itr++)
//////        {
//////            cout << itr->first << "  " << itr->second << endl;
//////        }
////
////
////
////
//////}
////#include <iostream>
////#include <stdexcept>
////#include <vector>
////#include <unordered_map>
////#include <unordered_set>
////#include <string>
////#include "KeywordsInFile.h"
////using namespace std;
////
////
////void testKeywordFound(KeywordsInFile &obj){
////    KeywordsInFile test("keywords.txt","text.txt");
////    cout << "KeywordFound: "<< test.KeywordFound("BBBB") << endl;
////
////    cout << "\n--------KeywordFound------\n";
////
////    if (!obj.KeywordFound("BBBB")){
////        cout << ">>>>> BBBB IS IN file but not found\n";
////    }
////
////    if (!obj.KeywordFound("AbaB")){
////        cout << ">>>>> AbaB IS IN file but not found\n";
////    }
////
////    if (obj.KeywordFound("aaB")){
////        cout << ">>>>> aaB NOT IN file but found\n";
////    }
////
////    if (obj.KeywordFound("abc")){
////        cout << ">>>>> abc NOT IN file but found\n";
////    }
////
////    if (!obj.KeywordFound("AAb")){
////        cout << ">>>>> AAb IS IN file but not found\n";
////    }
////
////    if (!obj.KeywordFound("z")){
////        cout << ">>>>> z IS IN file but not found\n";
////    }
////
////    if (!obj.KeywordFound("sun")){
////        cout << ">>>>> sun IS IN file but not found\n";
////    }
////}
////
////void testWordInLine(KeywordsInFile &obj) {
////
////    cout << "\n--------Keywords In Line------\n";
////    try{
////        if (obj.KeywordInLine("AbaB", 8) != 1) {
////            cout <<"AbaB on line 8 = 1 not " << obj.KeywordInLine("AbaB", 8) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " AbaB 8 = 1 \n";
////    }
////    try{
////        if (obj.KeywordInLine("Sun", 1) != 3) {
////            cout <<"Sun on line 1 = 3 not " << obj.KeywordInLine("Sun", 1) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " Sun 1 = 3\n";
////    }
////    try{
////        if (obj.KeywordInLine("Sun", 3) != 0) {
////            cout <<"Sun on line 3 = 0 not " << obj.KeywordInLine("Sun", 3) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " Sun 3 = 0\n";
////    }
////
////    try{
////        if (obj.KeywordInLine("AAb", 6) != 1) {
////            cout <<"AAb on line 6 = 1 not " << obj.KeywordInLine("AAb", 6) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " AAb 6 = 1\n";
////    }
////    try{
////        if (obj.KeywordInLine("abc", 4) != 0) {
////            cout <<"abc not on lon line i = 4 not " << obj.KeywordInLine("abc", 4) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " abc 4 = 0\n";
////    }
////    try{
////        if (obj.KeywordInLine("sun", 1) != 1) {
////            cout <<"sun on line 1 = 1 not " << obj.KeywordInLine("sun", 1) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " sun 1 = 1\n";
////    }
////    try{
////        if (obj.KeywordInLine("BBBB", 4) != 2) {
////            cout <<"BBBB on line 4 = 2 not " << obj.KeywordInLine("BBBB", 4) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " BBBB 4 = 2\n";
////    }
////    try{
////        if (obj.KeywordInLine("cba", 4) != 1 && obj.KeywordInLine("cba", 8) != 1) {
////            cout <<"cba on line 4 = 1, on line 8 = 1 not " << obj.KeywordInLine("cba", 4) << " " << obj.KeywordInLine("cba", 8) << endl;
////        }
////    } catch(const exception &e) {
////        cout << e.what() << " cba 4 = 1, 8 = 1\n";
////    }
////}
////
////void testOccurrences(KeywordsInFile &obj) {
////    cout << "\n--------Total Occurrences------\n";
////    if (obj.TotalOccurrences("aaB") != 0){
////
////        cout << ">>>>> aaB " << obj.TotalOccurrences("aaB") << endl;
////    }
////
////    if (obj.TotalOccurrences("cba") != 2){
////
////        cout << ">>>>> cba " << obj.TotalOccurrences("cba") << endl;
////    }
////
////    if (obj.TotalOccurrences("abc") != 0){
////
////        cout << ">>>>> abc " << obj.TotalOccurrences("abc") << endl;
////    }
////
////    if (obj.TotalOccurrences("AbaB") != 1){
////
////        cout << ">>>>> AbaB " << obj.TotalOccurrences("AbaB") << endl;
////    }
////
////    if (obj.TotalOccurrences("a") != 1){
////
////        cout << ">>>>> a " << obj.TotalOccurrences("a") << endl;
////    }
////
////    if (obj.TotalOccurrences("AAb") != 1){
////
////        cout << ">>>>> AAb " << obj.TotalOccurrences("AAb") << endl;
////    }
////
////    if (obj.TotalOccurrences("BBBB") != 3){
////
////        cout << ">>>>> BBBB " << obj.TotalOccurrences("BBBB") << endl;
////    }
////
////    if (obj.TotalOccurrences("z") != 2){
////
////        cout << ">>>>> z " << obj.TotalOccurrences("z") << endl;
////    }
////
////    if (obj.TotalOccurrences("sun") != 1){
////
////        cout << ">>>>> sun " << obj.TotalOccurrences("sun") << endl;
////    }
////    if (obj.TotalOccurrences("Sun") != 6){
////
////        cout << ">>>>> Sun " << obj.TotalOccurrences("Sun") << endl;
////    }
////}
////
////int main() {
////    string keywordsFile = "keywords.txt";
////    string textFile = "text.txt";
////    cout << "Failed tests:\n";
////    KeywordsInFile obj(keywordsFile, textFile);
////    testKeywordFound(obj);
////    testWordInLine(obj);
////    testOccurrences(obj);
////    cout << "\n----- Operator -------\n";
////    cout << obj << "----------------------\n";
////    return 0;
////}


int Meet (const vector<int>& vec) {

    std::set<int> S;

    S(vec.begin(), vec.end());

    int output;
    for (auto f : S) {

        output += S[i] - S[i + 1];

    }

    return output;
}
int main() {
    Meet({10, 1, 8, 4});
}