/*
 * util.cpp
 *
 *  Created on: 2016-09-21
 *      Author: etudiant
 */

#include "util.h"

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

}


