# cppcourse-brunel
c++ project on Neurons 2017


What is it ?
------------
A simulation programm of a really small network of neurons (originally 12500 neurons,can be changed , see below) based on Nicolas Brunnel's article "Dynamics of Sparsely Connected Networks of Excitatory and Inhibitory Spiking Neurons" December 23 1998.
The simulation returns the spikes each neuron emits and at which time for a defined duration


How to install
--------------
- Download files in a single folder
- Add a 'googletest' folder dowloaded from github if you want to use the gtests
- Add a 'build' folder
- Create a cmake file inside the 'build' folder
- Compile and run inside 'build', run command : ./Neuron


How to use the program
----------------------
- run with './Neuron' command inside a terminal in 'build'
- you can change the quantity of Neurons inside your Network by changing the const value N_ in 'Network.hpp', N_ should always be a mutiple of 5 (see Ne_ and Ni_ in 'Network.hpp).
- you can change the simulation time inside 'NeuronTest3', the simulation time is in miliseconds, if you only have the number of steps, divide it by 10, that should give you your simulation time in miliseconds.
- the background noise is used by simulating a poisson distribution, it's parameter is defined by a calculation that uses eta_ as a variable. eta_ can be changed inside 'Network.hpp'.
- g_ defines the relative strengh of inhibitory synapse and can be modified in 'Network.hpp'.
- the program creates a NeuronTest.txt file inside 'build' were you can view the results, if you need an other type of file change the file name inside the Network constructor in 'Network.cpp' (first line of the constructor).
- Download NeuronTest.txt on a Jupyther plot creator or any other plot creator to view the results as plot.


examples of simulations
-----------------------

N_ = 12500, simulation_time = 100.0 ms, eta_ = 2, g_ = 3
runs for seconds 12.26 seconds

N_ = 12500, simulation_time = 200.0 ms, eta_ = 4, g_ = 4
runs for 22.28 seconds 

N_ = 12500, simulation_time = 200.0 ms, eta_ = 2, g_ = 5
runs for 15.59 seconds 

N_ = 12500, simulation_time = 200.0 ms, eta_ = 0.9, g_ = 4.5
runs for seconds 9.45




