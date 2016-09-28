/*
 * arret.cpp
 *
 *  Created on: 2016-09-20
 *      Author: etudiant
 */

#include <sstream>
#include "ContratException.h"
#include "arret.h"

/**
 * \brief Constructeur d'Arret
 * \param[in] un vecteur de string contenent les informations d'une ligne gtfs
 */
Arret::Arret(const std::vector<std::string>& ligne_gtfs):
	m_station_id(stoi(ligne_gtfs[3])), m_heure_arrivee(stringToHeure(ligne_gtfs[1])),
	m_heure_depart(stringToHeure(ligne_gtfs[2])),
	m_numero_sequence(stoi(ligne_gtfs[4])), m_voyage_id(ligne_gtfs[0])
{
	INVARIANTS();
}

/**
 * \brief getter de l'Heure d'arrivee a l'arret
 * \return un objet Heure
 */
const Heure& Arret::getHeureArrivee() const
{
	return m_heure_arrivee;
}

/**
 * \brief setter de l'Heure d'arrivee
 * \param[in] un objet Heure valide
 */
void Arret::setHeureArrivee(const Heure& p_heureArrivee)
{
	m_heure_arrivee = p_heureArrivee;
}

/**
 * \brief getter de l'Heure de depart
 * \return un objet Heure
 */
const Heure& Arret::getHeureDepart() const
{
	return m_heure_depart;
}

/**
 * \brief setter de l'Heure de depart
 * \param[in] un objet Heure valide
 */
void Arret::setHeureDepart(const Heure& p_heureDepart)
{
	m_heure_depart = p_heureDepart;
}

/**
 * \brief getter du numero de sequence
 * \return un unsigned int du numero de sequence
 */
unsigned int Arret::getNumeroSequence() const
{
	return m_numero_sequence;
}

/**
 * \brief setter du numero de sequence
 * \param[in] un unsigned int du numero de sequence
 */
void Arret::setNumeroSequence(unsigned int p_numeroSequence)
{
	m_numero_sequence = p_numeroSequence;
}

/**
 * \brief getter de la station_id
 * \return un unsigned int de la station_id
 */
unsigned int Arret::getStationId() const
{
	return m_station_id;
}

/**
 * \brief setter de la station_id
 * \param[in] un unsigned int de la station_id
 */
void Arret::setStationId(unsigned int stationId)
{
	m_station_id = stationId;
}

/**
 * \brief getter du voyage_id
 * \return un string contenant le voyage_id
 */
std::string Arret::getVoyageId() const
{
	return m_voyage_id;
}

/**
 * \brief setter du voyage_id
 * \param[in] un string non-vide contenant le voyage_id
 */
void Arret::setVoyageId(const std::string& voyageId)
{
	PRECONDITION(!(voyageId.empty()));
	m_voyage_id = voyageId;
	POSTCONDITION(m_voyage_id == voyageId);
	INVARIANTS();
}

/**
 * \brief operator < comparant deux objets Arret
 * \param[in] un autre Arret
 * \return un booleen
 */
bool Arret::operator <(const Arret& p_other) const
{
	return (this->m_numero_sequence < p_other.m_numero_sequence);
}

/**
 * \brief operator > comparant deux objets Arret
 * \param[in] un autre Arret
 * \return un booleen
 */
bool Arret::operator >(const Arret& p_other) const
{
	return (this->m_numero_sequence > p_other.m_numero_sequence);
}

/**
 * \brief transforme un string contenant une heure en un objet Heure
 */
const Heure Arret::stringToHeure(std::string p_str) const
{
	std::istringstream is(p_str);
	std::string segment;
	std::vector<int> vect = std::vector<int>();
	while (std::getline(is, segment, ':'))
	{
		vect.push_back(stoi(segment));
	}

	return Heure(vect[0], vect[1], vect[2]);
}

void Arret::verifieInvariant()
{
	INVARIANT(!(m_voyage_id.empty()));
}
