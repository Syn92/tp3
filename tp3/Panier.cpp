/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient) {
	// TODO
	idClient_ = idClient;
	totalAPayer_ = 0.0;
}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()  const
{
	double totalapayer;
	for (int i = 0; i < contenuPanier_.size(); i++)
	{
		if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
		{
			ProduitAuxEncheres* tempEnchere = static_cast<ProduitAuxEncheres*>(contenuPanier_[i]);
			if (tempEnchere->obtenirIdentifiantClient() == idClient_)
			{
				totalapayer += contenuPanier_[i]->obtenirPrix();
			}
		}
		else if(contenuPanier_[i]->retournerType() == TypeProduitOrdinaire) {
			totalapayer += contenuPanier_[i]->obtenirPrix();
		}
	}
	return totalapayer;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	// TODO
	if (prod->retournerType() == TypeProduitOrdinaire)
	{
		ProduitOrdinaire* temp = static_cast<ProduitOrdinaire*>(prod);
		if (temp->obtenirEstTaxable())
			temp->modifierPrix(temp->obtenirPrix() + TAUX_TAXE);
	}

	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	for (int i = 0; i < panier.contenuPanier_.size(); i++)
	{
		os << panier.contenuPanier_[i]->retournerType() <<panier.contenuPanier_[i] << endl;
		if (panier.contenuPanier_[i]->retournerType()==TypeProduitAuxEncheres) {
			ProduitAuxEncheres* tempEnchere = static_cast<ProduitAuxEncheres*>(panier.contenuPanier_[i]);
			os << tempEnchere << endl;
		}
		else {
			ProduitOrdinaire* tempOrdinaire = static_cast<ProduitOrdinaire*>(panier.contenuPanier_[i]);
			os << tempOrdinaire << endl;
		}
	}
	

	return os;
}
