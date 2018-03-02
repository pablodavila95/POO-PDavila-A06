//
// Created by Pablo on 26/02/2018.
//

#ifndef POO_PDAVILA_A06_FORMATOHORA_H
#define POO_PDAVILA_A06_FORMATOHORA_H


#include <iostream>

class FormatoHora {
    friend FormatoHora operator+ (const FormatoHora &hi ,const FormatoHora &hf);
    friend FormatoHora operator- (const FormatoHora &hi ,const FormatoHora &hf);
    friend bool operator> (const FormatoHora &hi ,const FormatoHora &hf);
    friend bool operator< (const FormatoHora &hi ,const FormatoHora &hf);
    friend bool operator!= (const FormatoHora &hi ,const FormatoHora &hf);
    friend bool operator>= (const FormatoHora &hi ,const FormatoHora &hf);
    friend bool operator<= (const FormatoHora &hi ,const FormatoHora &hf);

//Atributos de la clase FormatoHora.
private:
    int horas;
    int minutos;
    int segundos;
//Metodos de la clase FormatoHora.
public:
    FormatoHora(int h, int m, int s);
    bool corregirHora(FormatoHora &i);
    int getHoras();
    int getMinutos();
    int getSegundos();


    std::string to_String();
    bool validaHrs(int);
    bool validaMS(int);

    void setHoras(const int& h);

    void setMinutos(const int& m);

    void setSegundos(const int& s);
};



#endif //POO_PDAVILA_A06_FORMATOHORA_H
