#include <iostream>
using namespace std;

class Componentes{
    private:
        bool ligado, conectado;
        int valor;
        string nome;
    public:
        void ligar(){}
        void desligar(){}
        bool conectar(){}
        void desconectar(){}
        
        int getValor(){
            return this->valor;
        }
};