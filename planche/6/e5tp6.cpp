#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    int age;
    char sexe;

public:
    Personne(string nom, int age, char sexe) : nom(nom), age(age), sexe(sexe) {}

    string getNom() const { return nom; }
    int getAge() const { return age; }
    char getSexe() const { return sexe; }

    void setNom(string nom) { this->nom = nom; }
    void setAge(int age) { this->age = age; }
    void setSexe(char sexe) { this->sexe = sexe; }

    virtual string getPersonne() const {
        return "Nom: " + nom + ", Age: " + to_string(age) + ", Sexe: " + sexe;
    }
};

class Enseignant : public Personne {
private:
    string charge;

public:
    Enseignant(string nom, int age, char sexe, string charge)
        : Personne(nom, age, sexe), charge(charge) {}

    string getCharge() const { return charge; }
    void setCharge(string charge) { this->charge = charge; }

    string getPersonne() const override {
        return Personne::getPersonne() + ", Charge: " + charge;
    }
};

class Etudiant : public Personne {
private:
    string filiere;

public:
    Etudiant(string nom, int age, char sexe, string filiere)
        : Personne(nom, age, sexe), filiere(filiere) {}

    string getFiliere() const { return filiere; }
    void setFiliere(string filiere) { this->filiere = filiere; }

    string getPersonne() const override {
        return Personne::getPersonne() + ", Filiere: " + filiere;
    }
};

class Contractuel : public Enseignant, public Etudiant , public Personne {
public:
    Contractuel(string nom, int age, char sexe, string charge, string filiere)
        : Personne(nom, age, sexe), Enseignant(nom, age, sexe, charge), Etudiant(nom, age, sexe, filiere) {}

    string getPersonne() const override {
        return Enseignant::getPersonne() + ", Filiere: " + Etudiant::getFiliere();
    }
};

int main() {
    Enseignant enseignant("Ali", 40, 'M', "Mathematiques");
    Etudiant etudiant("Sara", 20, 'F', "Informatique");
    Contractuel contractuel("Omar", 25, 'M', "Physique", "Chimie");

    cout << enseignant.getPersonne() << endl;
    cout << etudiant.getPersonne() << endl;
    cout << contractuel.getPersonne() << endl;

    return 0;
}

