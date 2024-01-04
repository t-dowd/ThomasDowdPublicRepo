#include <iostream>
#include <fstream>

using namespace::std;

int main(){
    char lineOut;
    char ch;
    char a;
    ifstream reader("secretMessage.txt");
    ofstream writer("output.txt");
    while(!reader.eof()){
        while(reader.get(ch)){
            if (ch == '~'){
                cout << " ";
                ch = ' ';
                writer << ch;
            }
            else if (ch == '\n'){
                writer << '\n';
                cout << endl;
            }
            else {
                cout << (char)(ch+1);
                a = (char)(ch+1);
                writer << a;
            }
            }
        }
    writer.close();
    reader.close();
    return 0;
}