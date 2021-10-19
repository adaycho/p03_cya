// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo language.cc: clase lenguaje
// Contiene la definición de los metodos de la clase Language
// Referencias:
// Enlaces de interés:

#include "language.h"

Alphabet Language::Get_Alphabet() const {
  return alphabet_;
}

// Método que devuelve el prefijo de chain almacenados en language
void Language::Add_Prefixes(Chain chain) {
  Alphabet alphabet = chain.Get_Alphabet();
  alphabet_ = alphabet;
  for (int i = 0; i <= chain.Get_Size(); ++i){
    if ( i == 0) {
      language_.push_back(kEmptyChain);
    }

    else {
      std::string substring;
      for (int j = 0; j < i; ++j) {
        substring += chain.Get_Chain()[j].Get_Symbol();
      }

      Chain subchain(substring, alphabet);
      language_.push_back(subchain);
    }
  }
}

// Método que devuelve el sufijos de chain
void Language::Add_Suffixes(Chain chain) {
  Alphabet alphabet = chain.Get_Alphabet();
  alphabet_ = alphabet;
  for (int i = 0; i <= chain.Get_Size(); ++i){
    if ( i == 0) {
      language_.push_back(kEmptyChain);
    }

    else {
      std::string substring;
      for (int j = 0; j < i; ++j) {
        substring += chain.Get_Chain()[chain.Get_Size() - i + j].Get_Symbol();
      }

      Chain subchain(substring, alphabet);
      language_.push_back(subchain);
    }
  }
}

// Método que devuelve todas las subcadenas de la cadena en un vector
void Language::Substrings(Chain chain) {
  alphabet_ = chain.Get_Alphabet();
  for (int i = 0; i <= chain.Get_Size(); ++i) {
    if ( i == 0) {
      language_.push_back(kEmptyChain);
    }

    else {
      for (int j = 0; j < chain.Get_Size() + 1 - i; ++j) {
        Chain new_chain;
        for (int k = 0; k < i; ++k) {
          new_chain.Push_back(chain.Get_Chain()[k + j]);
        }

        bool flag = true;
        for (int k = 0; k < language_.size(); ++k) {
          if (language_[k] == new_chain) {
            flag = false;
          }
        }

        if (flag == true) {
          language_.push_back(new_chain);
        }
      }
    }
  }
}
//Sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Language& language) {
  out << "{" << language.language_[0];
  for (int i = 1; i < language.language_.size(); ++i){
    out << ", " << language.language_[i];
  }
  out << "}";
  return out;
}
//Sobrecarga de entrada
std::istream& operator>>(std::istream& in, Language& language) {
  int number;
  std::cout << "Nº Cadenas: ";
  in >> number;
  for (int i = 0; i < number; ++i){
    std::string hey;
    in >> hey;
    Chain chain(hey);
    language.language_.push_back(chain);
    for (auto& symbol:chain.Get_Alphabet().Get_Symbols()) {
      bool flag = true;
      for (auto& symbol2:language.alphabet_.Get_Symbols()) {
        if (symbol == symbol2) {
          flag = false;
        }
      }
      if (flag == true) {
        language.alphabet_.Insert(symbol);
      }
    }
  }
  return in;
}