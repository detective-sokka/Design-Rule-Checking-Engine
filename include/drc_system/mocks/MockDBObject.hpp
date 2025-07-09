#pragma once 

#include <gmock/gmock.h>

#include "drc_system/DBObject.hpp"

namespace drc
{
    class MockDBObject : public drc::DBObject
    {
        public:
            explicit MockDBObject(const std::string &id) : mockId{id}
            {            
            }
            std::string getId() const override {
                return this->mockId; 
            }
        private:
            std::string mockId;
    };
};