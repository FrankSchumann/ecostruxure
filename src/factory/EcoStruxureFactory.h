#pragma once

#include <memory>
#include <string>

#include "copa-pdk/component/ComponentControllerIf.h"
#include "copa-pdk/component/ComponentIf.h"
#include "copa-pdk/factory/FactoryIf.h"

class EcoStruxureFactory : public COPA::FactoryIf
{
   public:
    EcoStruxureFactory();
    EcoStruxureFactory( std::shared_ptr< COPA::ComponentControllerIf > _componentController );

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector<std::string> getDependencies() const override;

   private:
    const std::string type = std::string( "EcoStruxureAdapter" );

    std::shared_ptr< COPA::ComponentControllerIf > componentController;
};
