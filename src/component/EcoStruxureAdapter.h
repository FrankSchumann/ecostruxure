#pragma once

#include <memory>

#include "copa-pdk/osal/semaphore/SemaphoreFactory.h"
#include "runtime-sdk/RuntimeIf.h"

class EcoStruxureAdapter : public RuntimeIf
{
   public:
    EcoStruxureAdapter( std::string const &_type, std::string const &_name );
    EcoStruxureAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< COPA::SemaphoreFactoryIf > semaphoreFactory );

    virtual void startApplications() const override;
    virtual void stopApplications() const override;
    virtual std::string getRuntimeVersion() const override;

    virtual std::string getType() const override;
    virtual std::string getName() const override;
    virtual std::string getVersion() const override;

   private:
    std::string type;
    std::string name;

    std::shared_ptr< COPA::SemaphoreIf > semaphore;
};
