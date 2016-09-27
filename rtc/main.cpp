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
#include <time.h>
#include <sstream>
using namespace std;

int main()
{
	Coordonnees coord1 = Coordonnees(50, 100);
	Coordonnees coord2 = Coordonnees(10, -100);

	vector<string> vect1 = vector<string>();
	vect1.push_back("4955");
	vect1.push_back("M.-Gros-Louis");
	vect1.push_back("de la Colline / Chef M.-Gros-Louis");
	vect1.push_back("46.877662");
	vect1.push_back("-71.361829");

	vector<string> vect2 = vect1;
	vect2.pop_back();
	vect2.push_back("71.361829");

	Station station1 = Station(vect1);
	Station station2 = Station(vect2);

	Heure heure1 = Heure();
	Heure heure2 = heure1.add_secondes(120);
	Date date1 = Date();
	Date date2 = Date(2016, 9, 26);

	string test1 = "07:01:05";
	istringstream is = istringstream(test1);
	string segment;
	vector<string> vectTest;
	while (getline(is, segment, ':'))
	{
		vectTest.push_back(segment);
	}

	vector<string> vect3 = vector<string>();
	vect3.push_back("48420598-20162511multiint-0000010");
	vect3.push_back("07:01:00");
	vect3.push_back("07:01:00");
	vect3.push_back("3878");
	vect3.push_back("20010");
	Arret arr1 = Arret(vect3);
	cout << arr1.getHeureArrivee() << endl;

}


