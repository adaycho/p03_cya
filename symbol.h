// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo symbol.h: clase símbolo
// Contiene la declaración de los metodos de la clase Symbol y sus atributos
// Referencias:
// Enlaces de interés:

#ifndef SYMBOL_H
#define SYMBOL_H


#include <iostream>
#include <string>

// Clase que permite almacenar los símbolos
class Symbol{
  private:
    std::string symbol_;

  public:
    // Constructores y destructor
    Symbol(void): symbol_() {};
    Symbol(std::string symbol) : symbol_(symbol) {};

    // Getter-Setter
    std::string Get_Symbol() const;
    void Set_Symbol(const std::string new_symbol);

    //Métodos
    int Size() const;

    //Sobrecarga
    friend bool operator<(const Symbol& string1, const Symbol& string2);
    friend bool operator>(const Symbol& string1, const Symbol& string2);
    friend bool operator==(const Symbol& string1, const Symbol& string2);
    friend bool operator!=(const Symbol& string1, const Symbol& string2);

    friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
    friend std::istream& operator>>(std::istream& in, const Symbol& symbol);
};

#endif