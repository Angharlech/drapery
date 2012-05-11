#include "EngineCoordinator.hpp"

int main(int argc, char *argv[]) 
{
    EngineCoordinator engine;
    std::string filename(argv[1]);
    engine.loadMap(filename);
    engine.startMainLoop();
    return 0;
}

