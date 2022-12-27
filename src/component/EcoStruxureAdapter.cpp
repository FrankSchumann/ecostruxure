#include <iostream>
#include "EcoStruxureAdapter.h"

EcoStruxureAdapter::EcoStruxureAdapter( std::string const &_type, std::string const &_name )
    : EcoStruxureAdapter( _type, _name, std::make_shared< COPA::SemaphoreFactory >() )
{
}

EcoStruxureAdapter::EcoStruxureAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< COPA::SemaphoreFactoryIf > semaphoreFactory )
    : type( _type ), name( _name )
{
    semaphore = semaphoreFactory->create();
}

EcoStruxureAdapter::~EcoStruxureAdapter()
{
}

void EcoStruxureAdapter::startApplications() const
{
    std::cout << "EcoStruxureAdapter::startApplications"
              << " type: " << type << " name: " << name << std::endl;
    semaphore->acquire();
}

void EcoStruxureAdapter::stopApplications() const
{
    std::cout << "EcoStruxureAdapter::stopApplications"
              << " type: " << type << " name: " << name << std::endl;
}

std::string EcoStruxureAdapter::getRuntimeVersion() const
{
    return std::string( "0.8.1.5" );
}

std::string EcoStruxureAdapter::getType() const
{
    return type;
}

std::string EcoStruxureAdapter::getName() const
{
    return name;
}

std::string EcoStruxureAdapter::getVersion() const
{
    return std::string( "0.0.0.1" );
}
