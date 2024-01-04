/* CSCI 200: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): N/A
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * The Function file in tandem with the word functions.h and main file. The functions below count occurrences of each word & letter and display the frequencies.
 * "This program reads in a text file and parses the contents to count word data."
 */

#include<iostream>          //Input Output Stream
#include<fstream>           //File Input and Output
#include<vector>            //Vector Library
#include<string>            //String Library
#include<iomanip>           //Cout Manipulation
#include "word_functions.h" //Related Header file
using namespace std;

bool open_file(std::ifstream& streamin, const std::string fileString){ //Grabs the strings from the file.
    streamin.open(fileString);
    if ((streamin.is_open() == true)){ // Checks that the file exists
        return true;
    }
    else{
        return false;
    }
}
std::vector<std::string> read_words_from_file(std::ifstream& streamin){ // Puts all of the words and characters into an vector. Omits the Null ascii chracter a
    vector <string> allwords;                                           // at the end of the file.
    while (!streamin.eof()){
        string tempstr = " ";
        streamin >> tempstr;
        allwords.push_back(tempstr);}
    // allwords.pop_back();                  // Removing the EOF line
    return allwords;
}
void remove_punctuation(std::vector<std::string>& bigVector, std::string const PUNCTTOREMOVE){
    for (int i =0; i < int(bigVector.size()); i++){
        string tempstr = bigVector.at(i);               
        string retstring = "";
        for (int k =0; k < (int)tempstr.size();k++){
            char a = ' ';
            a = tempstr.at(k);
            if ((int)a <= 32){  //Omits all non printable characters. 
            continue;
            }
            else if(((int)a <= 47 && (int)a >= 33) || ((int)a >= 58 && (int)a <= 64 )|| ((int)a <= 96 && (int)a >= 91) || ((int)a <= 126 && (int)a > 123)){
                continue;
            }                   
            else{
                retstring += a; //Puts a valid character into the string that is returned.
            }
        }
        bigVector.at(i) = retstring;
    }
}
void capitalize_words(std::vector<std::string>&bigVecotrNoPunct){
 for (int i =0; i < int(bigVecotrNoPunct.size()); i++){
        string tempstr = bigVecotrNoPunct.at(i);
        string retstring = "";
        for (int k =0; k < (int)tempstr.size();k++){
            char a = ' ';
            a = tempstr.at(k);
            if ((int)a <= 32){
                continue;
            }
            else if((int)a <= 122 && (int)a >= 97){ //If the Ascii value of the character is mapped to a lowecase letter, capitalize it.
                retstring += (int)a - 32;
                continue;
            }
            else{
                retstring += a;
            }
        }
        bigVecotrNoPunct.at(i) = retstring;
    }
}
std::vector<std::string> filter_unique_words(std::vector<std::string>&bigVecotrNoPunctNoCaps){
    std::vector<std::string> arrayNoDupes;
    for (int i =0; i < (int)bigVecotrNoPunctNoCaps.size(); i++){
        bool equality_check = false;        // is this value equal to anything on the list so far?
        if ((int)arrayNoDupes.size() == 0){ // makes it so that arraynodupes will never have a size of zero
                arrayNoDupes.push_back(bigVecotrNoPunctNoCaps.at(i));
                continue;
                }
        for(int k=0; k < (int)arrayNoDupes.size();k++){
            if (bigVecotrNoPunctNoCaps.at(i) == arrayNoDupes.at(k)){ //If the string is already in the NoDupe array. 
                equality_check = true;
                continue;
            }
            else{
            }
        }
        if(equality_check == false){
            arrayNoDupes.push_back(bigVecotrNoPunctNoCaps.at(i));
            equality_check = false;
        }        
    }
return arrayNoDupes;
}
std::vector<unsigned int> count_unique_words(std::vector<std::string>& allWords, std::vector<std::string>& bigVectorFilterdUniqueWords){
    std::vector<unsigned int> filteredWordCount;
    for (int i = 0; i < (int)bigVectorFilterdUniqueWords.size(); i++){
        filteredWordCount.push_back(0);     // Initalizes this array with .size() values of zero.
    } 
    for (int i = 0; i < (int)bigVectorFilterdUniqueWords.size(); i++){
        for (int k = 0; k < (int)allWords.size(); k++){
            if (allWords.at(k) == bigVectorFilterdUniqueWords.at(i)){ //counts the unique words.
                filteredWordCount.at(i) += 1;
            }
        }
    }
    return filteredWordCount;
}
void count_letters(std::vector<std::string>& bigVector, unsigned int (&letters)[26]){
    for(int i = 0; i < (int)bigVector.size(); i++){
        for (int k = 0; k < (int)bigVector.at(i).size(); k++){
            letters[(int)bigVector.at(i)[k]-65] += 1;           //The Ascii values-65 map to an index of the array.
        }
    }
}
void print_letter_counts(unsigned int (&letters)[26]){
    for (int i = 0; i < 26; i++){
        cout << char(i + 65) <<  ": " << letters[i]<< endl;     //Simple print statement.
    }
}
void print_unique_word_counts(std::vector<std::string>& bigVector, std::vector<unsigned int> uniqueWordCounts){
    if (bigVector.size() != uniqueWordCounts.size()){ // error message.
        cerr << "Size of Unique words: " << bigVector.size() << "\nSize of Unique word count: " << uniqueWordCounts.size();
        return;
    }
    int setwless20 = 0;
    for (int i = 0; i < (int)bigVector.size();i++){
        if((int)bigVector.at(i).length() > setwless20){
            setwless20 = (int)bigVector.at(i).size();
        }

    }
    for (int i = 0; i < (int)bigVector.size();i++){
    cout.width(setwless20); cout << std::left << bigVector.at(i)<< ": " << std::right << uniqueWordCounts.at(i) << endl;
    }
}
void print_max_min_letter(unsigned int (&letters)[26]){
    char min; 
    double minint = letters[0];
    char max;
    double maxint = 0;
    int totalchar = 0;
    for (int i = 0; i < 26; i++){
        // cout << totalchar<<endl;
        totalchar += letters[i];
        if (letters[i] > maxint){
            max = (char)(i+65);
            maxint = int(letters[i]);
        }
        if (letters[i] < minint){
            min = (char)(i+65);
            minint = int(letters[i]);
        }

    }
    // A very sketchy print function
    int widthset = to_string((int)maxint).length();
    double x =(double) minint / (double)totalchar;
    double y = (double) maxint / (double)totalchar;
    cout << "Least Frequent Letter: " << min << " "; cout << right << setw(widthset) << minint;
    cout << fixed; cout << " ( " << right <<setprecision(3) << x*100 << "%)"<< endl;
    cout << " Most Frequent Letter: " << max << " "; cout << right << setprecision(0) << setw(widthset) << maxint;
    cout << fixed; cout << " ( " << right <<setprecision(3) << y*100 << "%)"<<endl;
 }