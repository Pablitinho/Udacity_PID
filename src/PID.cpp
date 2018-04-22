#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
	Kp=Kp_;
	Ki=Ki_;
	Kd=Kd_;
	prev_cte=0.0;
	cte_i=0.0;
}

void PID::UpdateError(double cte)
{
	p_error = -Kp*cte;
	i_error = -Ki*cte_i;
	d_error = -Kd*(cte-prev_cte);

	prev_cte = cte;
	cte_i += cte;
}

double PID::TotalError()
{
	double te=p_error+i_error+d_error;
	if (te<-1)
	{
		te=-1;
	}
	else if(te>1)
	{
		te=1;
	}
	return te;
}

