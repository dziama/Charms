#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include "wyrazenia.h" //biblioteka wyrazen dla parsera

using namespace std;

Wyrazenie* parser(const string& onp){
    vector<string> tokens = split_by_space(onp);
    //pętla po tokenach tworząca stos=drzewo
    stack<Wyrazenie*> stos;
    for(int i = 0; i < tokens.size(); i++) {
        if(tokens[i]=="x"){
             stos.push(new Zmienna());
        }
        else {
            if(tokens[i]=="+"){
                Wyrazenie* arg1 = stos.top();
                stos.pop();
                Wyrazenie* arg2 = stos.top();
                stos.pop();
                stos.push(new Dodawanie(arg2, arg1));
            }
            else {
                    if(tokens[i]=="-"){
                       Wyrazenie* arg1 = stos.top();
                       stos.pop();
                       Wyrazenie* arg2 = stos.top();
                       stos.pop();
                       //kolejnosc ma znaczenie
                       stos.push(new Odejmowanie(arg2, arg1));
                    }
                    else{
                        if(tokens[i]=="*"){
                            Wyrazenie* arg1 = stos.top();
                            stos.pop();
                            Wyrazenie* arg2 = stos.top();
                            stos.pop();
                            stos.push(new Mnozenie(arg2, arg1));
                        }
                        else{
                            if(tokens[i]=="/"){
                                Wyrazenie* arg1 = stos.top();
                                stos.pop();
                                Wyrazenie* arg2 = stos.top();
                                stos.pop();
                                //kolejnosc ma znaczenie
                                stos.push(new Dzielenie(arg2, arg1));
                            }
                            else{
                                if(tokens[i]=="cos"){
                                    Wyrazenie* arg1 = stos.top();
                                    stos.pop();
                                    stos.push(new Cosinus(arg1));
                                }
                                else{
                                    if(tokens[i]=="sin"){
                                        Wyrazenie* arg1 = stos.top();
                                        stos.pop();
                                        stos.push(new Sinus(arg1));
                                    }
                                    else{
                                        if(tokens[i]=="log"){
                                            Wyrazenie* arg1 = stos.top();
                                            stos.pop();
                                            stos.push(new LogarytmNaturalny(arg1));
                                        }
                                        else{
                                            if(tokens[i]=="^"){
                                                Wyrazenie* arg1 = stos.top();
                                                stos.pop();
                                                Wyrazenie* arg2 = stos.top();
                                                stos.pop();
                                                //odwracamy kolejnosc (kolejnosc ma znaczenie)
                                                stos.push(new Potega(arg2, arg1));
                                            }
                                            else{
                                                //zakładamy na razie że to liczba
                                                stos.push(new StalaLiczbowa(atof(tokens[i].c_str())));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
return stos.top();
}

