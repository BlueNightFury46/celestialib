#pragma once
#include <cmath>

namespace celestial{

#define PI 3.141592653589
#define m_orbitalSpeed(semimajor_axis, semiminor_axis, year) (semimajor_axis + semiminor_axis) * PI / (year * 365) / 24 / 60 / 60 * (1.5 * pow(10, 8))
#define Boltzmann_const 0.0000000567

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

//Returns the orbital distance of the planet
int c_dst(int time, int star_m, bool r_days){

  if(!r_days){
    return _kepler2__(time, star_m);
  } else {
    return _kepler2__(time, star_m) * 365;
    
  }


}

//Returns the mass of the orbiting star in Solar masses
int c_dst(int time, int radius){
    return _kepler1__(time, radius);
}

//Calculate the orbital period of the planet, if r_days is true return the value in Earth days
int c_dst(int radius, int star_m, int r_days){

  if(!r_days){
    return _kepler3__(radius, star_m);
  } else {
    return _kepler3__(radius, star_m) * 365;
    
  }


}

#define __c_km_au(d) (d * 1.5 * pow(10, 8))
#define __c_au_km(d) (d / 1.5 * pow(10, 8))

//Convert KM to AU
int km_to_au(int km){
  return __c_km_au(km);
}

//Convert AU to KM
int au_to_km(int au){
  return __c_au_km(au);
}

#define __lu_1__i(R, T) 4 * PI * pow(R, 2) * Boltzmann_const * pow(T, 4) / pow(10, 15)
#define __lu_1__s(num) num / 383414.05

//Takes in a radius (in Solar radii) and a temperature (in Kelvin) and returns the Luminosity in Solar Luminosities
double c_luminosity(double Radius, double Temperature){

  return __lu_1__s(__lu_1__i(Radius, Temperature));

}


class STAR{

public:

  double mass;
  double magnitude;
  double distance;
  double radius;
  double temperature;

  STAR(int MASS, int MAGNITUDE, int DISTANCE, int RADIUS, int TEMPERATURE){
    mass = MASS;
    magnitude = MAGNITUDE;
    distance = DISTANCE;
    radius = RADIUS;
    temperature = TEMPERATURE;
  }

  STAR(int MASS, int MAGNITUDE, int DISTANCE, int RADIUS){
    mass = MASS;
    magnitude = MAGNITUDE;
    distance = DISTANCE;
    radius = RADIUS;
  }


  STAR(){
    mass = 0;
    magnitude = 0;
    distance = 0;
    radius = 0;
    temperature = 0;

  }

};


class PLANET{

public:

  STAR parent;
  int mass;
  int distance;

};

STAR THE_SUN(1, -26.7, 1, 1);

//Takes in a star and returns it's Luminosity if the temperature and radius are set!
double c_luminosity(STAR star){

  if(star.temperature == 0){
    return 0;
  } 

  if(star.radius == 0){
    return 0;
  }

  return __lu_1__s(__lu_1__i(star.radius, star.temperature));

}








}
