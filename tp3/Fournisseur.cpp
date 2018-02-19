/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal)
	:Usager(nom,prenom,identifiant,codePostal) {
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction_.niveaux_[i] = 0;
	}
	
}

Satisfaction Fournisseur::obtenirSatisfaction() const{
	return satisfaction_;
}

vector<Produit*> Fournisseur::obtenirCatalogue() const {
	return contenuCatalogue_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction) {
	satisfaction_ = satisfaction;
}

void Fournisseur::noter(int appreciation) {
	if (appreciation > 4)
		appreciation = 4;//On force l'appreciation au niveau maximum de satisfaction si elle est suppérieur a celui-ci (5 niveau, indice de 0a4)
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit* produit) {
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit* produit) {
    for (int i = 0; i < contenuCatalogue_.size(); i++) {
        if (contenuCatalogue_[i] == produit) {
            // If the order isn't important
            contenuCatalogue_[i] = contenuCatalogue_.back();

            contenuCatalogue_.pop_back();
            break;
        }
    }
}

Fournisseur& Fournisseur::operator=(const Fournisseur &fournisseur) {
	if (this != &fournisseur) {
		Usager temp(*this);
		temp = static_cast<Usager>(fournisseur);
		satisfaction_ = fournisseur.satisfaction_;
		return *this;
	}
	 


}