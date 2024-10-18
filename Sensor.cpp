#ifndef SENSOR_CPP
#define SENSOR_CPP

#include <iostream>      // Biblioteca para entrada e saída de dados
#include <cstdlib>       // Biblioteca para funções de geração de números aleatórios
#include "Componente.cpp" // Inclui a classe base Componente

// Definição da classe Sensor, que herda de Componente
class Sensor : public Componente
{
public:
    // Construtor que chama o construtor da classe base Componente
    Sensor(string nome) : Componente(nome) {}

    // Método virtual puro que será implementado pelas classes derivadas
    virtual void atualizar() = 0;
};

// Definição da classe Temperatura, que herda de Sensor
class Temperatura : public Sensor
{
public:
    // Construtor que define o nome do sensor como "Temperatura"
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
    // Construtor que inicializa o nome e o limiar de claridade
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
    // Construtor que define o nome do sensor como "Umidade"
    Umidade() : Sensor("Umidade") {}

    // Implementação do método atualizar que define um valor aleatório para a umidade
    void atualizar() {
        valor = 40 + rand() % 41; // Gera umidade entre 40 e 80
    }
};

#endif // SENSOR_CPP
