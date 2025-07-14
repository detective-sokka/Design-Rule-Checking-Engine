#include <gtest/gtest.h>
#include <type_traits>

#include "drc_system/DRCEngine.hpp"
#include "drc_system/mocks/MockDBObject.hpp"

using namespace drc;
using namespace std;

TEST(DRCEngineTest, SingletonReturnsSameInstance)
{
    auto &instance1 = DRCEngine::getInstance(); 
    auto &instance2 = DRCEngine::getInstance(); 
    EXPECT_EQ(&instance1, &instance2);
}

TEST(DRCEngineTest, ConstructorPrivate) {
    static_assert(!is_constructible<DRCEngine>::value,
                  "Constructor should be private");
}

TEST(DRCEngineTest, CopyConstructorDeleted) {
    static_assert(!is_copy_constructible<DRCEngine>::value,
                  "Copy Constructor not allowed for Singleton");
}

TEST(DRCEngineTest, AssignmentOperatorDeleted) {
    static_assert(!is_copy_assignable<DRCEngine>::value,
                  "Assignment operator not allowed for Singleton");
}

TEST(DRCEngineTest, CreateViolationCreatesANewViolation)
{
    auto &instance = DRCEngine::getInstance();
    MockDBObject obj1("id1");
    MockDBObject obj2("id2");

    shared_ptr<DRCViolation> violation = instance.createViolation(obj1.getId(), obj2.getId());
    pair<string, string> objectIds{"id1", "id2"};

    ASSERT_TRUE(violation);
    ASSERT_EQ(objectIds, violation->getInvolvedObjectIds());

    MockDBObject obj3("id3");
    
    shared_ptr<DRCViolation> secondViolation = instance.createViolation(obj2.getId(), obj3.getId());
    objectIds = {"id2", "id3"};
    ASSERT_TRUE(secondViolation);
    ASSERT_EQ(objectIds, secondViolation->getInvolvedObjectIds());
    
    ASSERT_EQ(instance.getViolations("id2").size(), 2);
}