#pragma once

#include <core/component/ComponentControllerIf.h>
#include <core/component/ComponentIf.h>
#include <core/factory/FactoryIf.h>

#include <memory>
#include <string>

class EcoStruxureFactory : public core::FactoryIf
{
   public:
    EcoStruxureFactory();
    EcoStruxureFactory( std::shared_ptr< core::ComponentControllerIf > _componentController );

    virtual std::shared_ptr< core::ComponentIf > create( std::string const &name ) const override;
    virtual void cleanup( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector< std::string > getDependencies() const override;

   private:
    std::shared_ptr< core::ComponentControllerIf > componentController;
};
