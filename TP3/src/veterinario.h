
#ifndef SRC_VETERINARIO_H_
#define SRC_VETERINARIO_H_

#include <string>
using namespace std;

class Veterinario {
	string nome;
	long codOrdem;
public:
	/**
	 * The constructor of the class Veterinario
	 * @param nome , the name of the Vet.
	 * @param cod , the code assigned to the Vet.
	 */
	Veterinario(string nome, int cod);
	/**
	 * Returns the name of the Vet.
	 */
	string getNome() const;
	/**
	 * Returns the code of the Vet.
	 */
	long getCod() const;
	/**
	 * Sets the name of the Vet
	 * @param nomeA , the name to be set.
	 */
	void setNome(string nomeA) ;
	/**
	 * Sets the code of the Vet
	 * @param cod , the code to be set.
	 */
	void setCod(long cod);
	/**
	 * Overload of the operator of assignment, = , to allow assignments to object of class Veterinario.
	 * @param v1 , the Vet object passed by constant reference to allow safe copy.
	 */
	Veterinario & operator= (const Veterinario &v1) {
		this->setNome(v1.getNome());
		this->setCod(v1.getCod());
		return *this;
	}
	/**
	 * Returns true if the name of the Vet is the same of the argument.
	 * @param nameV , the name to be compared with the Vet's.
	 */
	bool sameNome(const string &nameV);
};



#endif /* SRC_VETERINARIO_H_ */
