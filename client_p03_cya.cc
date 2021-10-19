// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo client-p03_cya.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases string y alphabet
// que realizan el trabajo de leer el fichero de entrada al fichero de salida.
// Referencias:
// Enlaces de interés:


#include <fstream>
#include "language.h"

int main(int argc, char* argv[]) {
  assert(argc >= 4);
  //Variables dedicadas a la construcción de la cadena
  std::ifstream infile(argv[1]);
  std::ofstream outfile(argv[2]);
  std::string option {argv[3]};
  std::string line;

  //Variables dedicadas al uso de las opciones
  bool first_case = false;
  Chain case_6_7_info;
  int case_8_info;
  
   while (getline(infile, line)) {
    Chain chain (line);
    Language language;

    switch (std::stoi (option)) {

      case 1: // Devuelve el tamaño de la cadena
        outfile << chain.Get_Size() << std::endl;
        break;

      case 2: // Devuelve la cadena invertida
        chain.Invert();
        outfile << chain << std::endl;
        break;

      case 3: // Devuelve los prefijos
        language.Add_Prefixes(chain);
        outfile << language << std::endl;
        break;

      case 4: // Devuelve los sufijos
        language.Add_Suffixes(chain);
        outfile << language << std::endl;
        break;

      case 5: // Devuelve las subcadenas
        language.Substrings(chain);
        outfile << language << std::endl;
        break;

      case 6: //Comprueba si es subcadena
        if (first_case == false) {
          std::cout << "Introduce una cadena para analizar: ";
          std::cin >> case_6_7_info;
        }
        if(chain == case_6_7_info){
          outfile << chain << " == " << case_6_7_info <<std::endl;
        }
        else if(chain > case_6_7_info){
          outfile << chain << " > " << case_6_7_info <<std::endl;
        }
        else if(chain < case_6_7_info){
          outfile << chain << " < " << case_6_7_info <<std::endl;
        }
        else {
          outfile << chain << " != " << case_6_7_info <<std::endl;
        }
        
        break;

      case 7: //Devuelve la cadena con una cadena concatenada
        if (first_case == false) {
          std::cout << "Introduce una cadena para concatenar: ";
          std::cin >> case_6_7_info;
        }
        outfile << chain*case_6_7_info <<std::endl;

        break;
      
      case 8: // Devuelve la potencia
        if (first_case == false) {
        std::cout << "Introduce un número para elevar: ";
        std::cin >> case_8_info;
        }
        chain = chain^case_8_info;
        outfile << chain <<std::endl;
        break;

      default:
        std::cout << option << "no es una opción valida. Debe introducir el" <<
        " archivo de entrada, el archivo de salida y una opción entre 1 y 8" << std::endl;
        break;
    }
    first_case = true;
  }
  outfile.close(); 
  infile.close();
  return 0;
}

//Falta 6