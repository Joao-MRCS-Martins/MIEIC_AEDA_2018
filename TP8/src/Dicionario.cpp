#include <iostream>
#include <string>
#include <fstream>
#include "Dicionario.h"
#include "BST.h"

using namespace std;


BST<PalavraSignificado> Dicionario::getPalavras() const
{ return palavras; }



bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const
{
	return getPalavra() < ps1.getPalavra();
}


void Dicionario::lerDicionario(ifstream &fich)
{
	string nome;
	string significado;
	while(getline(fich,nome)) {
		nome = nome.substr(0,nome.find('\r'));
		getline(fich, significado);
		significado = significado.substr(0,significado.find('\r'));
		palavras.insert(PalavraSignificado(nome,significado));
	}
	return;
}


string Dicionario::consulta(string palavra) const
{
    BSTItrIn<PalavraSignificado> bt(palavras);
    PalavraSignificado pAntes("","");
    PalavraSignificado pAtual("","");
    while(!bt.isAtEnd()) {
    	pAntes = pAtual;
    	pAtual = bt.retrieve();
    	if(palavra < bt.retrieve().getPalavra())
    		break;
    	if(bt.retrieve().getPalavra() == palavra) {
    		return bt.retrieve().getSignificado();
    	}
    	bt.advance();
    }
    throw PalavraNaoExiste(pAntes.getPalavra(),pAntes.getSignificado(),pAtual.getPalavra(),pAtual.getSignificado());
}


bool Dicionario::corrige(string palavra, string significado)
{
	try
	{
		string sig = consulta(palavra);
		PalavraSignificado p1(palavra,sig);
		palavras.remove(p1);
		p1.setSignificado(significado);
		palavras.insert(p1);
		return true;
	}
	catch (PalavraNaoExiste &e){
		palavras.insert(PalavraSignificado(palavra,significado));
		return false;
	}
}


void Dicionario::imprime() const
{
	BSTItrPost<PalavraSignificado> bt(palavras);
	while(!bt.isAtEnd()) {
		cout << bt.retrieve().getPalavra() << endl << bt.retrieve().getSignificado() << endl;
		bt.advance();
	}
     return;
}

string PalavraNaoExiste::getPalavraAntes() const {
	return pAnt;
}

string PalavraNaoExiste::getSignificadoAntes() const {
	return sAnt;
}

string PalavraNaoExiste::getPalavraApos() const {
	return pAps;
}

string PalavraNaoExiste::getSignificadoApos() const {
	return sAps;
}
