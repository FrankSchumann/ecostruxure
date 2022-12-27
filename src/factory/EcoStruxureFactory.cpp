#include "EcoStruxureFactory.h"

#include <iostream>
#include <memory>

#include "../component/EcoStruxureAdapter.h"
#include "copa-pdk/component/ComponentController.h"

EcoStruxureFactory::EcoStruxureFactory() : EcoStruxureFactory( std::make_shared< COPA::ComponentController >() )
{
}

EcoStruxureFactory::EcoStruxureFactory( std::shared_ptr< COPA::ComponentControllerIf > _componentController ) : componentController( _componentController )
{
}

EcoStruxureFactory::~EcoStruxureFactory()
{
}

std::shared_ptr< COPA::ComponentIf > EcoStruxureFactory::create( std::string const &name ) const
{
    std::cout << "EcoStruxureFactory::create" << std::endl;

    std::shared_ptr< RuntimeIf > ecoStruxureAdapter = std::make_shared< EcoStruxureAdapter >( type, name );

    auto const runtimeAdapterTmp = componentController->get( "RuntimeAdapter", "Mickey Mouse" );
    auto const runtimeAdapter = std::reinterpret_pointer_cast< RuntimeAdapterIf >( runtimeAdapterTmp );

    runtimeAdapter->subscribe( name, ecoStruxureAdapter );

    return ecoStruxureAdapter;
}

std::string EcoStruxureFactory::getType() const
{
    return type;
}
