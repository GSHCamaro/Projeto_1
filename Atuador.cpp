#ifndef ATUADOR_CPP
#define ATUADOR_CPP

#include <iostream>     // Inclusão da biblioteca para input/output
#include "Componente.cpp"  // Inclusão do arquivo Componente.cpp, que contem a classe Componente
#include "Sensor.cpp"      // Inclusão do arquivo Sensor.cpp, que contem a classe Sensor

// Classe base Atuador, que herda da classe Componente
class Atuador : public Componente {
public:
    // Construtor da classe Atuador que recebe o nome e passa para o construtor da classe base (Componente)
    Atuador(string nome) : Componente(nome) {}
    
    // Função virtual pura, obrigando as classes filhas a implementarem essa função
    virtual bool setValor(int valor) = 0;

    // Função para retornar o valor atual do atuador
    int getValor() const { return valor; }
};

// Classe Ventilador que herda de Atuador
class Ventilador : public Atuador {
private:
    int velocidade;   // Variável para armazenar a velocidade do ventilador

public:
    // Construtor do ventilador inicializando o nome do atuador e a velocidade com 0
    Ventilador() : Atuador("Ventilador"), velocidade(0) {}

    // Função para definir a velocidade com base na temperatura
    bool setVelocidade(int temperatura) { // Temperatura ideal é 22°C
        // Ajusta a velocidade com base na temperatura
        if (temperatura == 30) {
            velocidade = 1000;  // Temperatura muito alta, velocidade máxima
        } else if (temperatura == 29) {
            velocidade = 800;   // Temperatura um pouco mais baixa
        } else if (temperatura == 28 || temperatura == 27) {
            velocidade = 400;   // Temperatura média
        } else if (temperatura == 26 || temperatura == 25) {
            velocidade = 200;   // Temperatura um pouco mais baixa
        } else {
            velocidade = 0;     // Temperatura dentro da faixa ideal ou menor que 25°C
        }
        return true;
    }

    // Função implementada da classe base Atuador que define o valor do ventilador
    bool setValor(int temperatura) {
        setVelocidade(temperatura);  // Define a velocidade com base na temperatura
        valor = velocidade;          // Atribui a velocidade ao valor do atuador
        return true;
    }
};

// Classe Umidificador que herda de Atuador
class Umidificador : public Atuador {
private:
    int umidificacao;   // Variável para armazenar o valor de umidificação

public:
    // Construtor do umidificador inicializando o nome do atuador
    Umidificador() : Atuador("Umidificador") {}

    // Função para definir a configuração de umidificação com base na umidade
    bool setConfiguracao(int umidade) { // Umidade ideal é 60%
        if (umidade <= 80 && umidade >= 60) {
            umidificacao = 0;   // Umidade ideal ou mais alta
        } else if (umidade < 60 && umidade >= 55) {
            umidificacao = 5;   // Umidade um pouco abaixo da ideal
        } else if (umidade < 55 && umidade >= 50) {
            umidificacao = 10;  // Umidade mais baixa
        } else if (umidade < 50 && umidade >= 45) {
            umidificacao = 20;  // Umidade ainda mais baixa
        } else {
            umidificacao = 30;  // Umidade muito baixa
        }
        return true;
    }

    // Função implementada da classe base Atuador que define o valor do umidificador
    bool setValor(int umidade) {
        setConfiguracao(umidade);  // Define a configuração com base na umidade
        valor = umidificacao;      // Atribui a umidificação ao valor do atuador
        return true;
    }
};

// Classe Desumidificador que herda de Atuador
class Desumidificador : public Atuador {
private:
    int desumidificacao;   // Variável para armazenar o valor de desumidificação

public:
    // Construtor do desumidificador inicializando o nome do atuador
    Desumidificador() : Atuador("Desumidificador") {}

    // Função para definir a configuração de desumidificação com base na umidade
    bool setConfiguracao(int umidade) {  // Umidade ideal é 60%
        if (umidade <= 80 && umidade >= 75) {
            desumidificacao = 30;  // Umidade muito alta, desumidificação máxima
        } else if (umidade < 75 && umidade >= 70) {
            desumidificacao = 20;  // Umidade alta
        } else if (umidade < 70 && umidade >= 65) {
            desumidificacao = 10;  // Umidade moderada
        } else if (umidade < 65 && umidade > 60) {
            desumidificacao = 5;   // Umidade um pouco mais baixa
        } else {
            desumidificacao = 0;   // Umidade dentro da faixa ideal ou muito baixa
        }
        return true;
    }

    // Função implementada da classe base Atuador que define o valor do desumidificador
    bool setValor(int umidade) {
        setConfiguracao(umidade);  // Define a configuração com base na umidade
        valor = desumidificacao;   // Atribui a desumidificação ao valor do atuador
        return true;
    }
};

// Classe Lampada que herda de Atuador
class Lampada : public Atuador {
    private:
    Luminosidade* sensorLuminosidade;
public:
    // Construtor da lâmpada que recebe um limiar de claridade
    Lampada(Luminosidade* sensor) : Atuador("Lampada"), sensorLuminosidade(sensor) {}

    // Função implementada da classe base Atuador que define o valor da lâmpada
    bool setValor(int brilho) {
        // A lâmpada será desligada se o brilho for maior que o limiar
        if (brilho >= sensorLuminosidade->getLimiarClaridade()) {
            valor = 0;    // Lâmpada desligada
        } else {
            valor = 1000;  // Lâmpada ligada em brilho máximo
        }
        return true;
    }

};

#endif
