#pragma once
#include "../Data/Models/Customer.h"
#include "../Views/Process/ProcessView.h"

using namespace std;

class ProcessController
{
	public:
		void ProcessGet(Customer customer, string message = "");
};