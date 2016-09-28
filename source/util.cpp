/*
 * util.cpp
 *
 *  Created on: 2016-09-21
 *      Author: etudiant
 */

#include "util.h"
#include <iostream>

namespace util
{

bool isLatitude(double p_latitude)
{
	if (p_latitude <= 90 && p_latitude >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isLongitude(double p_longitude)
{
	if (p_longitude <= 180 && p_longitude >= -180)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void separateur(int nbrSeparateur)
{
	for (int i = 0; i < nbrSeparateur; i++)
	{
		std::cout << "=";
	}
}

}


