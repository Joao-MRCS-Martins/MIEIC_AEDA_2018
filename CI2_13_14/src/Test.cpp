#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Correios.h"

void test_a_EstaOrdenado() {
  /*
  Agencia ag1("ag1");

  ag1.adicionaCarta(new CorreioNormal("lisboa", 1, 1));
  ag1.adicionaCarta(new CorreioNormal("porto", 5, 6));
  ag1.adicionaCarta(new EMS("porto", 2, 4));
  ag1.adicionaCarta(new EMS("lisboa", 1, 10));

  ASSERT(ag1.estaOrdenado());

  ag1.adicionaCarta(new EMS("lisboa", 1, 2));

  ASSERT(! ag1.estaOrdenado());
  */
}

void test_b_Recolha() {
  /*
  Agencia ag1("ag1");
  vector<Correspondencia *> expedidas;

  ag1.adicionaCarta(new CorreioNormal("lisboa", 1, 1));
  ag1.adicionaCarta(new CorreioNormal("porto", 5, 6));
  ag1.adicionaCarta(new EMS("barcelos", 2, 4));
  ag1.adicionaCarta(new EMS("albufeira", 1, 10));
  ag1.adicionaCarta(new EMS("porto", 2, 10));
  ag1.adicionaCarta(new CorreioNormal("lisboa", 3, 8));
  
  expedidas = ag1.recolha("barcelos", "lisboa");
  ASSERT_EQUAL(3, expedidas.size());
  ASSERT_EQUAL(3, (ag1.getCartas()).size());
  */
}

void test_c_EnviarPara() {
  /*
  Agencia ag1("ag1");

  ag1.adicionaCarta(new CorreioNormal("lisboa", 1, 1));
  ag1.adicionaCarta(new CorreioNormal("porto", 5, 6));
  ag1.adicionaCarta(new EMS("barcelos", 2, 4));
  ag1.adicionaCarta(new EMS("albufeira", 1, 10));
  ag1.adicionaCarta(new EMS("porto", 2, 10));
  ag1.adicionaCarta(new CorreioNormal("lisboa", 3, 8));

  try {
    ag1.enviarPara("matosinhos");
  }
  catch (DestinoInexistente &e) {
    cout << "Apanhou excepção. Destino inexistente: " << e.getDestino() << endl;
    ASSERT_EQUAL("matosinhos", e.getDestino());
  }

  Correspondencia *carta = ag1.enviarPara("lisboa");
  ASSERT_EQUAL("lisboa", carta->getDestino());
  */
}


void test_d_PrioridadesETamanho() {
  /*
  Central c1(1);
  Agencia ag1("ag1");
  Agencia ag2("ag2");
  Agencia ag3("ag3");

  ag1.adicionaCarta(new CorreioNormal("lisboa", 1, 1));
  ag1.adicionaCarta(new CorreioNormal("porto", 5, 6));
  ag1.adicionaCarta(new EMS("barcelos", 2, 4));
  ag1.adicionaCarta(new EMS("albufeira", 1, 10));
  ag1.adicionaCarta(new EMS("porto", 2, 10));

  c1.adicionaAgencia(ag1);

  ag2.adicionaCarta(new CorreioNormal("lisboa", 1, 10));
  ag2.adicionaCarta(new CorreioNormal("porto", 15, 16));
  ag2.adicionaCarta(new EMS("barcelos", 5, 4));
  ag2.adicionaCarta(new EMS("albufeira", 4, 4));
  ag2.adicionaCarta(new EMS("porto", 3, 12));
  ag2.adicionaCarta(new CorreioNormal("lisboa", 1, 2));

  c1.adicionaAgencia(ag2);

  ag3.adicionaCarta(new CorreioNormal("lisboa", 1, 10));
  ag3.adicionaCarta(new CorreioNormal("porto", 15, 16));
  ag3.adicionaCarta(new EMS("barcelos", 5, 4));
  ag3.adicionaCarta(new EMS("albufeira", 4, 4));
  ag3.adicionaCarta(new EMS("porto", 3, 12));
  ag3.adicionaCarta(new CorreioNormal("lisboa", 1, 2));
  ag3.adicionaCarta(new CorreioNormal("santarem", 11, 12));
  ag3.adicionaCarta(new CorreioNormal("lixa", 3, 20));

  c1.adicionaAgencia(ag3);

  ASSERT_EQUAL("ag3", (c1.agenciaPrioritaria(1)).getNome());
  ASSERT_EQUAL("ag3", (c1.agenciaMaior(1)).getNome());

  ASSERT_EQUAL("ag1", (c1.agenciaPrioritaria(3)).getNome());
  ASSERT_EQUAL("ag2", (c1.agenciaMaior(2)).getNome());
  */
}



