#ifndef COMPONENTE_CPP
#define COMPONENTE_CPP

#include <iostream>
#include <string>

using namespace std;

// Classe base para representar um componente
class Componente {
protected:
    bool ligado;       // Indica se o componente está ligado ou não
    bool conectado;    // Indica se o componente está conectado ou não
    int valor;         // Armazena o valor do componente (pode ser potência, luminosidade, etc.)
    string nome;       // Nome do componente, por exemplo, "Lampada", "Ventilador", etc.

public:
    // Construtor que inicializa o nome do componente e define estados iniciais (desligado e desconectado)
    Componente(string nome) : ligado(false), conectado(false), valor(0), nome(nome) {}

    // Método para ligar o componente (muda o estado 'ligado' para true)
    void ligar() { 
        ligado = true; 
    }

    // Método para desligar o componente (muda o estado 'ligado' para false)
    void desligar() { 
        ligado = false; 
    }

    // Método para conectar o componente (muda o estado 'conectado' para true e retorna esse estado)
    bool conectar() { 
        conectado = true; 
        return conectado; 
    }

    // Método para desconectar o componente (muda o estado 'conectado' para false)
    void desconectar() { 
        conectado = false; 
    }

    // Método que retorna o valor do componente (pode ser o nível de luminosidade, velocidade, etc.)
    int getValor() const { 
        return valor; 
    }

    // Método que retorna se o componente está ligado (true) ou desligado (false)
    bool isLigado() const { 
        return ligado; 
    }

    // Método que retorna o nome do componente (por exemplo, "Lampada", "Ventilador")
    string getNome() const { 
        return nome; 
    }
};

#endif // Fim do bloco de proteção contra múltiplas inclusões
