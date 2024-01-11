#include <iostream>
using namespace std;

class carta
{
    public:
        carta();
        void tomarCartas(int& jugadorSuma, int& dealerSuma);
        void mostrarResultado(int jugadorSuma, int dealerSuma, int &dinero, char& tecla, bool &finalizado);

    private:
        string letra[4] {"A", "J", "Q", "K"};
        string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};
};

