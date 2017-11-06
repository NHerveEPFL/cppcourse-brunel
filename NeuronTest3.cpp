#include <iostream>
#include "Network.hpp"

int main()
{
  double simulation_time(100.0); //-> in ms
  int simulation_steps(simulation_time*10);

  Network myBrain; //-> default network creation

  for(int i(0); i < simulation_steps; ++i)
  {
    myBrain.update(0.0);
  }

  return 0;
}


/* file << spike_time << '\t' << neuron_id(=#neurons) << '\n';
target[gid][tid] (=neuron number and target neuron)
you need a list of target for each neuron
create function connect to create list which you can implement in Network
# <cassert>
Doxygen :  //!< comment
don't forget eta (=2.0)

*/
