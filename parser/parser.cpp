#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <stdexcept>
#include "wyrazenia.h" //biblioteka wyrazen dla parsera

using namespace std;

// pomocniczy stos, który rzuca wyj¹tkami zamiast powodowaæ crash
class throwing_stack : public stack<Wyrazenie*> {
public:
    const_reference top() const {
        if(empty())
            throw logic_error("pusty stos");
        else
            return stack<Wyrazenie*>::top();
    }
};

Wyrazenie* parser(const string& onp){
    vector<string> tokens = split_by_space(onp);
    //pêtla po tokenach tworz±ca stos=drzewo
    throwing_stack stos;
    for(unsigned int i = 0; i < tokens.size(); i++) {
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
                                                //zakÅ‚adamy na razie Å¼e to liczba
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

