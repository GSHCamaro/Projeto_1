#include <iostream>
#include <ctime>
#include "Sala.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    Temperatura temp1, temp2, temp3;
    Luminosidade lum1(50), lum2(70), lum3(30);
    Umidade umid1, umid2, umid3;
    
    Ventilador vent1, vent2, vent3;
    Umidificador umidif1, umidif2, umidif3;
    Desumidificador desumid1, desumid2, desumid3;
    Lampada lamp1, lamp2, lamp3;

    Sala sala1(&temp1, &lum1, &umid1, &vent1, &umidif1, &desumid1, &lamp1);
    Sala sala2(&temp2, &lum2, &umid2, &vent2, &umidif2, &desumid2, &lamp2);
    Sala sala3(&temp3, &lum3, &umid3, &vent3, &umidif3, &desumid3, &lamp3);


    for (int i = 0; i < 1440; i++) {
        cout << "Atualização " << i + 1 << ":" << endl;

        sala1.atualizarSensores();
        sala1.atualizarAtuadores();
        sala1.exibirEstadoHortalicas();

        sala2.atualizarSensores();
        sala2.atualizarAtuadores();
        sala2.exibirEstadoFlores();

        sala3.atualizarSensores();
        sala3.atualizarAtuadores();
        sala3.exibirEstadoLegumes();
    }

    return 0;
}
