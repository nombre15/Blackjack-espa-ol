class players
{
    public:
        players();
        int jugar();
        void jugadorGana(int& dinero);
        void jugadorPierde(int& dinero);
        int ingresarTecla(char tecla, int dinero);

    private:
        int jugadorSuma = 0;
        int dealerSuma = 0;
        int dinero = 0;
        bool finalizado = false;
};
