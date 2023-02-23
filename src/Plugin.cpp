#include <iostream>
#include <memory>

#include "config.h"
#include <core/factory/FactoryController.h>
#include <core/component/ComponentController.h>
#include "factory/EcoStruxureFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "ecostruxure - subscribePlugin" << std::endl;

    std::shared_ptr< core::FactoryController > factoryController = std::make_shared< core::FactoryController >();

    std::shared_ptr< core::FactoryIf > ecoStruxureFactory = std::make_shared< EcoStruxureFactory >();

    factoryController->subscribe( ecoStruxureFactory );

    std::cout << std::endl;
}

extern "C" void unsubscribePlugin()
{
    std::cout << "ecostruxure - unsubscribePlugin" << std::endl;

    std::shared_ptr< core::ComponentController > componentController = std::make_shared< core::ComponentController >();

    std::shared_ptr< core::FactoryController > factoryController = std::make_shared< core::FactoryController >();

    std::shared_ptr< core::FactoryIf > ecoStruxureFactory = std::make_shared< EcoStruxureFactory >();

    auto const type = ecoStruxureFactory->getType();
    componentController->erase(type);

    factoryController->unsubscribe( type );

    std::cout << std::endl;
}

extern "C" const char* getName()
{
    return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
    return PLUGIN_VERSION.c_str();
}
