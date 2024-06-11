#pragma once
#include <cmath>

namespace celestial{

#define PI 3.141592653589
#define m_orbitalSpeed(semimajor_axis, semiminor_axis, year) (semimajor_axis + semiminor_axis) * PI / (year * 365) / 24 / 60 / 60 * (1.5 * pow(10, 8))

#define m_orbitalSpeed2(orbital_dist, year) orbital_dist * 2 * PI / (year * 365) / 24 / 60 / 60 * (1.5 * pow(10, 8))

//Calculate orbital speed in km/s
int cspeed(int semimajor_axis, int semiminor_axis, int year){

 return  m_orbitalSpeed(semimajor_axis, semiminor_axis, year);
  

}
//Calculate orbital speed in km/s
int cspeed(int avg, int year){

 return  m_orbitalSpeed2(avg, year);

}

//Kepler's 3rd law
#define _kepler1__(t, r) (pow(t, 2) / pow(r, 3))
#define _kepler2__(t, a) cbrt((pow(t, 2) * a))
#define _kepler3__(r, a) sqrt((pow(r, 3) * a))

//Kepler's 3rd law!
int c_dst(int time, int star_m, bool r_days){

  if(!r_days){
    return _kepler2__(time, star_m);
  } else {
    return _kepler2__(time, star_m) * 365;
    
  }


}

int c_dst(int time, int radius){
    return _kepler1__(time, radius);
}

int c_dst(int radius, int star_m, int r_days){

  if(!r_days){
    return _kepler3__(radius, star_m);
  } else {
    return _kepler3__(radius, star_m) * 365;
    
  }


}

#define __c_km_au(d) (d * 1.5 * pow(10, 8))
#define __c_au_km(d) (d / 1.5 * pow(10, 8))


class STAR{

public:

  int mass;
  int magnitude;
  int distance;

  STAR(int MASS, int MAGNITUDE, int DISTANCE){
    mass = MASS;
    magnitude = MAGNITUDE;
    distance = DISTANCE;
  }

};


class PLANET{

public:

  STAR parent;
  int mass;
  int distance;

};

STAR THE_SUN(1, -26, 1);








}
