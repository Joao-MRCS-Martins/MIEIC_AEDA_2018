/*
 * Correios.h
 */

#ifndef CORREIOS_H_
#define CORREIOS_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Correspondencia {
 protected:
  string destino;
  int prioridade;
public:
  Correspondencia(string destino, int prioridade);
  string getDestino() const;
  int getPrioridade() const;
  //
};

class CorreioNormal: public Correspondencia {
  int preco;
public:
  CorreioNormal(string destino, int prioridade, int preco);
  //
};

class EMS: public Correspondencia {
  int peso;
public:
  EMS(string destino, int prioridade, int peso);
  //
};


class Agencia {
	string nome;
	vector<Correspondencia *> cartas;

public:
	Agencia(string nome);
	void adicionaCarta(Correspondencia *carta);
	vector<Correspondencia *> getCartas() const;
	string getNome() const;
	vector<Correspondencia *> getCorrespondencia() const;
	//
};


class Central {
  int ID;
  vector<Agencia> agencias;
public:
  Central(int id);
  void adicionaAgencia(Agencia agencia);
  vector<Agencia> getAgencias() const;
  // 
};


string naRegiaoNorte(vector<EMS> &cartas, string dest1, string dest2);

#endif /* CORREIOS_H_ */
