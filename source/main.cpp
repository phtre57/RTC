/*
 * main.cpp
 *
 *  Created on: 2016-09-21
 *      Author: etudiant
 */

#include "coordonnees.h"
#include "station.h"
#include "auxiliaires.h"
#include "arret.h"
#include "util.h"
#include <time.h>
#include <sstream>
using namespace std;

int main()
{
	vector<vector<string>> vectStrArret;
	vector<Arret> vectArret = vector<Arret>();
	lireFichier("RTC/stop_times.txt", vectStrArret, ',', true);
	for (vector<vector<string>>::iterator it = vectStrArret.begin();
			it != vectStrArret.end(); ++it)
	{
		vectArret.push_back(Arret(*it));
	}

	vector<vector<string>> vectStrLigne;
	vector<Ligne> vectLigne = vector<Ligne>();
	lireFichier("RTC/routes.txt", vectStrLigne, ',', true);
	for (vector<vector<string>>::iterator it = vectStrLigne.begin();
			it != vectStrLigne.end(); ++it)
	{
		vectLigne.push_back(Ligne(*it));
	}

	vector<vector<string>> vectStrStation;
	vector<Station> vectStation = vector<Station>();
	lireFichier("RTC/stops.txt", vectStrStation, ',', true);
	for (vector<vector<string>>::iterator it = vectStrStation.begin();
			it != vectStrStation.end(); ++it)
	{
		vectStation.push_back(Station(*it));
	}

	vector<vector<string>> vectStrVoyage;
	vector<Voyage> vectVoyage = vector<Voyage>();
	lireFichier("RTC/trips.txt", vectStrVoyage, ',', true);
	for (vector<vector<string>>::iterator it = vectStrVoyage.begin();
			it != vectStrVoyage.end(); ++it)
	{
		string strTmp = it->front();
		unsigned int tmp = stoi(strTmp);

		for (vector<Ligne>::iterator it2 = vectLigne.begin();
				it2 != vectLigne.end(); ++it2)
		{
			if (tmp == it2->getId())
			{
				vectVoyage.push_back(Voyage(*it, &(*it2)));
			}
		}
	}

	cout << "Lignes de la RTC" << endl;
	cout << "Compte = " << vectLigne.size() << endl;
	util::separateur(20);
	cout << endl;
	for (vector<Ligne>::iterator it = vectLigne.begin();
			it != vectLigne.end(); ++it)
	{
		string tmp;
		if (it->getCategorie() == CategorieBus::LEBUS)
		{
			tmp = "LEBUS";
		}

		if (it->getCategorie() == CategorieBus::EXPRESS)
		{
			tmp = "EXPRESS";
		}

		if (it->getCategorie() == CategorieBus::METRO_BUS)
		{
			tmp = "METRO_BUS";
		}

		if (it->getCategorie() == CategorieBus::COUCHE_TARD)
		{
			tmp = "COUCHE_TARD";
		}
		cout << tmp << " " << it->getNumero() << " : " << it->getDescription()
				<< endl;
	}

	util::separateur(20);
	cout << endl;

	cout << "Stations de la RTC" << endl;
	cout << "Compte = " << vectStation.size() << endl;

	util::separateur(20);
	cout << endl;

	for (vector<Station>::iterator it = vectStation.begin();
			it != vectStation.end();  ++it)
	{
		cout << it->getId() << " - " << it->getNom() << endl;
	}

	util::separateur(20);
	cout << endl;

	cout << "Voyage de la journee du " << Date() << endl;
	cout << Heure() << " - " << Heure().add_secondes(3600) << endl;
	cout << "Compte = " << endl;

	util::separateur(20);
	cout << endl;

	return 0;
}


