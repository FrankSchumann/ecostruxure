#include "EcoStruxureFactory.h"

#include <iostream>
#include <memory>

#include "../component/EcoStruxureAdapter.h"
#include <core/component/ComponentController.h>
#include <runtime/RuntimeControllerIf.h>

EcoStruxureFactory::EcoStruxureFactory() : EcoStruxureFactory( std::make_shared< core::ComponentController >() )
{
}

EcoStruxureFactory::EcoStruxureFactory( std::shared_ptr< core::ComponentControllerIf > _componentController ) : componentController( _componentController )
{
}

std::shared_ptr< core::ComponentIf > EcoStruxureFactory::create( std::string const &name ) const
{
    std::cout << "EcoStruxureFactory::create" << std::endl;

    std::shared_ptr< RuntimeIf > ecoStruxureAdapter = std::make_shared< EcoStruxureAdapter >( name );

    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    auto const runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );

    runtimeController->subscribe( ecoStruxureAdapter );

    return ecoStruxureAdapter;
}

void EcoStruxureFactory::cleanup( std::string const &name ) const
{
    std::cout << "EcoStruxureFactory::cleanup" << std::endl;

    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    auto const runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );

    runtimeController->unsubscribe( name );
}

std::string EcoStruxureFactory::getType() const
{
    return EcoStruxureAdapter::type;
}

std::vector< std::string > EcoStruxureFactory::getDependencies() const
{
    std::vector< std::string > result{ "RuntimeController" };

    return result;
}

