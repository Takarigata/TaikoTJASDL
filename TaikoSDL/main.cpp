#include "Sources/GameFramework/Public/Game.h"
#include "Sources/GameFramework/Public/GameSFML.h"
#include "Sources/EngineFramework/Subsystem/Public/BaseEngineSubsystem.h"


GameSFML *gameSFML = nullptr;
BaseEngineSubsystem* Engine = nullptr;
int main(int argc, char* argv[])
{
	gameSFML = new GameSFML();
	
	gameSFML->init("Taiko SDK", 1920 , 1080, false);
	Engine = BaseEngineSubsystem::GetInstance();

	BaseEngineSubsystem* En = BaseEngineSubsystem::GetInstance();
	if(En)
	{
		En->printSub();
	}
	
	while(gameSFML->running())
	{
		gameSFML->handleEvents();
		gameSFML->update();
		gameSFML->render();
	}
	
	gameSFML->clean();
	
	return 0;
}