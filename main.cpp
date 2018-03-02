#include <iostream>
#include <cmath>
#include "FormatoHora.h"
int main(){

    int h1,m1,s1,h2,m2,s2;
    bool valor;

    std::cout<<"Hora de inicio: (Hora minutos segundos) \n";
    std::cin >> h1;
    std::cin >> m1;
    std::cin >> s1;

    std::cout<<"Hora de final: (Hora minutos segundos)\n";
    std::cin >> h2;
    std::cin >> m2;
    std::cin >> s2;

    FormatoHora horaS1(h1,m1,s1);
    FormatoHora horaS2(h2,m2,s2);

    valor = horaS1 < horaS2;
    valor = horaS1 > horaS2;
    valor = horaS1 <= horaS2;
    valor = horaS1 >= horaS2;
    valor = horaS1 != horaS2;


    return 0;
}