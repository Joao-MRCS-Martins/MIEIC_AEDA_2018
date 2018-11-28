#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "BST.h"


class PalavraSignificado {
      string palavra;
      string significado;
public:
       PalavraSignificado(string p, string s): palavra(p), significado(s) {}
       string getPalavra() const { return palavra; }
       string getSignificado() const { return significado; }
       void setSignificado(string sig) { significado = sig; }
       bool operator < (const PalavraSignificado &ps1) const;
};

class Dicionario
{
      BST<PalavraSignificado> palavras;
public:
      Dicionario(): palavras(PalavraSignificado("","")){};
      BST<PalavraSignificado> getPalavras() const;
      void lerDicionario(ifstream &fich);
      string consulta(string palavra) const;
      bool corrige(string palavra, string significado);
      void imprime() const;
};


// a alterar
class PalavraNaoExiste
{
	string pAnt;
	string sAnt;
	string pAps;
	string sAps;
public:
	PalavraNaoExiste(string pa,string sa,string pap,string sap) {pAnt = pa; sAnt = sa; pAps = pap; sAps = sap;}
	string getPalavraAntes() const ;
	string getSignificadoAntes() const ;
	string getPalavraApos() const ;
	string getSignificadoApos() const ;
};



#endif
