#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "Neuron.hpp"
#include <vector>
#include <fstream>
#include <random>


class Network
{

private:

  //-----------------------attributes--------------------
  const unsigned int N_ = 12500; //!< number of neurons

  const unsigned int Ni_ = N_/5;   //!< number of inhibitory neurons
  const unsigned int Ne_ = 4*Ni_; //!< number of exitatory neurons

  const int Ci_ = Ni_/10; //!< number of inhibitory connections for 1 neuron
  const int Ce_ = Ne_/10; //!< number of exitatory connections for 1 neuron

  const double g_ = 5; //!< Ji/Je
  const double Je_ = 0.1; //!< weight send by exitatory neuron

  const double eta_ = 2;//!< parameter for a poisson distribution


  std::vector<Neuron*> Neurons_;
  /*!
   * @brief : table that contains all neurons, the first Ne_(10000) are exitatory,
   * the next Ni_(2500) are inhibitory
   * Notice that to access a specific neuron n you need to choose n-1 !
   */

  std::ofstream out_; //!< output to create NeuronTest.txt file that contains time and neuron indicator when a spike happens

  std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
  std::poisson_distribution<unsigned int> d;  //-> table begins at 0 and ends at Ne-1 for exitatory


public:

  Network();
  /*!
   * @brief : implement Neurons_ with Ne_ exitatory neurons and Ni_ inhibitory
   * neurons randomly + create Ce_ and Ci_ connections between neurons
   */

  ~Network();


  void update(const double& I);
  /*!
   * @brief : updates the Network by 1 step
   * @param I : input current
   */


  void Interaction(Neuron n, const double& J) const;
  /*!
   * @brief : send delayed weight to all target neurons
   * @param n : the neuron that will send the weight to all targets
   * @param J : weight that will be send (Je_ or Ji_)
   */

  std::vector<Neuron*> getNeurons();

};


#endif
