#ifndef SALA_CPP
#define SALA_CPP

#include <iostream>        // Biblioteca para entrada e saída de dados
#include "Sensor.cpp"      // Inclusão do arquivo Sensor
#include "Atuador.cpp"     // Inclusão do arquivo Atuador

// Definição da classe Sala
class Sala {
private:
    Sensor* sensores[3];  // Array para armazenar três sensores
    Atuador* atuadores[4];  // Array para armazenar quatro atuadores
    Temperatura* temp;    // Ponteiro para o sensor de temperatura (não usado diretamente neste código)

public:
    // Construtor que inicializa os sensores e atuadores
    Sala(Sensor* s1, Sensor* s2, Sensor* s3, Atuador* a1, Atuador* a2, Atuador* a3, Atuador* a4) {
        sensores[0] = s1;  // Primeiro sensor
        sensores[2] = s2;  // Segundo sensor
        sensores[1] = s3;  // Terceiro sensor (note que o sensor 2 e 3 estão invertidos)
        atuadores[0] = a1;  // Primeiro atuador
        atuadores[1] = a2;  // Segundo atuador
        atuadores[2] = a3;  // Terceiro atuador
        atuadores[3] = a4;  // Quarto atuador
    }

    // Função para atualizar os sensores
    void atualizarSensores() {
        for (int i = 0; i < 3; i++) {  // Itera sobre os 3 sensores
            sensores[i]->atualizar();  // Chama o método atualizar de cada sensor
        }
    }

    // Função para atualizar os atuadores com base nos valores dos sensores
    void atualizarAtuadores() {
        atuadores[0]->setValor(sensores[0]->getValor());  // Define valor do primeiro atuador com o valor do primeiro sensor
        atuadores[1]->setValor(sensores[1]->getValor());  // Define valor do segundo atuador com o valor do segundo sensor
        atuadores[2]->setValor(sensores[1]->getValor());  // Define valor do terceiro atuador com o valor do segundo sensor (mesmo do segundo atuador)
        atuadores[3]->setValor(sensores[2]->getValor());  // Define valor do quarto atuador com o valor do terceiro sensor
    }

    // Função para exibir o estado dos sensores e atuadores na tela
    void exibirEstado(string nome) const {
        // Verifica se o nome é "Legumes" para alterar a frase de exibição
        if(nome == "Legumes"){
            cout << "Estado da Estufa dos " << nome << ":" << endl;
        } else {
            cout << "Estado da Estufa das " << nome << ":" << endl;
        }

        // Verifica se todos os sensores estão conectados
        if(sensores[0]->conectar() && sensores[1]->conectar() && sensores[2]->conectar()){
            cout << "Sensores Conectados e Seus Valores:" << endl;
            // Itera sobre os sensores e exibe os valores
            for (int i = 0; i < 3; i++) {
                // Verifica o nome do sensor e exibe o valor correspondente
                if(sensores[i]->getNome() == "Temperatura"){
                    cout << "  " << sensores[i]->getNome() << "(Ideal entre 24°C a 22°C): " 
                         << sensores[i]->getValor() << "°C / " 
                         << (sensores[i]->getValor() * 1.8) + 32 << "F / " 
                         << sensores[i]->getValor() + 273 << "K " << endl;
                } else if(sensores[i]->getNome() == "Umidade"){
                    cout << "  " << sensores[i]->getNome() << "(Ideal 60%): " 
                         << sensores[i]->getValor() << "%" << endl;
                } else {
                    Luminosidade* lum = static_cast<Luminosidade*>(sensores[i]);  // Converte para Luminosidade
                    cout << "  " << sensores[i]->getNome() << "(Ideal maior que " 
                         << lum->getLimiarClaridade() << " Lux): " 
                         << sensores[i]->getValor() << " Lux" << endl;
                }
            }
        } else {
            // Caso não consiga conectar algum sensor, exibe mensagem de erro
            cout << "Erro ao conectar os sensores!" << endl;
        }

        // Exibe o estado dos atuadores
        cout << "Atuadores Ligados e Seus Valores:" << endl;
        for (int i = 0; i < 4; i++) {
            // Verifica se o atuador tem um valor diferente de zero para ligar
            if(atuadores[i]->getValor() != 0){
                atuadores[i]->ligar();
            } else {
                atuadores[i]->desligar();
            }

            // Verifica se o atuador está ligado e exibe suas informações
            if(atuadores[i]->isLigado()){
                if(atuadores[i]->getNome() == "Ventilador"){
                    cout << "  " << atuadores[i]->getNome() << ": (Ligado) " 
                         << atuadores[i]->getValor() << " rpm" << endl;
                } else if(atuadores[i]->getNome() == "Lampada"){
                    cout << "  " << atuadores[i]->getNome() << ": (Ligado) " 
                         << atuadores[i]->getValor() << " Lumens" << endl;
                } else {
                    cout << "  " << atuadores[i]->getNome() << ": (Ligado) " 
                         << atuadores[i]->getValor() << " W" << endl;
                }
            } else {
                // Exibe a informação do atuador desligado
                cout << "  " << atuadores[i]->getNome() << ": (Desligado) " 
                     << atuadores[i]->getValor() << endl;
            }
        }
    }
};

#endif  // Finaliza a definição do arquivo SALA_CPP
