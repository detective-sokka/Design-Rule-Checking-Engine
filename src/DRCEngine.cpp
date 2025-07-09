#include <string>

#include "drc_system/DRCEngine.hpp"

using namespace drc;

DRCEngine& DRCEngine::getInstance()
{
    static DRCEngine engine; // Thread-safe since C++11
    return engine;
}

std::shared_ptr<DRCViolation> DRCEngine::createViolation(std::string object1Id, std::string object2Id)
{
    return std::shared_ptr<DRCViolation>(new DRCViolation(std::to_string(violationCounter++), object1Id, object2Id));
}

long long DRCEngine::violationCounter = 0;