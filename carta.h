#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class carta
{
    public:
        Carta();
        void tomarCartas(int& jugadorSuma, int& dealerSuma);
        void mostrarResultado(int jugadorSuma, int dealerSuma, int &dinero, char& tecla, bool &finalizado);

    private:
        string letra[4] {"A", "J", "Q", "K"};
        string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};
};

//Metodos del main que seran usados en carta.cpp
void jugadorGana(int& dinero);
void jugadorPierde(int& dinero);

#endif // CARTA_H
