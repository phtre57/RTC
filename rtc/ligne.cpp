/*
 * ligne.cpp
 *
 *  Created on: 2016-09-20
 *      Author: etudiant
 */

#include "ligne.h"
#include "ContratException.h"

/**
 * \brief Constructeur de l'objet Ligne
 * \param[in] Une vector contenant le contenu de la ligne gtfs routes.txt
 */
Ligne::Ligne(const std::vector<std::string>& ligne_gtfs):
	m_id(std::stoul(ligne_gtfs[0])), m_numero(ligne_gtfs[2]),
	m_description(ligne_gtfs[4]),m_categorie(couleurToCategorie(ligne_gtfs[7])),
	m_voyages(std::vector<Voyage*>())
{

}

/**
 * \brief Transforme le string contenant la couleur de la Ligne en une Categorie
 * \param[in] un string contenant la couleur
 * \return La Categorie de Ligne associee a la couleur de la Ligne
 */
CategorieBus Ligne::couleurToCategorie(std::string couleur)
{
	PRECONDITION(couleur == "97BF0D" or couleur == "013888" or
			couleur == "E04503" or couleur =="1A171B" or
			couleur == "003888");
	if (couleur == "97BF0D")
	{
		return CategorieBus::METRO_BUS;
	}

	if (couleur == "013888")
	{
		return CategorieBus::LEBUS;
	}

	if (couleur == "E04503")
	{
		return CategorieBus::EXPRESS;
	}

	if (couleur == "1A171B" or couleur == "003888")
	{
		return CategorieBus::COUCHE_TARD;
	}

	return CategorieBus::LEBUS;
}

/**
 * \brief Transforme une Categorie de Ligne en un string couleur
 * \param[in] La Categorie de la bus
 * \return Le string de la couleur, pour la Categorie COUCHE_TARD retourne toujours le string "1A171B"
 */
std::string Ligne::categorieToString(CategorieBus c)
{
	if (c == CategorieBus::LEBUS)
	{
		return "013888";
	}

	if (c == CategorieBus::METRO_BUS)
	{
		return "97BF0D";
	}

	if (c == CategorieBus::EXPRESS)
	{
		return "E04503";
	}

	if (c == CategorieBus::COUCHE_TARD)
	{
		return "1A171B";
	}

	return "013888";
}

/**
 * \brief getter de la Categorie de la Ligne
 * \return La Categorie de la Ligne
 */
CategorieBus Ligne::getCategorie() const
{
	return m_categorie;
}

/**
 * \brief setter de la Categorie de la Ligne
 * \param[in] Un Categorie
 */
void Ligne::setCategorie(CategorieBus categorie)
{
	m_categorie = categorie;
}

/**
 * \brief getter de la destinations de la Ligne
 * \return une pair de string contenant les destinations de la Ligne
 */
std::pair<std::string, std::string> Ligne::getDestinations() const
{
	size_t pos = m_description.find(" - ");
	std::string ind_1 = m_description.substr(0, pos);
	std::string ind_2 = m_description.substr(pos + 3);
	if (ind_1 == "null")
	{
		return std::pair<std::string, std::string>(ind_2, "");
	}
	return std::pair<std::string, std::string>(ind_1, ind_2);

}

/**
 * \brief getter de l'id de la Ligne
 * \return un unsigned int de l'id
 */
unsigned int Ligne::getId() const
{
	return m_id;
}

/**
 * \brief setter de l'id de la ligne
 * \param[in] un unsigned int de l'id de la Ligne
 */
void Ligne::setId(unsigned int id)
{
	m_id = id;
}

/**
 * \brief getter du numero de la Ligne
 * \return un string du numero de la Ligne
 */
const std::string& Ligne::getNumero() const
{
	return m_numero;
}

/**
 * \brief setter du numero de la Ligne
 * \param[in] un string non-vide du numero de la Ligne
 */
void Ligne::setNumero(const std::string& numero)
{
	PRECONDITION(!(numero.empty()));
	m_numero = numero;
	POSTCONDITION(m_numero == numero);
}

/**
 * \brief getter des Voyages fait par la Ligne
 * \return un vector avec tous les Voyages d la Ligne
 */
const std::vector<Voyage*>& Ligne::getVoyages() const
{
	return m_voyages;
}

/**
 * \brief setter des Voyages de la Ligne
 * \param[in] un vector contenant tous les Voyages de la Ligne
 */
void Ligne::setVoyages(const std::vector<Voyage*>& voyages)
{
	m_voyages = voyages;

}

/**
 * \brief Ajoute un voyage au vector de tous les Voyages fait par la Ligne
 * \param[in] un pointeur sur un objet Voyage
 */
void Ligne::addVoyage(Voyage* ptr_voyage)
{
	m_voyages.push_back(ptr_voyage);
	POSTCONDITION(!(m_voyages.empty()));
}

/**
 * \brief getter de la description de la ligne
 * \return un string de la description de la Ligne
 */
const std::string& Ligne::getDescription() const
{
	return m_description;
}

/**
 * \brief setter de la description de la Ligne
 * \param[in] un string non-vide contenant la description de la Ligne
 */
void Ligne::setDescription(const std::string& description)
{
	PRECONDITION(!(description.empty()));
	m_description = description;
	POSTCONDITION(m_description == description);
}
