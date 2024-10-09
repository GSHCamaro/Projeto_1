#ifndef SALA_CPP
#define SALA_CPP

#include <iostream>
#include "Sensor.cpp"
#include "Atuador.cpp"

class Sala {
private:
    Sensor* sensores[3];
    Atuador* atuadores[4];

public:
    Sala(Sensor* s1, Sensor* s2, Sensor* s3, Atuador* a1, Atuador* a2, Atuador* a3, Atuador* a4) {
        sensores[0] = s1;
        sensores[1] = s2;
        sensores[2] = s3;
        atuadores[0] = a1;
        atuadores[1] = a2;
        atuadores[2] = a3;
        atuadores[3] = a4;
    }

    void atualizarSensores() {
        for (int i = 0; i < 3; i++) {
            sensores[i]->atualizar();
        }
    }

    void atualizarAtuadores() {
        for (int i = 0; i < 4; i++) {
            atuadores[i]->setValor(rand() % 100);
        }
    }

    void exibirEstadoHortalicas() const {
        cout << "Estado da Estufa de Hortaliças" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  " << sensores[i]->getNome() << ": " << sensores[i]->getValor() << endl;
        }
        for (int i = 0; i < 4; i++) {
            cout << "  " << atuadores[i]->getNome() << ": " << atuadores[i]->getValor() << endl;
        }
        cout << endl;
    }

    void exibirEstadoFlores() const {
        cout << "Estado da Estufa de Flores" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  " << sensores[i]->getNome() << ": " << sensores[i]->getValor() << endl;
        }
        for (int i = 0; i < 4; i++) {
            cout << "  " << atuadores[i]->getNome() << ": " << atuadores[i]->getValor() << endl;
        }
        cout << endl;
    }

    void exibirEstadoLegumes() const {
        cout << "Estado da Estufa de Legumes" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  " << sensores[i]->getNome() << ": " << sensores[i]->getValor() << endl;
        }
        for (int i = 0; i < 4; i++) {
            cout << "  " << atuadores[i]->getNome() << ": " << atuadores[i]->getValor() << endl;
        }
        cout << endl;
    }
};

#endif // SALA_CPP
