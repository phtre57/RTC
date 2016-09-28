
/*
 * coordonnees.cpp
 *
 *  Created on: 2016-09-20
 *      Author: etudiant
 */

#include "coordonnees.h"
#include <cmath>
#include "ContratException.h"
#include "util.h"

/**
 *\ brief Constructeur de base de la classe Coordonnees
 *\ param[in] latitude format double en 0 et 90
 *\ param[in] longitude format double entre -180 et 180
 */
Coordonnees::Coordonnees(double latitude, double longitude):
	m_latitude(latitude), m_longitude(longitude)
{
	PRECONDITION(util::isLatitude(latitude));
	PRECONDITION(util::isLongitude(longitude));
	POSTCONDITION(m_latitude == latitude);
	POSTCONDITION(m_longitude == longitude);
	INVARIANTS();
}

/**
 * \brief Obtenir l'attribut latitude de l'objet Coordonnees
 * \return double de la latitude
 */
double Coordonnees::getLatitude() const
{
	return m_latitude;
}

/**
 * \brief setter de la latitude pour un objet Coordonnees
 * \param[in] double de latitude compris entre 0 et 90
 */
void Coordonnees::setLatitude(double latitude)
{
	PRECONDITION(util::isLatitude(latitude));
	m_latitude = latitude;
	POSTCONDITION(util::isLatitude(m_latitude));
	INVARIANTS();
}

/**
 * \brief getter de la longitude d'un objet Coordonnees
 * \return double de l'attribut longitude de l'objet Coordonnees
 */
double Coordonnees::getLongitude() const
{
	return m_longitude;
}

/**
 * \brief setter de longityde d'un objet Coordonnees
 * \param[in] double de longitude compris entre -180 et 180
 */
void Coordonnees::setLongitude(double longitude)
{
	PRECONDITION(util::isLongitude(longitude));
	m_longitude = longitude;
	POSTCONDITION(util::isLongitude(m_longitude));
	INVARIANTS();
}

/**
 * \brief verifie si les coordonnes sont valide
 * \param[in] double latitude et un double longitude
 * return true si les coordonnees sont valide et inversement false
 */
bool Coordonnees::is_valide_coord(double p_latitude, double p_longitude)
{
	if (util::isLatitude(p_latitude) && util::isLongitude(p_longitude))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * \brief surcharge de l'operator moins sur des objets coordonees. Donne la distance entre 2 points.
 * \param[in] un autre coordonnees
 * return la distance entre deux coordonnees
 */
double Coordonnees::operator -(const Coordonnees& other) const
{
	double latRad = (this->getLatitude()*M_PI) / 180;
	double longRad = (this->getLongitude()*M_PI) / 180;
	double other_latRad = (other.getLatitude()*M_PI) / 180;
	double other_longRad = (other.getLongitude()*M_PI) / 180;
	double radius = 6371; //en km
	double distance = 0; //en km

	double part1 = (other_latRad - latRad) / 2;
	double part2 = pow(sin(part1), 2);
	double part3 = (other_longRad - longRad) / 2;
	double part4 = pow(sin(part3), 2);
	double part5 = part2 + cos(latRad)*cos(other_latRad)*part4;
	double part6 = sqrt(part5);
	double part7 = asin(part6);
	distance = 2*radius*part7;

	return distance;
}

/**
 * \brief verifie les invariants de l'objet
 */
void Coordonnees::verifieInvariant()
{
	INVARIANT(util::isLatitude(m_latitude));
	INVARIANT(util::isLongitude(m_longitude));
}


/**
 * \brief surcharge de l'operateur << sur un objet Coordonnees
 * \return le flus contenant les informations d'une coordonnees
 */
std::ostream & operator<<(std::ostream & flux, const Coordonnees & p_coord)
{
	flux << "Latitude: " << p_coord.getLatitude() << ", " << "Longitude: " <<
			p_coord.getLongitude();
	return flux;
}


