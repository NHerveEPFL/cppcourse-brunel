# cppcourse-brunel
c++ project on Neurons 2017


What is it ?
------------
A simulation programm of a really small network of neurons based on Nicolas Brunnel's article "Dynamics of Sparsely Connected Networks of Excitatory and Inhibitory Spiking Neurons" December 23 1998.
The simulation returns the spikes each neuron emits and at which time for a defined duration


How to install
--------------
- Download files in a single folder
- Add a 'googletest' folder dowloaded from github to run gtests
- Add a 'build' folder
- Create a cmake file inside the 'build' folder
- Compile with cmake and run inside 'build', run commands :

```
./NetworkTest -> main simulation
./NeuronTest1
./NeuronTest2
./unittest1
```


How to use the program
----------------------
- run with './NetworkTest' command inside a terminal in 'build'
- You will be asked if you want a default simulation, type 'y' or 'n'
```
**default simulation**
Simulation time = 100.0 ms
Number of neurons = 12500
Relative strengh of inhibitory synapse : g = 5
Variable for poisson parameter : eta = 2
```
- For none default simulation you will have to choose a simulation time, a number of neurons, a g value and a eta value
- The program creates a NeuronTest.txt file inside 'build' were you can view the results. If you need an other type of file change the file name inside the Network constructor in 'Network.cpp' (first line of the constructor).
- Download 'NeuronTest.txt' on a Jupyther plot creator or any other plot creator to view the results as a plot.

The 3 tests
-----------
**'NeuronTest1.cpp' and NeuronTest2' counts in steps while 'NeuronTest3' is implemented in miliseconds**
- ./NeuronTest1 : 'NeuronTest1.cpp' tests one neuron with a input current of 1.01 (but no poisson probability) on 5000 steps. It returns the number of spikes that occured and creates 'NeuronTest1.txt which shows the membrane potential of the neuron at each step.
- ./NeuronTest2 : 'NeuronTest2.cpp' tests the program with 2 neurons with 1 connection. It creates two files, 'Neuron1Test2.txt' and Neuron2Test2.txt, which shows the membrane potential at every step.
- ./unittest1 : runs a serie of gtests

examples of simulations
-----------------------
**These simulations were done on the computers in CO5 on the SV vWorkspace**

N_ = 12500, simulation_time = 100.0 ms, g_ = 3, eta_ = 2 -> runs for 18.98 seconds


N_ = 12500, simulation_time = 200.0 ms, g_ = 6, eta_ = 4 -> runs for 39.83 seconds 


N_ = 12500, simulation_time = 200.0 ms,  g_ = 5, eta_ = 2 -> runs for 25.88 seconds 


N_ = 12500, simulation_time = 200.0 ms, g_ = 4.5, eta_ = 0.9 -> runs for 15.19 seconds





