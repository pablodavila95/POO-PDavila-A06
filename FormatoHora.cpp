//
// Created by Pablo on 26/02/2018.
//

#include "FormatoHora.h"
FormatoHora::FormatoHora(int h, int m, int s) {
    this->horas=h;
    this->minutos=m;
    this->segundos=s;
    //std::cout<<this->to_String()<<"\n";
}
bool FormatoHora::validaHrs(int) {
    bool horaCorrecta = true;
    if(horas>=0 && horas<=23){
        bool horacorrecta=true;
    }else if (horas<0 || horas>23){
        bool horacorrecta=false;
    }
}

bool FormatoHora::validaMS(int) {
    bool minutosYSegValidos = true;

    if(minutos>=0 && minutos<=59 && segundos>=0 && segundos <=59){
        bool minutosYSegvalidos= true;
    }else if (minutos<=0 || minutos>59 || segundos<=0 ||segundos>59 ){
        bool minutosYSegValidos=false;
    }
}
int FormatoHora::getHoras() {
    return horas;
}
int FormatoHora::getMinutos() {
    return minutos;
}
int FormatoHora::getSegundos() {
    return segundos;
}
std::string FormatoHora::to_String() {
    std::string muestraHora, muestraMinutos, muestraSegundos;
    muestraHora= (std::to_string(getHoras()));
    muestraMinutos= (std::to_string(getMinutos()));
    muestraSegundos= (std::to_string(getSegundos()));
    if (getMinutos() < 10 && getSegundos() <10) {
        return muestraHora+ ":0"+muestraMinutos+":0"+muestraSegundos;

    }
    else if (getMinutos()< 10) {
        return muestraHora+ ":0"+muestraMinutos+":"+muestraSegundos;
    }
    else if (getSegundos() < 10) {
        return muestraHora+ ":"+muestraMinutos+":0"+muestraSegundos;
    }
    else {
        return muestraHora+ ":"+muestraMinutos+":"+muestraSegundos;
    }

}

FormatoHora operator+(const FormatoHora &hi, const FormatoHora &hf) {
    int ht, mt, st;
    ht = hi.horas+hf.horas;
    mt = hi.minutos+hf.minutos;
    st = hi.segundos+hf.segundos;

    FormatoHora resultado(ht,mt,st);
    resultado.corregirHora(resultado);
    return resultado;
}

FormatoHora operator-(const FormatoHora &hi, const FormatoHora &hf) {
    int ht, mt, st;
    ht = hi.horas-hf.horas;
    mt = hi.minutos-hf.minutos;
    st = hi.segundos-hf.segundos;

    FormatoHora resultado(ht, mt, st);
    resultado.corregirHora(resultado);
    return resultado;
}

bool operator>(const FormatoHora &hi, const FormatoHora &hf) {
    int vTi, vTf;
    int h1,m1,s1,h2,m2,s2;
    bool valor;

    h1= hi.horas;
    m1= hi.minutos;
    s1=hi.segundos;

    h2=hf.horas;
    m2=hf.minutos;
    s2=hf.segundos;

    vTi = (h1*60) + m1;
    vTi = vTi * 60;
    vTi = s1 + vTi;

    vTf = (h2*60) + m2;
    vTf = vTf * 60;
    vTf = s2 + vTf;
    valor = vTi > vTf;
    return valor;
}

bool operator<(const FormatoHora &hi, const FormatoHora &hf) {
    int vTi, vTf;
    int h1,m1,s1,h2,m2,s2;
    bool valor;

    h1= hi.horas;
    m1= hi.minutos;
    s1=hi.segundos;

    h2=hf.horas;
    m2=hf.minutos;
    s2=hf.segundos;

    vTi = (h1*60) + m1;
    vTi = vTi * 60;
    vTi = s1 + vTi;

    vTf = (h2*60) + m2;
    vTf = vTf * 60;
    vTf = s2 + vTf;

    valor = vTi < vTf;
    return valor;
}

bool operator!=(const FormatoHora &hi, const FormatoHora &hf) {
    int vTi, vTf;
    int h1,m1,s1,h2,m2,s2;
    h1= hi.horas;
    m1= hi.minutos;
    s1=hi.segundos;

    h2=hf.horas;
    m2=hf.minutos;
    s2=hf.segundos;

    vTi = (h1*60) + m1;
    vTi = vTi * 60;
    vTi = s1 + vTi;

    vTf = (h2*60) + m2;
    vTf = vTf * 60;
    vTf = s2 + vTf;

    return vTf != vTi;
}

bool operator<=(const FormatoHora &hi, const FormatoHora &hf) {
    int vTi, vTf;
    int h1,m1,s1,h2,m2,s2;
    h1= hi.horas;
    m1= hi.minutos;
    s1=hi.segundos;

    h2=hf.horas;
    m2=hf.minutos;
    s2=hf.segundos;

    vTi = (h1*60) + m1;
    vTi = vTi * 60;
    vTi = s1 + vTi;

    vTf = (h2*60) + m2;
    vTf = vTf * 60;
    vTf = s2 + vTf;

    return vTf <= vTi;
}

bool operator>=(const FormatoHora &hi, const FormatoHora &hf) {
    int vTi, vTf;
    int h1,m1,s1,h2,m2,s2;
    h1= hi.horas;
    m1= hi.minutos;
    s1=hi.segundos;

    h2=hf.horas;
    m2=hf.minutos;
    s2=hf.segundos;

    vTi = (h1*60) + m1;
    vTi = vTi * 60;
    vTi = s1 + vTi;

    vTf = (h2*60) + m2;
    vTf = vTf * 60;
    vTf = s2 + vTf;

    return vTf >= vTi;
}

bool FormatoHora::corregirHora(FormatoHora &i) {
    int v1,v2,v3;
    v1 = i.getHoras();
    v2 = i.getMinutos();
    v3 = i.getSegundos();

        if (v3>60) {
            v3 = v3 - 60;
            v2++;
            //setMinutos(v2);
            //setSegundos(v3);
        }

        if (v2>60) {
            v2 = v2 - 60;
            v1++;
            //setHoras(v1);
            //setMinutos(v2);
        }

        if (v1>24) {
            v1 = v1 - 24;
            //setHoras(v1);
        }

    i.setHoras(v1);
    i.setMinutos(v2);
    i.setSegundos(v3);
    }

void FormatoHora::setHoras(const int &h) {
    this->horas = h;
}

void FormatoHora::setMinutos(const int &m) {
    this->minutos = m;
}

void FormatoHora::setSegundos(const int &s) {
    this->segundos = s;
}


