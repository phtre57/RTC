/*
 * auxiliaires.cpp
 *
 *  Created on: 2016-09-20
 *      Author: etudiant
 */

#include <time.h>
#include <cmath>
#include <sstream>
#include <fstream>
#include "auxiliaires.h"
#include "ContratException.h"

std::vector<std::string> split(const std::string& s, char delim)
{
	std::istringstream is(s);
	std::string tmp;
	std::vector<std::string> vectTmp = std::vector<std::string>();
	while (std::getline(is, tmp, delim))
	{
		vectTmp.push_back(tmp);
	}

	return vectTmp;
}

void lireFichier(std::string nomFichier,
		std::vector<std::vector<std::string> >& resultats, char delimiteur,
		bool rm_entete)
{
	std::ifstream
}

/**
 * \brief constructeur par default d'une Date (construit la Date presente
 */
Date::Date()
{
	time_t genTime = time(NULL);
	struct tm* locTime = localtime(&genTime);
	m_an = locTime->tm_year + 1900;
	m_mois = locTime->tm_mon + 1;
	m_jour = locTime->tm_mday;
	POSTCONDITION(m_an == (unsigned int) locTime->tm_year + 1900);
	POSTCONDITION(m_mois == (unsigned int) locTime->tm_mon + 1);
	POSTCONDITION(m_jour == (unsigned int) locTime->tm_mday);
	INVARIANTS();
}

/**
 * \brief constructeur avec parametres d'une Date
 * \param[in] unsigned int d'une annee
 * \param[in] unsigned int d'un mois
 * \param[in] unsigned int d'un jour
 */
Date::Date(unsigned int an, unsigned int mois, unsigned int jour):
		m_an(an), m_mois(mois), m_jour(jour)
{
	PRECONDITION(validerDate(an, mois, jour));
	POSTCONDITION(m_an == an);
	POSTCONDITION(m_mois == mois);
	POSTCONDITION(m_jour == jour);
	INVARIANTS();
}

/**
 * \brief operator == sur deux objets Date
 * \param[in] un autre Date
 * \return un booleen
 */
bool Date::operator ==(const Date& other) const
{
	return (this->m_an == other.m_an and this->m_mois == other.m_mois and
			this->m_jour == other.m_jour);
}

/**
 * \brief operator < sur deux objets Date
 * \param[in] un autre Date
 * \return un booleen
 */
bool Date::operator <(const Date& other) const
{
	if (this->m_an < other.m_an)
	{
		return true;
	}

	if (this->m_an == other.m_an and this->m_mois < other.m_mois)
	{
		return true;
	}

	if (this->m_an == other.m_an and this->m_mois == other.m_mois and
			this->m_jour < other.m_jour)
	{
		return true;
	}

	else return false;
}

/**
 * \brief operator > sur deux objets Date
 * \param[in] un autre Date
 * \return un booleen
 */
bool Date::operator >(const Date& other) const
{
	if (this->m_an > other.m_an)
	{
		return true;
	}

	if (this->m_an == other.m_an and this->m_mois > other.m_mois)
	{
		return true;
	}

	if (this->m_an == other.m_an and this->m_mois == other.m_mois and
			this->m_jour > other.m_jour)
	{
		return true;
	}

	else return false;
}

/**
 * \brief operator << sur un objet Date
 * \param[in] un Date
 * \return un flux contenant les informations d'une Date
 */
std::ostream & operator<<(std::ostream & flux, const Date & p_date)
{
	flux << p_date.m_jour << "/" << p_date.m_mois << "/" << p_date.m_an;
	return flux;
}

/**
 * \brief verifie la validite d'une Date
 * \param[in] unsigned int d'une annee
 * \param[in] unsigned int d'un mois
 * \param[in] unsigned int d'un jour
 * \return true si la Date est valide, false si la Date n'est pas valide
 */
bool Date::validerDate(unsigned int p_an, unsigned int p_mois, unsigned int p_jour)
{
	if ((p_an % 400) == 0 and p_mois == 2 and p_jour > 29)
	{
		return false;
	}

	if ((p_an % 100) == 0 and p_mois == 2 and p_jour > 28)
	{
		return false;
	}

	if ((p_an % 4) == 0 and p_mois == 2 and p_jour > 29)
	{
		return false;
	}

	if ((p_an % 4) != 0 and p_mois == 2 and p_jour > 28)
	{
		return false;
	}

	if ((p_mois % 2) == 0 and p_jour > 30)
	{
		return false;
	}

	if ((p_mois % 2) != 0 and p_jour > 31)
	{
		return false;
	}

	else return true;
}

/**
 * \brief verifieInvariant d'une Date
 */
void Date::verifieInvariant()
{
	INVARIANT(validerDate(m_an, m_mois, m_jour));
}

/**
 * \brief contructeur par default d'un objet Heure. Construit l'Heure locale.
 */
Heure::Heure()
{
	time_t generalTime = time(NULL);
	struct tm* locTime = localtime(&generalTime);
	m_heure = locTime->tm_hour;
	m_min = locTime->tm_min;
	m_sec = locTime->tm_sec;
	POSTCONDITION(m_heure == (unsigned int) locTime->tm_hour);
	POSTCONDITION(m_min == (unsigned int) locTime->tm_min);
	POSTCONDITION(m_sec = (unsigned int) locTime->tm_sec);
	INVARIANTS();
}

