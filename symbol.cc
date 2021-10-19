// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo symbol.cc: clase símbolo
// Contiene la definición de los metodos de la clase Symbol
// Referencias:
// Enlaces de interés:


#include "symbol.h"

//Getter de un único símbolo
std::string Symbol::Get_Symbol() const {
  return symbol_;
}

//Setter de un único símbolo
void Symbol::Set_Symbol(const std::string new_symbol) {
  symbol_ = new_symbol;
}

// Metodo para devolver el tamaño
int Symbol::Size() const{
  return symbol_.size();
}

//Sobrecarga de operadores
//Menor que
bool operator<(const Symbol& string1, const Symbol& string2) {
  return string1.Get_Symbol() < string2.Get_Symbol();
}

//Mayor que
bool operator>(const Symbol& string1, const Symbol& string2) {
  return string1.Get_Symbol() > string2.Get_Symbol();
}

//Igualdad
bool operator==(const Symbol& string1, const Symbol& string2) {
  return string1.Get_Symbol() == string2.Get_Symbol();
}

//Desigualdad
bool operator!=(const Symbol& string1, const Symbol& string2) {
  return string1.Get_Symbol() != string2.Get_Symbol();
}

//Salida
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.Get_Symbol();
  return out;
}

//Entrada
std::istream& operator>>(std::istream& in, const Symbol& symbol) {
  in >> symbol.symbol_;
  return in;
}