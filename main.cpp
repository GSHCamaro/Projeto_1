#include <iostream>  // Inclusão da biblioteca iostream
#include <ctime>     // Inclusão da biblioteca ctime
#include "Sala.cpp"  // Inclusão do arquivo "Sala.cpp" que contem a classe Sala e seus componentes

using namespace std;  // Usa o namespace padrão para evitar uso explícito de "std::"

// Função principal do programa
int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios com base no horário atual

    // Instanciando sensores de temperatura, luminosidade e umidade
    Temperatura temp1, temp2, temp3;  // Três sensores de temperatura
    Luminosidade lum1(210), lum2(220), lum3(200);  // Três sensores de luminosidade com limiares diferentes
    Umidade umid1, umid2, umid3;  // Três sensores de umidade

    // Instanciando atuadores (ventiladores, umidificadores, desumidificadores, e lâmpadas)
    Ventilador vent1, vent2, vent3;  // Três ventiladores
    Umidificador umidif1, umidif2, umidif3;  // Três umidificadores
    Desumidificador desumid1, desumid2, desumid3;  // Três desumidificadores
    Lampada lamp1(&lum1), lamp2(&lum2), lamp3(&lum3);  // Três lâmpadas, cada uma associada a um sensor de luminosidade

    // Criação de três salas, cada uma com diferentes conjuntos de sensores e atuadores
    Sala sala1(&temp1, &lum1, &umid1, &vent1, &umidif1, &desumid1, &lamp1);  // Sala 1 com seus componentes
    Sala sala2(&temp2, &lum2, &umid2, &vent2, &umidif2, &desumid2, &lamp2);  // Sala 2 com seus componentes
    Sala sala3(&temp3, &lum3, &umid3, &vent3, &umidif3, &desumid3, &lamp3);  // Sala 3 com seus componentes

    // Loop para simular 1440 atualizações 
    for (int i = 0; i < 1440; i++) {
        cout << "Atualização " << i + 1 << ":" << endl;  // Exibe o número da atualização

        // Atualiza e exibe o estado da sala 1 (Flores)
        sala1.atualizarSensores();  // Atualiza os sensores da sala 1
        sala1.atualizarAtuadores();  // Atualiza os atuadores da sala 1
        sala1.exibirEstado("Flores");  // Exibe o estado da sala 1, ou seja, mostra os valores dos atuadores e sensores
        cout << endl;  // Pula uma linha

        // Atualiza e exibe o estado da sala 2 (Hortaliças)
        sala2.atualizarSensores();  // Atualiza os sensores da sala 2
        sala2.atualizarAtuadores();  // Atualiza os atuadores da sala 2
        sala2.exibirEstado("Hortalicas");  // Exibe o estado da sala 2, ou seja, mostra os valores dos atuadores e sensores
        cout << endl;  // Pula uma linha

        // Atualiza e exibe o estado da sala 3 (Legumes)
        sala3.atualizarSensores();  // Atualiza os sensores da sala 3
        sala3.atualizarAtuadores();  // Atualiza os atuadores da sala 3
        sala3.exibirEstado("Legumes");  // Exibe o estado da sala 3, ou seja, mostra os valores dos atuadores e sensores
        cout << "---------------------------------------------------------------------" << endl;  // Linha separadora entre as atualizações
    }

    return 0;  // Retorna 0, indicando que o programa terminou com sucesso
}
