#include "copa-pdk/osal/semaphore/SemaphoreFactory.h"

#include "Semaphore.h"

namespace COPA
{
SemaphoreFactory::SemaphoreFactory()
{
}

std::shared_ptr< SemaphoreIf > SemaphoreFactory::create() const
{
    return nullptr;
}

}
