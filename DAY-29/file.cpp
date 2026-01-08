#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void writeFile(const string &filename, const string &content) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
        cout << "File written successfully." << endl;
    } else {
        cout << "Error opening file for writing." << endl;
    }
}