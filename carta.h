#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class carta
{
    public:
        Carta();
        void tomarCartas(int& suma, int& dealerSuma);
        void mostrarResultado(int& suma, int& dealerSuma, int& dinero, char& tecla, bool &finalizado);

    private:
        string letra[4] {"A", "J", "Q", "K"};
        string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};
};

void jugadorGana(int& dinero, int& suma);
void jugadorPierde(int& dinero, int& suma);
int ingresarTecla(char tecla, int dinero);

#endif // CARTA_H
