#include <exception>
#include "drc_system/DRCViolation.hpp"

using namespace drc;
using namespace std;

void DRCViolation::update()    
{
    markedForDeletion = true;
}

string DRCViolation::getId() const
{
    return violationId;
}
DRCViolation::DRCViolation(string violationId, string firstObjectId, string secondObjectId) 
                          : violationId{violationId}
                          , involvedObjectIds{firstObjectId, secondObjectId}
                          , markedForDeletion{false}
{
}

pair<string, string> DRCViolation::getInvolvedObjectIds() const
{
    return involvedObjectIds;
}

bool DRCViolation::isMarkedForDeletion() const
{
    return markedForDeletion;
}