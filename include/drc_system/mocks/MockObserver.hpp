#pragma once 

#include <gmock/gmock.h>

#include "drc_system/Observer.hpp"

namespace drc
{
    class MockObserver : public drc::Observer
    {
        public: 
            MOCK_METHOD(void, update, (), (override));
    };
};