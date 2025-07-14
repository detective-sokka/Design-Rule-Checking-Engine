#include <string>

#include "drc_system/DRCEngine.hpp"

using namespace drc;

DRCEngine& DRCEngine::getInstance()
{
    static DRCEngine engine; // Thread-safe since C++11
    return engine;
}

shared_ptr<DRCViolation> DRCEngine::createViolation(string object1Id, string object2Id)
{
    return shared_ptr<DRCViolation>(new DRCViolation(to_string(violationCounter++), object1Id, object2Id));
}

long long DRCEngine::violationCounter = 0;