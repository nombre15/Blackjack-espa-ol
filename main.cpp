#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

void jugadorGana(int& dinero, int& suma);
void jugadorPierde(int& dinero, int& suma);

int main(){

    repetir:

        int suma = 0;
        int dealerSuma = 0;
        int dinero = 0;
        bool check;
            
        int tecla;
        string letra[4] {"A", "J", "Q", "K"};
        string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};

        cout << "Escribe la cantidad de dinero que usaras"  << endl;
        cin >> dinero;

        while(cin.fail()) {

            cout << "Ingrese un numero adecuado" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> dinero;
        }

        cout << "\n"; 

        blackjack: 

            srand(time(0));
            int numero = rand() % 11;
            int dealerNumero = rand() % 11;
            int randomJ = rand() % 4;
            int randomD = rand() % 4;
            suma = suma + numero;
            dealerSuma = dealerSuma + dealerNumero;

            //Cero y 1 para usar letras
            if(numero == 0 || numero == 1){

                suma = suma + 10;
                cout << "Tu: " << letra[randomJ] << simbolo[randomJ] << " -" << suma << " puntos";
            }

            //Numeros normales
            if(1 < numero && numero <= 10){

                cout << "Tu: "<<numero << simbolo[randomJ] << " - " << suma << " puntos";
            }

            if(1 < dealerNumero && dealerNumero <= 10){

                cout << "\nDealer: "<< dealerNumero << simbolo[randomD] << " - " << dealerSuma << " puntos";
            }

            if(dealerNumero == 0 || dealerNumero == 1){

                dealerSuma = dealerSuma + 10;
                cout << "\nDealer: " << letra[randomD] << simbolo[randomD] << " - " << dealerSuma << " puntos";
            }
            
                            ////////RESULTADOS////////
            //21 puntos JUGADOR
            if(suma == 21) {

                cout << "\n\n21 puntos,  Ganador!!";
                jugadorGana(dinero,suma);
                _cputs("\n\nPresiona E para jugar otra vez o X para salir\n\n");
                tecla = getch();


                do{

                    if(tecla == 'e'){
                        goto repetir; 
                    }

                    else if(tecla == 'x'){

                        cout << "\n\nTe vas con " << dinero << "$";
                        return 0;
                    }

                    else{

                        _cputs("\nPorfavor presiona una tecla valida\n\n");
                        tecla = getch();
                    }                   
                }while(tecla != 'e' || tecla != 'x');
            }

            //Mas de 21 puntos JUGADOR
            else if(suma > 21){

                _cputs("\n\nTienes mas de 21 puntos, perdedor!");
                jugadorPierde(dinero,suma);
                _cputs("\n\nPresiona E para jugar otra vez o X para salir\n\n");
                tecla = getch();

                do{

                    if(tecla == 'e'){
                        goto repetir; 
                    }

                    else if(tecla == 'x'){

                        cout << "\n\nQuedaste sin dinero :(";
                        return 0;
                    }

                    else{

                        _cputs("Porfavor presiona una tecla valida\n\n");
                        tecla = getch();
                    }                   
                }while(tecla != 'e' || tecla != 'x');
            }

            //21 puntos DEALER
            else if(dealerSuma == 21) {

                _cputs("\n\nEl dealer tiene 21 puntos, el dealer gana!");
                jugadorPierde(dinero, suma);
                _cputs("\n\nPresiona E para jugar otra vez o X para salir\n\n");
                tecla = getch();

                do{

                    if(tecla == 'e'){
                        goto repetir; 
                    }

                    else if(tecla == 'x'){

                        cout << "\n\nQuedaste sin dinero :(";
                        return 0;
                    }

                    else{

                        _cputs("\nPorfavor presiona una tecla valida\n\n");
                        tecla = getch();
                    }                   
                }while(tecla != 'e' || tecla != 'x');
            }

            //Mas de 21 puntos DEALER
            else if(dealerSuma > 21){

                _cputs("\n\nGanador!, el dealer tiene mas de 21 puntos");
                jugadorGana(dinero,suma);
                _cputs("\n\nPresiona E para jugar otra vez o X para salir\n\n");
                tecla = getch();

                do{

                    if(tecla == 'e'){                       
                        goto repetir; 
                    }

                    else if(tecla == 'x'){

                        cout << "\n\nTe vas con " << dinero << "$";
                        return 0;
                    }

                    else{

                        _cputs("\nPorfavor presiona una tecla valida\n\n");
                        tecla = getch();
                    }                   
                }while(tecla != 'e' || tecla != 'x');
            }         

            else{

                _cputs("\n\nPresiona E para jugar otra vez o X para salir\n\n");
                tecla = getch();

                do{

                    if(tecla == 'e'){
                        goto blackjack;
                    }     

                    else if(tecla == 'x'){

                        if(dealerSuma > suma){

                            cout << "\nEl dealer tiene mas puntos, pierdes!" << endl;
                            return 0;
                        }

                        else if(dealerSuma == suma){

                            cout << "\nEmpate! no puedes abandonar" << endl;
                            goto blackjack;
                        }

                        else{
                            
                            cout << "\nTe vas con " << dinero << "$";
                            return 0;
                        }
                    }

                    else{

                        _cputs("Porfavor presiona una tecla valida\n\n");
                        tecla = getch();
                    }           
                }while(tecla != 'e' || tecla != 'x');
            }
}   

void jugadorGana(int& dinero, int& suma) {

    dinero = dinero + (dinero * 0.5);
    cout << "\nAhora tienes " << dinero << "$\n" << endl;
    suma = 0;
}

void jugadorPierde(int& dinero, int& suma) {

    cout << "\nPierdes todo!" << endl;
    dinero = 0;
    suma = 0;
}
