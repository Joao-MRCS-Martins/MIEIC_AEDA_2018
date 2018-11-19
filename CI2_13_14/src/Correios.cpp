/*
 * Conrreios.cpp
 */

#include "Correios.h"

Central::Central(int id){
  ID = id;
}

void Central::adicionaAgencia(Agencia agencia){
  agencias.push_back(agencia);
}

vector<Agencia> Central::getAgencias() const{
  return agencias;
}

Agencia::Agencia(string nome){
  this->nome = nome;
}

void Agencia::adicionaCarta(Correspondencia *carta){
  cartas.push_back(carta);
}

vector<Correspondencia *> Agencia::getCartas() const{
  return cartas;
}

string  Agencia::getNome() const{
  return nome;
}

vector<Correspondencia *> Agencia::getCorrespondencia() const{
  return cartas;
}



Correspondencia::Correspondencia(string destino, int prioridade){
  this->destino = destino;
  this->prioridade = prioridade;
}

string Correspondencia::getDestino() const{
  return destino;
}

int Correspondencia::getPrioridade() const{
  return prioridade;
}

CorreioNormal::CorreioNormal(string destino, int prioridade, int preco):Correspondencia(destino, prioridade){
  this->preco = preco;
}

EMS::EMS(string destino, int prioridade, int peso):Correspondencia(destino, prioridade){
  this->peso = peso;
}

//////////////////////    resolucao   ///////////////////////////

