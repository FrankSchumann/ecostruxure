#pragma once

#include <osal/semaphore/SemaphoreIf.h>

namespace osal
{
class Semaphore : public SemaphoreIf
{
   public:
    Semaphore();

    void acquire() const override;
    void release() const override;
};

}
