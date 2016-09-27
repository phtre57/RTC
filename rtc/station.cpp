/*
 * station.cpp
 *
 *  Created on: 2016-09-20
 *      Author: etudiant
 */

#include <sstream>
#include "station.h"
#include "ContratException.h"

/**
 * \brief Constructeur d'une station de bus
 * \param[in] vector contenant les string d'une ligne gtfs pour une station
 */
Station::Station(const std::vector<std::string>& ligne_gtfs):
	m_id(std::stoul(ligne_gtfs[0])), m_nom(ligne_gtfs[1]), m_description(ligne_gtfs[2]),
	m_coords(Coordonnees(std::stod(ligne_gtfs[3]), std::stod(ligne_gtfs[4]))),
	m_voyages_passants(std::vector<Voyage*>())
{

}

/**
 * \brief getter des Coordonnees d'une station
 * \return l'objet Coordonnees
 */
const Coordonnees& Station::getCoords() const
{
	return m_coords;
}

/**
 * \brief setter de m_coords
 * \param[in] prend une coordonnees valide
 */
void Station::setCoords(const Coordonnees& coords)
{
	PRECONDITION(coords.is_valide_coord(coords.getLatitude(), coords.getLongitude()));
	m_coords = coords;
	POSTCONDITION(m_coords.getLatitude() == coords.getLatitude() &&
			m_coords.getLongitude() == coords.getLongitude());
	INVARIANTS();
}

/**
 * \brief getter de description de l'objet station
 * \return le string de la description de la Station
 */
const std::string& Station::getDescription() const
{
	return m_description;
}

void Station::setDescription(const std::string& description)
{
	PRECONDITION(!(description.empty()));
	m_description = description;
	POSTCONDITION(m_description == description);
}

std::vector<Ligne*> Station::getLignesPassantes() const
{
	PRECONDITION(!(m_voyages_passants.empty()));

	std::vector<Ligne*> vectLigne = std::vector<Ligne*>();
	Voyage* tmp = m_voyages_passants[0];
	vectLigne.push_back(tmp->getLigne());

	for (std::vector<Voyage*>::const_iterator it = m_voyages_passants.begin();
			it != m_voyages_passants.end(); ++it)
	{
		if (tmp->getLigne()->getId() != (*it)->getLigne()->getId())
		{
			vectLigne.push_back((*it)->getLigne());
			tmp = *it;
		}
	}

	return vectLigne;
}

const std::string& Station::getNom() const
{
	return m_nom;
}

void Station::setNom(const std::string& nom)
{
	PRECONDITION(!(nom.empty()));
	m_nom = nom;
	POSTCONDITION(m_nom == nom);
}

unsigned int Station::getId() const
{
	return m_id;
}

void Station::setId(unsigned int stationId)
{
	m_id = stationId;
}

const std::vector<Voyage*>& Station::getVoyagesPassants() const
{
	return m_voyages_passants;
}

void Station::addVoyage(Voyage* ptr_voyage)
{
	m_voyages_passants.push_back(ptr_voyage);
	POSTCONDITION(!(m_voyages_passants.empty()));
}

double Station::distance(const Station& p_station) const
{
	return (this->getCoords() - p_station.getCoords());
}

void Station::verifieInvariant()
{
	INVARIANT(m_coords.is_valide_coord(m_coords.getLatitude(), m_coords.getLongitude()));
}
