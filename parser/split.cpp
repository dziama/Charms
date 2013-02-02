#include "split.h"
#include <vector>
#include <cstring>
using namespace std;

    vector<string> split_by_space(const string& str){
        vector<string> tokens;
        string buf = "";
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != ' ') {
                buf += str[i];
            }
            else {
                if(buf != "")
                    tokens.push_back(buf);
                buf = "";
            }
        }
        // ostatni token
        if(buf != "")
            tokens.push_back(buf);
        return tokens;
    }
/*Wyrazenie* make_wyrazenie(vector<string>tokens){
    //tu bedzie wyrazenie
    for(int i = 0; i < tokens.size(); i++) {

    ;}
}

Wyrazenie* parser(const string& str){
    vector<string> tokens;
    stack<Wyrazenie*> stos;
    //funkcja wrzucania tokenow
    split_by_spaces(str);
    //funkcja ktora z tokenów zrobi wyrazenie
    make_wyrazenie(tokens);
}
*/
