/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom, int reference,
	double prix, TypeProduit type, double prixBase, int identifiantClient) :Produit(fournisseur, nom, reference, prix, type) {
	prixBase_ = prixBase;
	identifiantClient_ = identifiantClient;
}

int ProduitAuxEncheres::obtenirIdentifiantClient() const {
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const {
	return prixBase_;
}

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient) {
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase) {
	prixBase_ = prixBase;
}

ostream &operator<<(ostream &os,const ProduitAuxEncheres &produit) {
	os << static_cast<Produit>(produit) << "\t Prix de Base  " << produit.prixBase_ << endl << "\t Identifiant Client " << produit.identifiantClient_ << endl;
	return os;
}

istream &operator>>(istream &is, ProduitAuxEncheres &produit) {
	is >> static_cast<Produit>(produit) >> produit.prixBase_ >> produit.identifiantClient_;
	return is;
}