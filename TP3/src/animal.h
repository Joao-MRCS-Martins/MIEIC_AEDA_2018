#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinario.h"
#include <string>
using namespace std;

class Animal {
protected:
	string nome;
	int idade;
	Veterinario *vet;
	static int maisJovem;
public:
	/**
	 * The constructor for the class Animal.
	 * @param nome , set the name of the animal.
	 * @param idade , set the age of the animal.
	 */
	Animal(string nome, int idade);
	/**
	 * Virtual member for the destructor of the class Animal.
	 */
	virtual ~Animal(){};
	/**
	 * Returns the name attribute of Animal object.
	 */
	string getNome() const;
	/**
	 * Returns the age attribute of Animal object.
	 */
	int getIdade() const;
	/**
	 * Returns the name of the veterinary assigned to the animal.
	 */
	string getNomeVet() const;
	/**
	 * Returns the code of the veterinary assigned to the animal.
	 */
	long getCodVet() const;
	/**
	 * Static member returns the age of the youngest animal created.
	 */
	static int getMaisJovem();
	/**
	 * Virtual member to return true if the animal is young. There won't be no usage
	 * in Animal class, but on the classes derivated from it.
	 */
	virtual bool eJovem() const;
	/**
	 * Virtual member that will return the Animal information, i.e., the attributes.
	 */
	virtual string getInformacao() const;
	/**
	 * Assigns a given veterinary to the animal.
	 * @param v1 is a pointer to an object of class Veterinary.
	 */
	void setVeterinario(Veterinario * v1) ;
};



class Cao: public Animal {
	string raca;
public:
	/**
	 * The constructor of the class Cao
	 * @param nome , the name of the dog.
	 * @param idade , its age.
	 * @param raca , its breed.
	 */
	Cao(string nome, int idade, string raca);
	/**
	 * Return true if the dog is young.
	 */
	bool eJovem() const;
	/**
	 * Returns the information about the object: name, age and breed.
	 */
	string getInformacao() const;
};



class Voador {
	int velocidade_max;
	int altura_max;
public:
	/**
	 * The constructor of the class Voador.
	 * @param vmax , the maximum velocity achieved by the flying animal.
	 * @param amax , the maximum height achieved by the flying animal.
	 */
	Voador(int vmax, int amax);
	/**
	 * Virtual member for the destructor of the class Voador
	 */
	virtual ~Voador(){};
	/**
	 * Returns the information about the object: the maximum velocity and maximum height.
	 */
	string getInformacao() const;

};



class Morcego: public Animal, public Voador {
public:
	/**
	 * The constructor of the class Morcego
	 * @param nome , the name of the bat.
	 * @param idade , the age of the bat.
	 * @param vmax , the maximum velocity achieved by the bat.
	 * @param amax, the maximum height achieved by the bat.
	 */
	Morcego(string nome, int idade, int vmax, int amax);
	/**
	 * Returns true if the bat is young.
	 */
	bool eJovem() const;
	/**
	 * Returns the information about the object: name, age, maximum velocity and maximum height.
	 */
	string getInformacao() const;
};


#endif /* SRC_ANIMAL_H_ */
