#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
using namespace std;

int main()
{

    SetConsoleTitle("Blackjack");

    repetir:
    int suma = 0;
    int dealerSuma = 0;
    int tecla;
    int dinero;
    string letra[4] {"A", "J", "Q", "K"};
    string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};

    cout << "Escribe la cantidad de dinero que usaras"  << endl;
    cin >> dinero;
    cout << "\n";

    blackjack:

    srand(time(0));
    int numero = rand() % 11;
    int dealerNumero = rand() % 11;
    int random = rand() % 4;
    int dealerRandom = rand() % 4;
    suma = suma + numero;
    dealerSuma = dealerSuma + dealerNumero;

    //resultados
    if(suma == 21) {


        _cputs("21 puntos,  Ganador!! \n\nPresiona E para jugar otra vez o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

            cout << "Tienes "  << dinero << "$\n" << endl;
            goto repetir;
        }

        else if(tecla == 'x'){

            cout << "Tienes "  << dinero << "$" << endl;
            return 0;
        }
     }

     if(suma > 21){

        suma = 0;
        dinero = 0;
        _cputs("Tienes mas de 21 puntos, perdedor!\n\nPresiona E para jugar otra vez o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

        cout << "Ahora tienes " << dinero << "$\n" << endl;
            goto repetir;
        }

        else if(tecla == 'x'){

            dinero = 0;
            cout << "\nPierdes todo! \nAhora tienes " << dinero << "$" << endl;
            return 0;
        }
     }

     if(dealerSuma == 21) {

        dinero = 0;
        cout << "\nPierdes todo! \nAhora tienes " << dinero << "$" << endl;
        _cputs("El dealer tiene 21 puntos, el dealer gana!\nPresiona E para jugar otra vez o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

        cout << "Ahora tienes " << dinero << "$\n" << endl;
            goto repetir;
        }

        else if(tecla == 'x'){

            cout << "Tienes "  << dinero << "$" << endl;
            return 0;
        }
     }

     if(dealerSuma > 21){

        suma = 0;
        dinero = 0;
        _cputs("Ganador!, el dealer tiene mas de 21 puntos\n\nPresiona E para jugar otra vez o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

        cout << "Ahora tienes " << dinero << "$\n" << endl;
            goto repetir;
        }

        else if(tecla == 'x'){

            dinero = 0;
            cout << "\nPierdes todo! \nAhora tienes " << dinero << "$" << endl;
            return 0;
        }
     }

    //Cero para usar letras
    if(numero == 0){

      cout << "Tu: " << letra[random] << simbolo[random];

       suma = suma + 10;

       cout << " -" << suma << " puntos";
    }

    //1 para tirar otra vez
    if (numero == 1) {

       goto blackjack;
     }

    if (dealerNumero == 1) {

       goto blackjack;
     }

     //numeros normales
     if(1 < numero && numero <= 10){

     cout << "Tu: "<<numero << simbolo[random];
     cout << " - " << suma << " puntos";
     }

     if(1 < dealerNumero && dealerNumero <= 10){

     cout << "\nDealer: "<< dealerNumero << simbolo[random];
     cout << " - " << dealerSuma << " puntos";
     }

     if(dealerNumero == 0){

      cout << "\nDealer: " << letra[dealerRandom] << simbolo[dealerRandom];

       dealerSuma = dealerSuma + 10;

       cout << " - " << dealerSuma << " puntos" << endl;
     }

       _cputs("\nPresiona E para jugar otra vez o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

            dinero = dinero + (dinero * 0.5);
            goto blackjack;
        }

        if(tecla == 'x'){

            cout << "Ahora tienes " << dinero << "$" << endl;
        }
    }
