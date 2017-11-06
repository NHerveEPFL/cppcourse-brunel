#include <iostream>
#include "Neuron.hpp"
#include <fstream>
#include "Network.hpp"




int main()
{
  Neuron n1;
  Neuron n2;

  unsigned long t_stop(4000);
  double I(1.01);

  bool n1Spike(false);
  bool n2Spike(false);


  std::ofstream outN;
  outN.open("neuron1Test2.txt");


  std::ofstream outH;
  outH.open("neuron2Test2.txt");



  for ( unsigned long time=0; time<t_stop; ++time)
  {
    n1Spike = n1.update(I, 0);
    outN << "at " << n1.getNeuron_clock() << " ms -> " << n1.getPot()
         << std::endl;



    n2Spike = n2.update(0.0, 0);
    outH << "at " << n2.getNeuron_clock() << " ms -> " << n2.getPot()
         << std::endl;


    if (n1Spike)
    {
      n2.addDelayed_weight(0.2, n1.getDelay(),n1.getNeuron_clock());
    }
  }


/*
  for (size_t i(0); i < N.getTimes_spikes().size(); ++i)
  {
      std::cout << N.getTimes_spikes()[i] << std::endl;
  }
*/

  outH.close();
  outN.close();


}
