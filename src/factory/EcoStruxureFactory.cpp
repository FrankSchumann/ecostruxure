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

    std::shared_ptr< RuntimeIf > ecoStruxureAdapter = std::make_shared< EcoStruxureAdapter >( type, name );

    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    auto const runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );

    runtimeController->subscribe( name, ecoStruxureAdapter );

    return ecoStruxureAdapter;
}

std::string EcoStruxureFactory::getType() const
{
    return type;
}

std::vector< std::string > EcoStruxureFactory::getDependencies() const
{
    std::vector< std::string > result{ "RuntimeController" };

    return result;
}

