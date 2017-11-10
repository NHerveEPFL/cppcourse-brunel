#include "Network.hpp"




Network::Network(int N, double g, double eta)
: N_(N), g_(g), eta_(eta)
{
  out_.open("NetworkTest.txt");

  std::random_device rd;  //used to obtain a seed for the random number engine
  gen = std::mt19937(rd());
  double V = (20*eta_)/(0.1*20);
  d = std::poisson_distribution<unsigned int>(V*0.1);

// creates the neuron list
  for (size_t i(0); i < Ne_+Ni_; ++i)
  {
    Neurons_.push_back(new Neuron);
  }

  std::random_device rd1;  //used to obtain a seed for the random number engine
  std::mt19937 gen1(rd1()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis1(0, Ne_-1);
  //-> table begins at 0 and ends at Ne-1 for exitatory

  std::random_device rd2;  //used to obtain a seed for the random number engine
  std::mt19937 gen2(rd2()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis2(Ne_, Ne_+Ni_-1);
  //-> table begins at Ne and ends at Ne+Ni-1 for inhibitory

  for (size_t target(0); target < Neurons_.size(); ++target) //-> for all neurons
  {
    for (int i(0); i < Ce_; ++i) //-> randomly create Ce_ exitatory neuron connections
    {
      Neurons_[dis1(gen1)]->connect(target); //-> target becomes a target for dis1(gen1)
    }
    for (int j(0); j < Ci_; ++j) //-> randomly create Ci_ inhibitory neuron connections
    {
      Neurons_[dis2(gen2)]->connect(target);
    }
  }
}



Network::~Network()
  {
    for ( auto& neuron : Neurons_ )
    {
      neuron = nullptr;
      delete neuron;
    }

    out_.close();
  }



void Network::Interaction(const Neuron& n, const double& J) const
{
  for (auto& j : n.getTargets())
  {
      Neurons_[j]->addDelayed_weight(J, n.getDelay(), n.getNeuron_clock());
  }
}



void Network::update(const double& I)
{

  for (size_t i(0); i < Neurons_.size(); ++i)  //-> go through neuron list
  {
    if (Neurons_[i]->update(I, d(gen))) //-> check if spike + update
    {
      out_ << Neurons_[i]->getNeuron_clock() << '\t' << i << '\n';
      if (i < Ne_)
      { Interaction(*Neurons_[i], Je_); }
      else
      { Interaction(*Neurons_[i], Je_*(-g_)); }
    }
  }
}



std::vector<Neuron*> Network::getNeurons() const
{ return Neurons_; }
