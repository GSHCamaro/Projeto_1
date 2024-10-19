#ifndef SENSOR_CPP  // Verifica se SENSOR_CPP não foi definido ainda
#define SENSOR_CPP  // Define SALA_CPP
// Elas garantem que o conteúdo entre #ifndef e #endif seja incluído apenas uma vez durante a compilação

#include <iostream>         // Inclusão da biblioteca iostream
#include <cstdlib>          // Inclusão da biblioteca cstdlib
#include "Componente.cpp"   // Inclusão do arquivo "Componente.cpp" que contem a classe Componente com todas as suas carcteristicas

// Definição da classe Sensor que herda de Componente
class Sensor : public Componente{
public:
    // Construtor que chama o construtor da classe base Componente
    Sensor(string nome) : Componente(nome) {}

    // Método virtual puro que será implementado pelas classes derivadas para atualizar o valor de cada sensor
    virtual void atualizar() = 0;
};

// Definição da classe Temperatura, que herda de Sensor
class Temperatura : public Sensor
{
public:
    // Construtor que define o nome do sensor como "Temperatura" e chama o construtor da classe base Sensor
    Temperatura() : Sensor("Temperatura") {}

    // Implementação do método atualizar que define um valor aleatório para a temperatura
    void atualizar() {
        valor = 22 + rand() % 9; // Gera temperatura entre 22 e 30
    }

    // Método para obter a temperatura em graus Celsius
    float getTemperaturaEmC() const {
        return valor;
    }

    // Método para obter a temperatura em Fahrenheit
    float getTemperaturaEmF() const {
        return (valor * 1.8) + 32; // Converte Celsius para Fahrenheit
    }

    // Método para obter a temperatura em Kelvin
    float getTemperaturaEmK() const {
        return valor + 273; // Converte Celsius para Kelvin
    }
};

// Definição da classe Luminosidade, que herda de Sensor
class Luminosidade : public Sensor {
private:
    int LimiarClaridade;  // Atributo que armazena o limiar de claridade

public:
    // Construtor que inicializa o nome e o limiar de claridade e chama o construtor da classe base Sensor
    Luminosidade(int limiar) : Sensor("Luminosidade"), LimiarClaridade(limiar) {}

    // Implementação do método atualizar que define um valor aleatório para a luminosidade
    void atualizar() {
        valor = 100 + rand() % 201; // Gera luminosidade entre 100 e 300
    }

    // Método para obter o valor do limiar de claridade
    int getLimiarClaridade() const {
        return LimiarClaridade;
    }
};

// Definição da classe Umidade, que herda de Sensor
class Umidade : public Sensor {
public:
    // Construtor que define o nome do sensor como "Umidade" e chama o construtor da classe base Sensor
    Umidade() : Sensor("Umidade") {}

    // Implementação do método atualizar que define um valor aleatório para a umidade
    void atualizar() {
        valor = 40 + rand() % 41; // Gera umidade entre 40 e 80
    }
};

#endif // Finaliza a verificação