void test_e_TestRegiaoNorte() {
  /*
  vector<EMS> ems;
  EMS ems1("albufeira", 1, 2);
  EMS ems2("barcelos", 1, 3);
  EMS ems3("lisboa", 1, 1);
  EMS ems4("lisboa", 1, 4);
  EMS ems5("porto", 1, 3);
  EMS ems6("valenca", 1, 3);
  EMS ems7("valongo", 1, 5);
  EMS ems8("valongo", 1, 2);
  
  ems.push_back(EMS("albufeira", 1, 2));
  ems.push_back(EMS("barcelos", 1, 2));
  ems.push_back(EMS("lisboa", 1, 2));
  ems.push_back(EMS("porto", 1, 2));
  ems.push_back(EMS("porto", 1, 2));
  ems.push_back(EMS("valenca", 1, 2));
  ems.push_back(EMS("valongo", 1, 2));
  ems.push_back(EMS("valongo", 1, 2));

  ASSERT_EQUAL("valenca", naRegiaoNorte(ems, "lisboa", "valongo"));
  */
}


void test_f_FusaoDeVetores() {
  /*
  vector<int> ints1;
  vector<int> ints2;
  vector<int> combInt;
  vector<unsigned int> uint1;
  vector<unsigned int> uint2;
  vector<unsigned int> combUint;
  vector<string> str1;
  vector<string> str2;
  vector<string> combStr;

  ints1.push_back(-1);
  ints1.push_back(2);
  ints1.push_back(3);
  ints1.push_back(4);
  ints1.push_back(9);

  ints2.push_back(-1);
  ints2.push_back(2);
  ints2.push_back(7);
  ints2.push_back(9);

  uint1.push_back(1);
  uint1.push_back(2);
  uint1.push_back(3);
  uint1.push_back(7);

  uint2.push_back(2);
  uint2.push_back(7);
  uint2.push_back(9);


  str1.push_back("AA");
  str1.push_back("FF");

  str2.push_back("BB");
  str2.push_back("CC");
  str2.push_back("DD");
  str2.push_back("EE");

  combInt = combinaVetores(ints1, ints2);
  combUint = combinaVetores(uint1, uint2);
  combStr = combinaVetores(str1, str2);

  ASSERT_EQUAL(6, combInt.size());
  ASSERT_EQUAL(5, combUint.size());
  ASSERT_EQUAL(6, combStr.size());


  ASSERT_EQUAL(2, combInt[1]);
  ASSERT_EQUAL(9, combUint[4]);
  ASSERT_EQUAL("EE", combStr[4]);
  */
}



void test_g_ContaAgencias() {
  /*
  Agencia a1("ag1");
  Agencia a2("ag2");
  Agencia a3("ag3");

  ASSERT_EQUAL(9, Central::getAgenciasGeradas());
  */
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_a_EstaOrdenado));
	s.push_back(CUTE(test_b_Recolha));
	s.push_back(CUTE(test_c_EnviarPara));
	s.push_back(CUTE(test_d_PrioridadesETamanho));
	s.push_back(CUTE(test_e_TestRegiaoNorte));
	s.push_back(CUTE(test_f_FusaoDeVetores));
	s.push_back(CUTE(test_g_ContaAgencias));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "AEDA 2013/2014 - Avaliação - 23/out - Testes Unitarios Estudantes");
}

int main(){
    runSuite();
    return 0;
}

