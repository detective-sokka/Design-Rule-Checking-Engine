#pragma once

#include <memory>
#include <string>

#include "DRCViolation.hpp"

namespace drc
{
    class DRCEngine
    {
        public:
            static DRCEngine& getInstance();
            std::shared_ptr<DRCViolation> createViolation(std::string object1Id, std::string object2Id);
            static long long violationCounter;
        private: 
            DRCEngine() = default;
            ~DRCEngine() = default;

            DRCEngine(const DRCEngine&) = delete;
            DRCEngine& operator=(const DRCEngine&) = delete;
    };   
}