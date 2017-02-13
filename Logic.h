#ifndef LOGIC_H_
#define LOGIC_H_

#include "controllers/OperationController.h"
#include "controllers/MoveController.h"
#include "controllers/NewController.h"
#include "controllers/LoadController.h"
#include "controllers/ContinueController.h"
#include "controllers/SaveController.h"
#include "controllers/AbandonController.h"
#include "models/Game.h"

class Logic {
	controllers::MoveController * moveController;
	controllers::NewController * newController;
	controllers::LoadController * loadController;
	controllers::ContinueController * continueController;
	controllers::SaveController * saveController;
	controllers::AbandonController * abandonController;

public:
	Logic();
	controllers::OperationController * getOperationController();
};

#endif
