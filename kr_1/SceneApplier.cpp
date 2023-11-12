#include "SceneApplier.h"
SceneApplier::SceneApplier(std::vector<float>& scenes, BankAccount* bankAccount)
	: operations{ scenes },
	bankAccount{ bankAccount },
	defferedOperations{},
	attemptsCounter{ 0 }
{
}

void SceneApplier::apply()
{
	for (auto operation : operations) {
		if (bankAccount->getValue() + operation < 0) {
			defferedOperations.push(operation);
		}
		else {
			bankAccount->modification(operation);
		}

		cntrlDelayedOper();

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void SceneApplier::cntrlDelayedOper()
{
	if (!defferedOperations.empty()) {
		if (attemptsCounter >= MAX_ATTEMPTS) {
			defferedOperations.pop();
			attemptsCounter = 0;
		}
		if (bankAccount->getValue() + defferedOperations.front() >= 0) {
			bankAccount->modification(defferedOperations.front());
			defferedOperations.pop();
			attemptsCounter = 0;
		}
		else {
			++attemptsCounter;
		}
	}
}