// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo alphabet.h: clase alfabeto
// Contiene la declaración de los metodos de la clase Alphabet y sus atributos
// Referencias:
// Enlaces de interés:

#ifndef ALPHABET_H
#define ALPHABET_H

#include "symbol.h"
#include <cassert>
#include <set>
#include <vector>

// Clase que permite almacenar los símbolos usados en una cadena mediante un
// set/conjunto
class Alphabet{
  private:
    std::set<Symbol> symbols_;

  public:
    // Constructores y destructor
    Alphabet(void);
    Alphabet(std::vector<Symbol> symbols);

    // Getters-Setters
    std::set<Symbol> Get_Symbols() const;
    void Set_Symbols(const std::set<Symbol> new_symbols);
    void Set_Symbol(const Symbol new_symbol);

    // Funciones
    void Insert(const Symbol new_symbol);
    int Get_Size(void) const;

    // Sobrecarga
    friend std::ostream& operator<<(std::ostream& out,
    const Alphabet& alphabet);
    friend std::istream& operator>>(std::istream& in, Alphabet& alphabet);
};

#endif