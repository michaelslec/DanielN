#include "WarBoats.h"
#include "Ocean.h"
#include <iostream> // cout, endl
#include <iomanip>  // setw

namespace CS170
{
  namespace WarBoats
  {
    const int BOAT_LENGTH = 4;  //!< Length of a boat
    const int HIT_OFFSET = 100; //!< Add this to the boat ID

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE 
     */

    // int int int -> Ocean*
    Ocean *CreateOcean(int num_boats, int x_quadrants, int y_quadrants)
    {
      Ocean *temp = new Ocean;

      temp->num_boats = num_boats;
      temp->boats = new Boat[num_boats];
      temp->x_quadrants = x_quadrants;
      temp->y_quadrants = y_quadrants;
      temp->grid = new int[x_quadrants * y_quadrants];

      return temp;
    }

    // Ocean -> SIDE EFFECTS
    // Takes an ocean and free's all associated memory
    void DestroyOcean(Ocean *theOcean)
    {
      delete[] theOcean->boats;
      delete[] theOcean->grid;
      delete theOcean;
    }

    // Ocean Boat -> BoatPlacement
    // Returns whether or not boat was place in an acceptable location
    // SIDE EFFECT: places boat on board
    BoatPlacement PlaceBoat(Ocean &ocean, const Boat &boat)
    {
      if (boat.orientation == oHORIZONTAL)
      {
        if ((boat.position.x + BOAT_LENGTH - 1) >= ocean.x_quadrants)
          return bpREJECTED;

        // Horizontal
        for (int i = 0; i < BOAT_LENGTH; i++)
        {
          //                     Vertical displacement in array       horizontal displacement
          size_t start_position = (boat.position.y * ocean.x_quadrants) + boat.position.x;
          if (ocean.grid[start_position + i] != dtOK)
          {
            return bpREJECTED;
          }
        }
      }
      else
      {
        if ((boat.position.y + BOAT_LENGTH - 1) >= ocean.y_quadrants)
          return bpREJECTED;

        // Horizontal
        for (int i = 0; i < BOAT_LENGTH; i++)
        {
          size_t index = (boat.position.y + i) * ocean.x_quadrants + boat.position.x;
          if (ocean.grid[index] != dtOK) {
            return bpREJECTED;
          }
        }
      }

      if (boat.orientation == oHORIZONTAL) {
        for (int i = 0; i < BOAT_LENGTH; ++i) {
          size_t start_position = (boat.position.y * ocean.x_quadrants) + boat.position.x;
          ocean.grid[start_position + i] = boat.ID;
        }
      } else {
        for (int i = 0; i < BOAT_LENGTH; ++i) {
          size_t index = (boat.position.y + i) * ocean.x_quadrants + boat.position.x;
          ocean.grid[index] = boat.ID;
        }
      }

      return bpACCEPTED;
    }
    //ocean: ocean object
    //coordinate: spot in the ocean we want to hit
    //Side Effects: Changes a point on the ocean board as well as
    //the game's statistics.
    ShotResult TakeShot(Ocean &ocean, const Point &coordinate)
    {
      //checking if the coordinate is valid
      if (coordinate.x < 0 || coordinate.y < 0 ||
          coordinate.x >= ocean.x_quadrants || coordinate.y >= ocean.y_quadrants)
        //the coordinate was out of bounds
        return srILLEGAL;
      
      //point in the ocean
      //coordinate.y * ocean.x_quadrants moves the point down each row, while
      //adding coordinate.x moves the point along the row.
      int point = coordinate.y * ocean.x_quadrants + coordinate.x;
      
      //if they hit an empty spot on the ocean
      if (ocean.grid[point] == dtOK)
      {
        //change the point on the grid to blown up
        ocean.grid[point] = dtBLOWNUP;
        //increment number of times they missed
        ocean.stats.misses++;
        //they missed
        return srMISS;
      }
      //boat IDs range from 1 to 99, so checking if the point is a boat segment.
      else if (ocean.grid[point] > dtOK && ocean.grid[point] < HIT_OFFSET)
      {
        //increment the counter for number of hits the particular boat has taken
        //doing -1 in the subcript as it's zero-based, so boat #5 is 4 in the array
        ocean.boats[ocean.grid[point]-1].hits++;
        //increment the number of hits
        ocean.stats.hits++;
        
        //if all segments of the boat have been hit.
        //doing -1 in the subcript as it's zero-based, so boat #5 is 4 in the array
        if(ocean.boats[ocean.grid[point]-1].hits == BOAT_LENGTH)
        {
          //adding the hit offset to the boat segment
          ocean.grid[point] += HIT_OFFSET;
          //increment the number of boats sunken
          ocean.stats.sunk++;
          //the boat will be sunken
          return srSUNK;
        }
        
        //adding the hit offset to the boat segment
        ocean.grid[point] += HIT_OFFSET;
        //they hit a boat piece, but didn't sink the boat
        return srHIT;
      }
      //if they hit a spot that has already been hit
      else if (ocean.grid[point] == dtBLOWNUP || ocean.grid[point] > HIT_OFFSET)
      {
        //increment number of times they've made a duplicate shot
        ocean.stats.duplicates++;
        //it's a duplicate
        return srDUPLICATE;
      }
      
      return srILLEGAL;
    }
    
    //ocean: the ocean object whose statistics we want
    ShotStats GetShotStats(const Ocean &ocean)
    {
      return ocean.stats;
    }
    /**************************************************************************/
    /*!
      \brief
        Prints the grid (ocean) to the screen.
      
      \param ocean
        The Ocean to print
      
      \param field_width
        How much space each position takes when printed.
      
      \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.
        
      \param showboats
        If true, the boats are shown in the output. (Debugging feature)
    */
    /**************************************************************************/
    void DumpOcean(const CS170::WarBoats::Ocean &ocean,
                   int field_width,
                   bool extraline,
                   bool showboats)
    {
      // For each row
      for (int y = 0; y < ocean.y_quadrants; y++)
      {
        // For each column
        for (int x = 0; x < ocean.x_quadrants; x++)
        {
          // Get value at x/y position
          int value = ocean.grid[y * ocean.x_quadrants + x];

          // Is it a boat that we need to keep hidden?
          if ((value > 0) && (value < HIT_OFFSET) && (showboats == false))
            value = 0;

          std::cout << std::setw(field_width) << value;
        }
        std::cout << std::endl;
        if (extraline)
          std::cout << std::endl;
      }
    }

  } // namespace WarBoats
} // namespace CS170
