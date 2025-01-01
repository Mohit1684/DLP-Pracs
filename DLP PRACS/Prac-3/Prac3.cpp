#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;


unordered_set<string> keywords = {
    "int", "float", "double", "char", "if", "else", "for", "while",
    "do", "switch", "case", "break", "continue", "return", "void",
    "class", "public", "private", "protected", "namespace", "using",
    "bool", "true", "false", "include", "main", "cout", "cin", "endl"};


unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=",
    "&&", "||", "!", "&", "|", "^", "<<", ">>", "++", "--", "+=", "-=",
    "*=", "/=", "%=", "&=", "|=", "^=", ".", "::"};

bool isKeyword(const string& word) {
    return keywords.find(word) != keywords.end();
}


bool isOperator(const string& word) {
    return operators.find(word) != operators.end();
}

bool isIdentifier(const string& word) {
    if (word.empty() || isdigit(word[0]) || isKeyword(word)) return false;
    for (char c : word) {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

bool isNumber(const string& word) {
    for (char c : word) {
        if (!isdigit(c) && c != '.') return false;
    }
    return !word.empty();
}

int main() {
    string filename;
    cout << "Enter the filename to analyze: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    bool insideComment = false;

    while (getline(file, line)) {
        string word;
        bool insideString = false;

        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];


            if (insideComment) {
                if (line[i] == '*' && line[i + 1] == '/') {
                    insideComment = false;
                    ++i;
                }
                continue;
            }

            if (line[i] == '/' && line[i + 1] == '*') {
                insideComment = true;
                ++i;
                continue;
            }

            if (line[i] == '/' && line[i + 1] == '/') {
                cout << "Comment: " << line.substr(i) << endl;
                break;
            }

            if (c == '"') {
                insideString = !insideString;
                if (!insideString) {
                    cout << "String: \"" << word << "\"" << endl;
                    word.clear();
                }
                continue;
            }

            if (insideString) {
                word += c;
                continue;
            }

            if (ispunct(c) && operators.find(string(1, c)) != operators.end()) {
                cout << "Operator: " << c << endl;
                continue;
            }

            if (isalnum(c) || c == '_') {
                word += c;
            } else {
                if (!word.empty()) {
                    if (isKeyword(word))
                        cout << "Keyword: " << word << endl;
                    else if (isIdentifier(word))
                        cout << "Identifier: " << word << endl;
                    else if (isNumber(word))
                        cout << "Number: " << word << endl;
                    word.clear();
                }
                if (ispunct(c)) {
                    cout << "Punctuation: " << c << endl;
                }
            }
        }


        if (!word.empty()) {
            if (isKeyword(word))
                cout << "Keyword: " << word << endl;
            else if (isIdentifier(word))
                cout << "Identifier: " << word << endl;
            else if (isNumber(word))
                cout << "Number: " << word << endl;
        }
    }

    file.close();

    return 0;
}
