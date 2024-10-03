#include <iostream>
using namespace std;

class Estufa{
    private:
        Atuador atuadores;
        Sensor sensores;
    public:
        Estufa(Atuador atuadores,Sensor sensores):
        Atuador{atuadores},Sensor{sensores}{}

        void atualizaSensores(){}
        void atualizaAtuadores(){}
};
