// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo chain.cc: clase cadena
// Contiene la definición de los metodos de la clase Chain, así como sus
// constructores
// Referencias:
// Enlaces de interés:

#include "chain.h"
#include <fstream>

// Constructores
Chain::Chain() : string_pos_(), alphabet_() {}

Chain::Chain(std::string line) {
  int found;
  if (line.find_last_of(kSpace) == -1) {
    std::string string_copy;
    string_copy = line;
    for (int i = 0; i < string_copy.size(); ++i) {
      std::string symbol(1, string_copy[i]);
      bool flag = true;
      for (auto& alphabet_sym : alphabet_.Get_Symbols()) {
        if (alphabet_sym == symbol) {
          flag = false;
        }
      }

      if (flag == true) {
        Symbol symbol_in(symbol);
        alphabet_.Insert(symbol_in);
      }
    }
  }
  else {
    while (line.find_first_of(kSpace) != -1) {
      found = line.find_first_of(kSpace);
      std::string symbol = line.substr(0, found);
      line = line.substr(found +1);
      bool flag = true;
      for (auto& alphabet_sym : alphabet_.Get_Symbols()) {
        if (alphabet_sym == symbol) {
          flag = false;
        }
      }

      if (flag == true) {
        Symbol symbol_in(symbol);
        alphabet_.Insert(symbol_in);
      }
    }
  }
  for (int i = 0; i < line.size(); ++i) {
    for (auto& symbol:alphabet_.Get_Symbols()) {
      std::string symbol_ch = line.substr(i, symbol.Size());
      if (symbol.Get_Symbol() == symbol_ch) {
        string_pos_.push_back(symbol);
        i += symbol.Size() - 1;
        break;
      }
    }
  }
}

Chain::Chain(std::string string, Alphabet alphabet) {
  alphabet_ = alphabet;
  for (int i = 0; i < string.size(); ++i) {
    for (auto& symbol:alphabet_.Get_Symbols()) {
      std::string symbol_ch = string.substr(i, symbol.Size());
      if (symbol.Get_Symbol() == symbol_ch) {
        string_pos_.push_back(symbol);
        i += symbol.Size() - 1;
        break;
      }
    }
  }
}

// Getter que devuelve el alfabeto
Alphabet Chain::Get_Alphabet() const {
  return alphabet_;
}

//Getter que devuelve el vector de símbolo
std::vector<Symbol> Chain::Get_Chain() const {
  return string_pos_;
}

// Método que devuelve el tamaño de la cadena
int Chain::Get_Size() const {
  return string_pos_.size();
}

// Método que invierte la cadena
void Chain::Invert() {
  std::vector<Symbol> v_copy = string_pos_;
  for (int i = 0; i < v_copy.size(); ++i) {
    string_pos_[v_copy.size() - i - 1] = v_copy[i];
  }
}

// Método para añadir letras a la cadena
void Chain::Push_back(Symbol symbol) {
  string_pos_.push_back(symbol);
}

// Sobrecarga de operadores
// Elevar
Chain operator^(const Chain& chain, const int& number) {
  int size = chain.Get_Size();
  Chain raised_chain;
  for (int i = 0; i < number; ++i) {
    for (int j = 0; j < size; ++j){
      raised_chain.Push_back(chain.Get_Chain()[j]);
    }
  }
  return raised_chain;
}

// Concatenar
Chain operator*(const Chain& chain1, const Chain& chain2) {
  Chain new_chain = chain1;
  for (auto& symbol:chain2.Get_Alphabet().Get_Symbols()) {
    new_chain.alphabet_.Insert(symbol);
  }
  for (int i = 0; i < chain2.Get_Size(); ++i){
    new_chain.string_pos_.push_back(chain2.string_pos_[i]);
  }
  
  return new_chain;
}

// Igualdad
bool operator==(const Chain& chain1, const Chain& chain2) {
  bool flag = true;
  if(chain1.Get_Size() == chain2.Get_Size()) {
    for(int i = 0; i < chain1.Get_Size(); ++i) {
      if(chain1.string_pos_[i] != chain2.string_pos_[i]) {
        flag = false;
      }
    }
  }
  else {
    flag = false;
  }
  return flag;
}

// Menor que
bool operator<(const Chain& chain1, const Chain& chain2) {
  for (int i = 1; i <= chain2.Get_Size(); ++i) {
    for (int j = 0; j < chain2.Get_Size() + 1 - i; ++j) {
      Chain new_chain;
      for (int k = 0; k < i; ++k) {
        new_chain.Push_back(chain2.Get_Chain()[k + j]);
      }
      if (chain1 == new_chain) {
        return true;
      }
    }
  }
  return false;
}

// Mayor que
bool operator>(const Chain& chain1, const Chain& chain2) {
  for (int i = 1; i <= chain1.Get_Size(); ++i) {
    for (int j = 0; j < chain1.Get_Size() + 1 - i; ++j) {
      Chain new_chain;
      for (int k = 0; k < i; ++k) {
        new_chain.Push_back(chain1.Get_Chain()[k + j]);
      }
      if (chain2 == new_chain) {
        return true;
      }
    }
  }
  return false;
}

// Desigualdad
bool operator!=(const Chain& chain1, const Chain& chain2) {
  bool flag = false;
  if(chain1.Get_Size() == chain2.Get_Size()) {
    for(int i = 0; i < chain1.Get_Size(); ++i) {
      if(chain1.string_pos_[i] != chain2.string_pos_[i]) {
        flag = true;
      }
    }
  }
  else {
    flag = true;
  }
  return flag;
}

// Salida
std::ostream& operator<<(std::ostream& out, const Chain& string) {
  for (int i = 0; i < string.string_pos_.size(); i++) {
    out << string.string_pos_[i];
  }
  return out;
}

//Entrada
std::istream& operator>>(std::istream& in, Chain& string) {
  std::string line;
  in >> line;
  Chain chain(line);
  string.string_pos_ = chain.Get_Chain();
  string.alphabet_ = chain.Get_Alphabet();
  return in;
}