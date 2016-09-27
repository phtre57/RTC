/*
 * voyage.cpp
 *
 *  Created on: 2016-09-20
 *      Author: etudiant
 */

#include "voyage.h"
#include "ContratException.h"

/**
 * \brief Constructeur de Voyage
 * \param[in] un vecteur contenant la ligne gtfs
 * \param[in] un ptr sur une Ligne
 */
Voyage::Voyage(const std::vector<std::string>& ligne_gtfs, Ligne* p_ligne):
	m_id(ligne_gtfs[2]), m_ligne(p_ligne), m_service_id(ligne_gtfs[1]),
	m_destination(ligne_gtfs[3])

{

}

/**
 * \brief recherche une station parmis le vecteur de station du Voyage
 * \param[in] un unsigned int contenent le num_station de la station a trouve
 * \return l'objet Arret si elle est presente dans le vecteur sinon throw une exception de type runetime_error
 */
Arret& Voyage::arretDeLaStation(unsigned int p_num_station)
{
	PRECONDITION(!(m_arrets.empty()));
	for (std::vector<Arret>::iterator it = m_arrets.begin();
			it != m_arrets.end(); ++it)
	{
		if (p_num_station == it->getStationId())
		{
			return *it;
		}
	}

	throw std::runtime_error("Numero de station inexistante");
}

/**
 * \brief getter du vector des Arrets du Voyage
 * \return le vector contenant les Arrets du Voyage
 */
std::vector<Arret> Voyage::getArrets() const
{
	return m_arrets;
}

/**
 * \brief getter de la destination du Voyage
 *\return un string de la Destination du Voyage
 */
const std::string& Voyage::getDestination() const
{
	return m_destination;
}

/**
 * \brief setter de la destination du Voyage
 * \param[in] un string non-vide contenant la destination du Voyage
 */
void Voyage::setDestination(const std::string& p_destination)
{
	PRECONDITION(!(p_destination.empty()));
	m_destination = p_destination;
	POSTCONDITION(m_destination == p_destination);
}

/**
 * \brief getter de l'id du Voyage
 * \return un string contenant l'id du Voyage
 */
std::string Voyage::getId() const
{
	return m_id;
}

/**
 * \brief setter du l'id du Voyage
 * \param[in] un string non-vide contenant l'id du Voyage
 */
void Voyage::setId(std::string p_id)
{
	PRECONDITION(!(p_id.empty()));
	m_id = p_id;
	POSTCONDITION(m_id == p_id);
}

/**
 * \brief getter de la Ligne du Voyage
 * \return un ptr sur un objet Ligne du Voyage
 */
Ligne* Voyage::getLigne() const
{
	return m_ligne;
}

/**
 * \brief setter de la Ligne du Voyage
 * \param[in] un ptr sur un objet Ligne correspondant a la Ligne du Voyage
 */
void Voyage::setLigne(Ligne* p_ligne)
{
	m_ligne = p_ligne;
}

/**
 * \brief getter du service id du Voyage
 * \return un string contenant le service id du Voyage
 */
std::string Voyage::getServiceId() const
{
	return m_service_id;
}

/**
 * \brief setter du service id du Voyage
 * \param[in] un string non-vide contenant le service id du Voyage
 */
void Voyage::setServiceId(std::string p_service_id)
{
	PRECONDITION(!(p_service_id.empty()));
	m_service_id = p_service_id;
	POSTCONDITION(m_service_id == p_service_id);
}

/**
 * \brief getter de l'heure de depart du Voyage
 * \return un objet Heure
 */
Heure Voyage::getHeureDepart() const
{
	PRECONDITION(!(m_arrets.empty()));
	return m_arrets[0].getHeureDepart();
}

/**
 * \brief getter de l'heure de la fin du Voyage
 * \return un objet Heure
 */
Heure Voyage::getHeureFin() const
{
	PRECONDITION(!(m_arrets.empty()));
	return m_arrets.back().getHeureArrivee();
}

/**
 * \brief setter du vector contenant les Arrets du Voyage
 * \param[in] un vecteur contenant tous les Arrets du Voyage
 */
void Voyage::setArrets(std::vector<Arret>& resultat)
{
	m_arrets = resultat;
}

/**
 * \brief operator < sur 2 objets Voyage
 * \return un booleen
 */
bool Voyage::operator <(const Voyage& p_other) const
{
	PRECONDITION(!(m_arrets.empty()) and !(p_other.m_arrets.empty()));
	return (this->getHeureDepart() < p_other.getHeureDepart());
}

/**
 * \brief operator > sur 2 objets Voyage
 * \return un booleen
 */
bool Voyage::operator >(const Voyage& p_other) const
{
	PRECONDITION(!(m_arrets.empty()) and !(p_other.m_arrets.empty()));
	return (this->getHeureDepart() > p_other.getHeureDepart());
}
