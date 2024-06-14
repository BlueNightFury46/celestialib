# Celestialib
 Celestialib is a small open-source C++ project I made 
 which provides some Astronomy equations and functions

 ## cspeed 
> cspeed is a function that calculates the orbital speed of a planet, given the semiminor-axis, semimajor-axis and year (it also works with just the average distance from the star and year), the semimajor and semiminor axes are in AU and the year is in Earth years
> int cspeed(int semimajor-axis, int semiminor-axis, int year) 


 ## c_dist
> c_dist is an implementation of Kepler's 3rd law and has 3 different variations in c_dist:
>
### int c_dst(int time, int star_m, bool r_days) - returns semimajor axis of orbit (AU)
> takes in the time, mass of the parent star and a boolean which indicates whether to use days, or years. (true means use days, false means use years)
>
>> ### int c_dst(int radius, int star_m, int r_days) - returns orbital period 
> takes in the radius of the orbit (semimajor axis), mass of the star and a boolean which decides whether to use days, or years. (true means use days, false means use years)
>
### int c_dst(int time, int radius) - returns the mass of the parent star (solar masses)
> takes in the orbital period in Earth years and the radius of the orbit in AU

## c_luminosity
> double c_luminosity(double Radius, double Temperature)<br>
> takes in the Radius of the star (in Solar Radii), surface Temperature (Kelvin) and returns the Solar Luminosity of the star relative to the Sun.
>
> Accepts a STAR object and returns 0 if any of the required fields (Temperature, Radius) are missing.
