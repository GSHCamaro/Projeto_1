#ifndef COMPONENTE_CPP
#define COMPONENTE_CPP

#include <iostream>
#include <string>

using namespace std;

class Componente {
protected:
    bool ligado;
    bool conectado;
    int valor;
    string nome;

public:
    Componente(string nome) : ligado(false), conectado(false), valor(0), nome(nome) {}
    void ligar() { 
        ligado = true; 
        }
    void desligar() { 
        ligado = false; 
        }
    bool conectar() { 
        conectado = true; return conectado; 
        }
    void desconectar() { 
        conectado = false; 
        }
    int getValor() const { 
        return valor; 
        }
    bool isLigado() const { 
        return ligado; 
        }
    string getNome() const { 
        return nome; 
        }
};

#endif 
