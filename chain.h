// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo chain.h: clase cadena
// Contiene la declaración de los metodos de la clase Chain y sus atributos
// Referencias:
// Enlaces de interés:

#ifndef STRING_H
#define STRING_H

#include "alphabet.h"

  const char kSpace = ' ';

// Clase que almacena una secuencia de símbolos que pretenecen a un alfabeto
// y al propio alfabeto
class Chain{
  private:
    std::vector<Symbol> string_pos_;
    Alphabet alphabet_;

  public:
    // Constructores y destructor
    Chain(void);
    Chain(std::string line);
    Chain(std::string string, Alphabet alphabet);

    // Getters
    Alphabet Get_Alphabet(void) const;
    std::vector<Symbol> Get_Chain(void) const;

    // Funciones
    int Get_Size(void) const;
    void Invert();
    void Push_back(Symbol symbol);
    void Concatenate(std::string string);
  
    // Sobrecarga
    friend Chain operator^(const Chain& chain, const int& number);
    friend Chain operator*(const Chain& chain1, const Chain& chain2);

    friend bool operator==(const Chain& chain1, const Chain& chain2);
    friend bool operator<(const Chain& chain1, const Chain& chain2);
    friend bool operator>(const Chain& chain1, const Chain& chain2);
    friend bool operator!=(const Chain& chain1, const Chain& chain2);
    
    friend std::ostream& operator<<(std::ostream& out, const Chain& string);
    friend std::istream& operator>>(std::istream& in, Chain& stringt);
};   

#endif