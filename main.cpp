#include <iostream>
#include "astro/celestialib.h"

int main (int argc, char *argv[]) {

  celestial::STAR polaris;

  //polaris.temperature = 6015;
  //polaris.radius = 37.5;

  std::cout << celestial::c_luminosity(polaris);
  
  return 0;
}
