#include "Ocean.h"
#include <iostream>

using namespace CS170::WarBoats;

int main() {
  int num_boats = 3;
  int xsize = 8;
  int ysize = 8;
  CS170::WarBoats::Ocean *theOcean;
  theOcean = CS170::WarBoats::CreateOcean(num_boats, xsize, ysize);
  CS170::WarBoats::Ocean &ocean = *theOcean;

  std::cout << "The empty board" << std::endl;
  CS170::WarBoats::DumpOcean(ocean);
  std::cout << std::endl;

  CS170::WarBoats::Boat boat;
  CS170::WarBoats::Point location;
  CS170::WarBoats::BoatPlacement bp;

    // Boat #1
  boat.ID = 1;
  location.x = 1;
  location.y = 3;
  boat.position = location;
  boat.orientation = CS170::WarBoats::oHORIZONTAL;
  bp = CS170::WarBoats::PlaceBoat(ocean, boat);
  if (bp == CS170::WarBoats::bpREJECTED)
    std::cout << "Boat placement is rejected." << std::endl;
  else
    std::cout << "Boat placement is accepted." << std::endl;

    // Boat #2
  boat.ID = 2;
  location.x = 5;
  location.y = 1;
  boat.position = location;
  boat.orientation = CS170::WarBoats::oVERTICAL;
  bp = CS170::WarBoats::PlaceBoat(ocean, boat);
  if (bp == CS170::WarBoats::bpREJECTED)
    std::cout << "Boat placement is rejected." << std::endl;
  else
    std::cout << "Boat placement is accepted." << std::endl;

    // Boat #3
  boat.ID = 3;
  location.x = 0;
  location.y = 5;
  boat.position = location;
  boat.orientation = CS170::WarBoats::oHORIZONTAL;
  bp = CS170::WarBoats::PlaceBoat(ocean, boat);
  if (bp == CS170::WarBoats::bpREJECTED)
    std::cout << "Boat placement is rejected." << std::endl;
  else
    std::cout << "Boat placement is accepted." << std::endl;

    // Illegal placement
  boat.ID = 4;
  location.x = 10;
  location.y = 5;
  boat.position = location;
  boat.orientation = CS170::WarBoats::oHORIZONTAL;
  bp = CS170::WarBoats::PlaceBoat(ocean, boat);
  if (bp == CS170::WarBoats::bpREJECTED)
    std::cout << "Boat placement is rejected." << std::endl;
  else
    std::cout << "FAILURE" << std::endl;

    // Illegal placement
  boat.ID = 4;
  location.x = 2;
  location.y = 0;
  boat.position = location;
  boat.orientation = CS170::WarBoats::oVERTICAL;
  bp = CS170::WarBoats::PlaceBoat(ocean, boat);
  if (bp == CS170::WarBoats::bpREJECTED)
    std::cout << "Boat placement is rejected." << std::endl;
  else
    std::cout << "FAILURE" << std::endl;

      // Illegal placement
  boat.ID = 4;
  location.x = 5;
  location.y = 6;
  boat.position = location;
  boat.orientation = CS170::WarBoats::oHORIZONTAL;
  bp = CS170::WarBoats::PlaceBoat(ocean, boat);
  if (bp == CS170::WarBoats::bpREJECTED)
    std::cout << "Boat placement is rejected." << std::endl;
  else
    std::cout << "Failure" << std::endl;

  std::cout << "The board with " << num_boats << " boats" << std::endl;
  CS170::WarBoats::DumpOcean(ocean, 4, true);
  std::cout << std::endl;
  CS170::WarBoats::DestroyOcean(theOcean);

    return 0;
}