#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>
#include <cmath>
#include <cstddef>  //-> is needed on SV workspace to use size_t


class Neuron
{


private:

//----------- attributes ----------------------


/** the membrane potential V_ depends of a Input_current and is always
 reset to a reset potential (V_res_) when it reaches the firing treshold
 (V_thr_) */

	double V_; 						//!< membrane potential
	const double V_thr_ = 20; 	//!< membrane potential treshold
	const double V_res_ = 0;		//!< membrane potential reset


	const int Tau_ = 20; //!< time constant used in the potential update (in ms)
	const int R_ = 20;  //!< membrane resistance

	const double h_ = 0.1; //!< step time in real time (in ms)


	const double J_ext_ = 0.1; //!< external input unit received by background noise

	const unsigned long D_ = 15; //delay of input current recieved by other neurons



/** when the Membrane_potential_ is reset it has a little time during which
 it is insesitive to stimulation (called the refractory time (T_ref_) */
	const int T_ref_ = 20;   //!< refractory time



	const double C1_ = exp(-h_/Tau_); //!< constant for update
	const double C2_ = R_*(1-exp(-h_/Tau_));  //!< constant for update


/* a spike is created each time the membrane potential reaches the
 membrane potential treshold */
	int Number_spikes_;  //!< number of spikes that occure


	int Ref_; //!< counter to check refractory state (Ref_ > 0) = Ref state


	std::vector <double> Times_spikes_; //!< labels the time at which a spike occures


	int Neuron_clock_;  //!< keeps track of time inside the neuron (in step value)


	std::vector<double> Delayed_weights_; //!< memorizes delayed signals
	/* Delayed_weights_ is simulated as a buffer */


	std::vector<int> Targets_; //!< list of target neurons



//--------------------- modules --------------------------



double Delayed_signal();
/*!
 * @brief : return a delayed signal from Delayed_weights_, returns 0 if there
 * is none and clears the value once it is used
 */


public:

	Neuron();
	Neuron(double V);

/*returns/set membrane potential */
	double getPot() const;
	void setPot(const double& V);

/*returns/add number of spikes */
	int getSpikes() const;
	void addSpike();

/* returns real time value of Neuron_clock_ (in ms) */
	double getNeuron_clock() const;
  /*!
	 * @brief : returns the neuron time in ms
	 */


	std::vector <double> getTimes_spikes() const;
	void addTime_spike(const double& time);



	bool update(const double& I, int poisson);
	/*! updates the membrane potential by 1 step, returns 'true' if the neuron
	 * has spiked
	 * @param I : input current
	 * @param poisson : random value from a poisson distribution for background
	 * noise
	 */

	size_t getDelay() const;


	void addDelayed_weight
	(const double& J, const unsigned long& D, const unsigned long& time);
	/*!
	 * @brief : simulates interaction between two neurons (*this recieves J
	 * from other neuron)
	 * @param J : weight to add
	 * @param D : delay at which the weight will come
	 */

	double getDelayed_weight(size_t position) const;
	/*!
	 * @brief : returns the delayed weight, this function is only used for tests
	 * since Delayed_signal also clears the value and will be lost
	 * @param position : time at which you want to test the buffer (± 15 steps)
   */

	void connect(const int& target);
	/*!
	 * @brief : saves target neuron index
	 * @param target : neuron index
	 */

 	std::vector <int> getTargets() const;


};







#endif
