#pragma once

#include <memory>

#include <osal/semaphore/SemaphoreFactory.h>
#include <runtime/RuntimeIf.h>

class EcoStruxureAdapter : public RuntimeIf
{
   public:
    EcoStruxureAdapter( std::string const &_name );
    EcoStruxureAdapter( std::string const &_name, std::shared_ptr< osal::SemaphoreFactoryIf > semaphoreFactory );

    virtual void startApplications() const override;
    virtual void stopApplications() const override;
    virtual std::string getRuntimeVersion() const override;

    virtual std::string getType() const override;
    virtual std::string getName() const override;
    virtual std::string getVersion() const override;

    static std::string const type;

   private:
    std::string name;

    std::shared_ptr< osal::SemaphoreIf > semaphore;
};
