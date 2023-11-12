#include "BankAccount.h"
#include "SceneApplier.h"
#include <vector>

int main()
{

	BankAccount bankAccount;
	std::vector<float> sceneFirst({ 100, -20, 10, 5 });
	std::vector<float> sceneSecond({ 40, 9, -10 });

	SceneApplier sceneApplierFirst(sceneFirst, &bankAccount);
	SceneApplier sceneApplierSecond(sceneSecond, &bankAccount);

	std::thread threadSceneFirst(&SceneApplier::apply, sceneApplierFirst);
	std::thread threadSceneSecond(&SceneApplier::apply, sceneApplierSecond);

	threadSceneFirst.join();
	threadSceneSecond.join();

	

	return 0;
}