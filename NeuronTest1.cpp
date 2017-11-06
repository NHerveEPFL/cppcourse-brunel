#include <iostream>
#include "Neuron.hpp"
#include <fstream>



int main()
{
/* the test creats a Neuron, a Input current I and a time stop that indicates
when to end the experiment */
	Neuron jimmy;
	size_t t_stop(5000);
	double I(1.01);
	bool S(false);

	std::ofstream out;
	out.open("neuronTest1.txt");

	for ( size_t time=0; time<t_stop; ++time)
	{
/** does a update and return true if a spike occured */
		S = jimmy.update(I, 0);
		out << jimmy.getPot() << std::endl;
	}

	std::cout << std::endl << "Number of spikes = " << jimmy.getSpikes()
						<< std::endl;

	out.close();

	return 0;
}
