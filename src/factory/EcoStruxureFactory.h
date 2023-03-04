#pragma once

#include <memory>
#include <string>

#include <core/component/ComponentControllerIf.h>
#include <core/component/ComponentIf.h>
#include <core/factory/FactoryIf.h>

class EcoStruxureFactory : public core::FactoryIf
{
   public:
    EcoStruxureFactory();
    EcoStruxureFactory( std::shared_ptr< core::ComponentControllerIf > _componentController );

    virtual std::shared_ptr< core::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector<std::string> getDependencies() const override;

    void cleanup( std::string const &name );

   private:
    std::shared_ptr< core::ComponentControllerIf > componentController;
};
