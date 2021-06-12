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
    int suma = 0;
    int tecla;
    int dinero;
    string letra[4] {"A", "J", "Q", "K"};
    string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};

    cout << "Escribe la cantidad de dinero que vas a apostar"  << endl;
    cin >> dinero;
    cout << "\n";

    blackjack:

    srand(time(0));
    int numero = rand() % 11;
    int random = rand() % 4;
    suma = suma + numero;

    //definiendo resultados
    if(suma == 21) {

        _cputs("Ganaste!! \n\nzPresiona E para volver a jugar o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

            goto blackjack;
        }

        else if(tecla == 'x'){

            cout << "Ahora tienes "  << dinero << "$" << endl;
            return 0;
        }
     }

     if(suma > 21){

        suma = 0;
        _cputs("Te pasaste de 21, perdiste!\n\nPresiona E para volver a jugar o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

            goto blackjack;
        }

        else if(tecla == 'x'){

            dinero = 0;
            cout << "\nPerdiste todo! \nAhora tienes " << dinero << "$" << endl;
            return 0;
        }
     }

    //si sale cero se aprovecha para usar las letras
    if(numero == 0){

      cout << letra[random];
      cout << simbolo[random];

       suma = suma + 10;

       cout << "\nTienes " << suma << " puntos" << endl;
       _cputs("\nPresiona E para seguir o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

            goto blackjack;
        }

        if(tecla == 'x'){

            cout << "Ahora tienes " << dinero << "$" << endl;
        }
    }

    //si sale uno vuelve a tirar de nuevo
    else if (numero == 1) {

       goto blackjack;
     }

     //si sale normal
     else{

     cout << numero << simbolo[random] << endl;
     cout << "Tienes " << suma << " puntos" << endl;
     _cputs("\nPresiona E para seguir o X para salir\n\n");

        tecla = getch();

        if(tecla == 'e'){

            dinero = dinero + (dinero * 0.5);
            goto blackjack;
        }

        if(tecla == 'x'){

            cout << "Ahora tienes " << dinero << "$" << endl;
        }
    }
}
