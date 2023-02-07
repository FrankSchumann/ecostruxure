#include <copa/factory/FactoryController.h>

namespace COPA
{

FactoryController::FactoryController()
{

}

void FactoryController::subscribe( std::shared_ptr< FactoryIf > const factory )
{

}

void FactoryController::unsubscribe( std::string const &type )
{

}

std::shared_ptr< FactoryIf > FactoryController::get( std::string const &type ) const
{
    return nullptr;
}

void FactoryController::list() const
{

}

}