// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo alphabet.cc: clase alfabeto
// Contiene la definición de los metodos de la clase Alphabet, así como sus
// constructores
// Referencias:
// Enlaces de interés:

#include "alphabet.h"

//Constructores
Alphabet::Alphabet() : symbols_() {}

Alphabet::Alphabet(std::vector<Symbol> symbols) {
  for(int i = 0; i < symbols.size(); ++i) {
    symbols_.insert(symbols[i]);
  }
};

//Getter del alfabeto completo
std::set<Symbol> Alphabet::Get_Symbols() const {
  return symbols_;
}

//Setter del alfabeto completo
void Alphabet::Set_Symbols(const std::set<Symbol> new_symbols) {
  symbols_ = new_symbols;
}

//Método que insrta un simbolo al alfabeto
void Alphabet::Insert(const Symbol new_symbol) {
   symbols_.insert(new_symbol);
}

//Método que devuelve el nº de símbolos del alfabeto
int Alphabet::Get_Size() const{
  return symbols_.size();
}

//Sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << "{";
  bool flag = false;
  for (auto& i : alphabet.symbols_){
    if (flag) {
      out << ", ";
    }
    out << i;
    flag = true;
  }
  out << "}";
  return out;
}

//Sobrecarga de entrada
std::istream& operator>>(std::istream& in, Alphabet& alphabet) {
  int number;
  std::cout << "Nº Símbolos: ";
  in >> number;
  for (int i = 0; i < number; ++i){
    std::string hey;
    in >> hey;
    Symbol symbol(hey);
    alphabet.symbols_.insert(symbol);
  }
  return in;
}