/**
 * \brief Constructeur d'heure avec parametres
 * \param[in] unsigned int contenant l'heure (plus grand que 0 et plus petit que 30)
 * \param[in] unsigned int contenant les minutes (plus grand que 0 et plus petit que 60)
 * \param[in] unsigned int contenant les secondes (plus grand que 0 et plus petit que 60)
 */
Heure::Heure(unsigned int heure, unsigned int min, unsigned int sec):
		m_heure(heure), m_min(min), m_sec(sec)
{
	PRECONDITION(heure < 30 and heure >= 0);
	PRECONDITION(min < 60 and min >= 0);
	PRECONDITION(sec < 60 and min >= 0);
	POSTCONDITION(m_heure == heure);
	POSTCONDITION(m_min == min);
	POSTCONDITION(m_sec == sec);
	INVARIANTS();
}

/**
 * \brief ajoute les secondes mises en parametre a l'objet Heure
 * \param[in] unsigned int contenant des secondes
 * \return un objet Heure avec les secondes ajoutees
 */
Heure Heure::add_secondes(unsigned int secs) const
{
	unsigned int tmp = m_sec + secs;
	unsigned int sec = tmp % 60;
	tmp = tmp / 60;
	unsigned int tmp2 = m_min + tmp;
	unsigned int min = tmp2 % 60;
	tmp2 = tmp2 / 60;
	unsigned int heure = m_heure + tmp2;
	if (heure >= 30)
	{
		heure -= 30;
	}
	return Heure(heure, min, sec);

}

/**
 * \brief operator == sur deux objets Heure
 * \param[in] un autre Heure
 * \return un booleen
 */
bool Heure::operator ==(const Heure& other) const
{
	return (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec == other.m_sec);
}

/**
 * \brief operator < sur deux objets Heure
 * \param[in] une autre Heure
 * \return un booleen
 */
bool Heure::operator <(const Heure& other) const
{
	if (this->m_heure < other.m_heure)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min < other.m_min)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec < other.m_sec)
	{
		return true;
	}

	else return false;

}

/**
 * \brief operator > sur deux objets Heure
 * \param[in] une autre Heure
 * \return un booleen
 */
bool Heure::operator >(const Heure& other) const
{
	if (this->m_heure > other.m_heure)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min > other.m_min)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec > other.m_sec)
	{
		return true;
	}

	else return false;
}

/**
 * \brief operator <= sur deux objets Heure
 * \param[in] une autre Heure
 * \return un booleen
 */
bool Heure::operator <=(const Heure& other) const
{
	if (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec == other.m_sec)
	{
		return true;
	}

	if (this->m_heure < other.m_heure)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min < other.m_min)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec < other.m_sec)
	{
		return true;
	}

	else return false;
}

/**
 * \brief operator >= sur deux objets Heure
 * \param[in] une autre Heure
 * \return un booleen
 */
bool Heure::operator >=(const Heure& other) const
{
	if (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec == other.m_sec)
	{
		return true;
	}

	if (this->m_heure > other.m_heure)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min > other.m_min)
	{
		return true;
	}

	if (this->m_heure == other.m_heure and this->m_min == other.m_min and
			this->m_sec > other.m_sec)
	{
		return true;
	}

	else return false;
}

/**
 * \brief operator - sur deux objets Heure
 * \param[in] une autre Heure
 * \return retourne la difference entre les deux Heure en secondes
 */
int Heure::operator -(const Heure& other) const
{
	int thisSec = this->m_heure*3600 + this->m_min*60 + m_sec;
	int otherSec = other.m_heure*3600 + other.m_min*60 +
			other.m_sec;
	int result = (std::abs(thisSec - otherSec));
	return result;
}

/**
 * \brief operator << d'un objet Heure
 * \param[in] une Heure
 * \return un flux contenant les information d'une heure
 */
std::ostream & operator <<(std::ostream & flux, const Heure & p_heure)
{
	if (p_heure.m_min < 10 and p_heure.m_sec > 10)
	{
		flux << p_heure.m_heure << ":0" << p_heure.m_min <<  ":" <<
				p_heure.m_sec;
	}

	if (p_heure.m_sec < 10 and p_heure.m_min > 10)
	{
		flux << p_heure.m_heure << ":" << p_heure.m_min <<  ":0" <<
				p_heure.m_sec;
	}

	if (p_heure.m_sec < 10 and p_heure.m_min < 10)
	{
		flux << p_heure.m_heure << ":0" << p_heure.m_min <<  ":0" <<
				p_heure.m_sec;
	}

	if (p_heure.m_sec > 10 and p_heure.m_min > 10)
	{
		flux << p_heure.m_heure << ":" << p_heure.m_min <<  ":" <<
				p_heure.m_sec;
	}
	return flux;
}

/**
 * \brief verifieInvariant de la classe Heure
 */
void Heure::verifieInvariant()
{
	INVARIANT(m_heure < 30 and m_heure >= 0);
	INVARIANT(m_min < 60 and m_min >= 0);
	INVARIANT(m_sec < 60 and m_sec >= 0);
}
