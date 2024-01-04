/* CSCI 200: Assignment 3: L3A - String Fuctions
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): Office Hours used.
 *
 * The goal of this lab is to practice using and manipulating strings, passing via refrence.
 */

#include "string_functions.h"

unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) { // DONE
    char result = '\0';
    // TODO 01: set result to the character of a string at a given index
    result = STR[IDX];
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    // TODO 02: set result to the concatenation of strings LEFT and RIGHT
    result += RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) { //
    string result = STR;
    // TODO 03: set result to the result of inserting a string into another
    string str1 = STR;
    result = str1.insert(IDX,TO_INSERT);
    return result;
}

size_t string_find(const string STR, const char C)  {// Changed result to -1 // DONE
    size_t result = -1;
    // TODO 04: set result to the index of the first occurrence of the character
    for (long long int i = 0; i < int(STR.length()); i++){
        if (STR[i] == C){
            return i;
        }
    }
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) { // DONE
    string result = STR;
    // TODO 05: set result to be a substring starting at index of given length
    result = result.substr(IDX,LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) { // HELP HERE
    string result = STR;
    // // TODO 06: set result to be the string with the given text replaced    
    int pos = -1;
    pos = result.find(TEXT_TO_REPLACE);
    if (pos == -1){
        return result;
    }
    string str1 = result.substr(0,pos);
    string str2 = result.substr(pos + int(TEXT_TO_REPLACE.length()));
    result = str1 + REPLACE_WITH + str2;
    return result;
}

string string_first_word(const string STR)  { // DONE
    string result = STR;
    // TODO 07: set result to the first word from the string
    for (int i=0;i < int(result.length()); i++){
        if (result[i] == ' '){
            result = result.substr(0,i);
            return result;
        }
    }
    return result;
}

string string_remove_first_word(const string STR)  {
    string result = STR;

    // TODO 08: set result to be the string with the first word removed

    for (int i=0;i < int(result.length()); i++){
        if (result[i] == ' '){
            result = result.substr(i +1);
            return result;
        }
    }
    result = "";
    return result;

}
string string_second_word(const string STR)  {
    string result = STR;
    // TODO 09: set result to be the second word from the string
    int spaceCounter = 0;
    int firstSpace = 0;
  for (int i=0;i < int(result.length()); i++){
        // cout << result[i] << endl;
        if (result[i] == ' '){
           spaceCounter++;
            if (spaceCounter == 1){
            firstSpace = i;
            }
        }
        if (i +1 == int(result.length())){
            if (firstSpace != 0){
                result = result.substr(0,i+1);
                // cout << result << endl;
                result = result.substr(firstSpace+1,result.length());
                return result;
            }
            else{
                return result = "";
            }
        }
        else if (spaceCounter == 2){
            result = result.substr(0,i);
            result = result.substr(firstSpace+1,result.length());
            return result;
            }
        }
    return result;
}

string string_third_word(const string STR)  {
    string result = STR;
    bool INEEDBOOL = false;
    int spaceCount = 0;
    // int reqSpqce = 0;
    string sentresult = "";
    for (int i = 0; i < int(result.length()); i++){
        if (INEEDBOOL == true){
            if (result[i] != ' '){
                sentresult += result[i];
            }
            else{
                INEEDBOOL = false;
                return sentresult;
                // cout << "\n"<< "-" << sentresult << "-" << "\n";
            }
        }
        // cout << result[i];
        else if ((result[i] == ' ') && (spaceCount == 1)){
            INEEDBOOL = true;
            // reqSpqce = i;
            spaceCount++;
            // cout << "!";
            INEEDBOOL = true;
        }
        else if (result[i] == ' '){
            spaceCount++;
            // cout << "_";
        }
        else{
            // cout << result[i];
        }
    }

    return sentresult;
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    // TODO 11: set result to be the nth word from the string
    // string result = STR;
    bool INEEDBOOL = false;
    if (N == 1){
        INEEDBOOL = true;
    }
    
    int spaceCount = 2;
    // int reqSpqce = 0;
    string sentresult = "";
    for (int i = 0; i < int(result.length()); i++){
        if (INEEDBOOL == true){
            if (result[i] != ' '){
                sentresult += result[i];
            }
            else{
                INEEDBOOL = false;
                return sentresult;
                // cout << "\n"<< "-" << sentresult << "-" << "\n";
            }
        }
        // cout << result[i];
        else if ((result[i] == ' ') && (spaceCount == N)){
            INEEDBOOL = true;
            // reqSpqce = i;
            spaceCount++;
            // cout << "!";
            INEEDBOOL = true;
        }
        else if (result[i] == ' '){
            spaceCount++;
            // cout << "_";
        }
        else{
            // cout << result[i];
        }
    }
    return sentresult;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    vector<string> result;
    // TODO 12: split the string by the given deliminatr

    int lengthOfString = string_length(STR);
    std::string tempString1 = "";
    for (int i = 0; i < lengthOfString; i++){
        if (STR.at(i) != DELIMINATOR){
            tempString1 += STR[i];
        }
        else if(STR.at(i) == DELIMINATOR || i == lengthOfString){
            result.push_back(tempString1);
            tempString1 = ""; 
        }
    }
    result.push_back(tempString1);
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    // TODO 13: set result to be the string with all instances of TARGET replaced
    string result2 = "";
    for (int i =0; i < int(result.length()); i++){
        if (result[i] == TARGET){
            result2 += REPLACEMENT;
        }
        else{
            result2 += result[i];
        }
    }
    result = result2;
    return result;
}

string string_to_lower(const string STR) {
    string result = STR;
    // TODO 14: convert all characters to lower case
    string result2= "";
    for (int i = 0; i < int(result.length()); i++){
        if ( result[i] <= 122 && result[i] >= 97){
            // Lower to Upper 
            // char a = result[i] - 32;
            // result2 += result[i] - 32;
            result2 += result[i];
        }
        else if (result[i] >= 65 && result[i] <= 90){
            // Upper to lower
            // char a = result[i] + 32;
            result2 += result[i] + 32;
        }
        else{
            result2 += result[i];
        }
    }
    return result2;
}

string string_to_upper(const string STR) {
    string result = STR;
    // TODO 15: convert all characters to upper case
    string result2= "";
    for (int i = 0; i < int(result.length()); i++){
        if ( result[i] <= 122 && result[i] >= 97){
            // Lower to Upper 
            // char a = result[i] - 32;
            result2 += result[i] - 32;
            
        }
        else if (result[i] >= 65 && result[i] <= 90){
            // Upper to lower
            // char a = result[i] + 32;
            // result2 += result[i] + 32;
            result2 += result[i];
        }
        else{
            result2 += result[i];
        }
    }
    return result2;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    int char1 = 0;
    int char2 = 0;
    for (char i = 0; i < (int)LHS.length(); i++){
        char1 += (int)LHS[i];
    }
    for (char k = 0; k < (int)RHS.length(); k++){
        char2 += (int)RHS[k];
    }
    if (char1 < char2){
        return -1;
    }
    else if (char1 > char2){
        return 1;
    }
    else {
        return 0;
    }
    return result;
}