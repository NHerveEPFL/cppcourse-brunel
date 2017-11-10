#include <iostream>
#include "Network.hpp"


// -> checks if the user wants a default or a personal simulation
bool DefaultSimulation();


int main()
{
  double simulation_time(200.0); //-> in ms
  int simulation_steps;

  if (DefaultSimulation())
  {
      Network myBrain; //-> default network creation

      simulation_steps = simulation_time*10;

      for(int i(0); i < simulation_steps; ++i)
      {
        myBrain.update(0.0);
      }
  }
  else
  {
    int N;
    double g, eta;

    std::cout << "Simulation time ? (in ms) : ";
    std::cin >> simulation_time;

    std::cout << "How many neurons ? (multiple of 5): ";
    std::cin >> N;

    std::cout << "g value ? : ";
    std::cin >> g;

    std::cout << "eta value ? : ";
    std::cin >> eta;

    Network myBrain(N, g, eta); //-> specific network creation

    simulation_steps = simulation_time*10;

    for(int i(0); i < simulation_steps; ++i)
    {
      myBrain.update(0.0);
    }
  }

  return 0;
}





bool DefaultSimulation()
{
  bool def(false);
  char response('a');

  while (response != 'y' and response != 'n')
  {
    std::cout << "Do you want a default simulation ? (y/n) : ";
    std::cin >> response;
  }

  if (response == 'y')
  { def = true; }

  return def;
}


/* file << spike_time << '\t' << neuron_id(=#neurons) << '\n';
target[gid][tid] (=neuron number and target neuron)
you need a list of target for each neuron
create function connect to create list which you can implement in Network
# <cassert>
Doxygen :  //!< comment
don't forget eta (=2.0)

*/
