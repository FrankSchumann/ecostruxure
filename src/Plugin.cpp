#include <iostream>
#include <memory>

#include "copa-pdk/factory/FactoryController.h"
#include "factory/EcoStruxureFactory.h"
#include "config.h"

extern "C" void subscribePlugin()
{
    std::cout << "Runtime - subscribePlugin2" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > ecoStruxureFactory = std::make_shared< EcoStruxureFactory >();

    factoryController->subscribe( ecoStruxureFactory );
}

extern "C" const char* getName()
{
	return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
	return PLUGIN_VERSION.c_str();
}
