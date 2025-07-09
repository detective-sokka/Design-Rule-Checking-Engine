#include <gtest/gtest.h>

#include "drc_system/mocks/MockObserver.hpp"
#include "drc_system/mocks/MockDBObject.hpp"

using namespace drc;

TEST(DRCObjectTest, ConstructorStoresUniqueID)
{
    MockDBObject object1{"VIA_1"};
    EXPECT_EQ(object1.getId(), "VIA_1");

    MockDBObject object2{"PIN_1"};
    EXPECT_EQ(object2.getId(), "PIN_1");
}

TEST(DRCObjectTest, NotifyCallsUpdateOnSingleObserver)
{
    MockObserver *observer1 = new MockObserver{};
    MockDBObject object1{"PIN_5"};

    object1.subscribe(observer1);

    EXPECT_CALL(*observer1, update()).Times(1);
    object1.notifyObservers();

    delete observer1;
}

TEST(DRCObjectTest, NotifyCallsUpdateOnMultipleObservers)
{
    MockObserver *observer1 = new MockObserver{};
    MockObserver *observer2 = new MockObserver{};

    MockDBObject object1{"PIN_5"};

    object1.subscribe(observer1);
    object1.subscribe(observer2);

    EXPECT_CALL(*observer1, update()).Times(1);
    EXPECT_CALL(*observer2, update()).Times(1);

    object1.notifyObservers();

    delete observer1;
    delete observer2;
}

TEST(DRCObjectTest, UnsubscribePreventsNotification)
{
    MockObserver *observer1 = new MockObserver{};
    MockObserver *observer2 = new MockObserver{};

    MockDBObject object1{"PIN_5"};

    object1.subscribe(observer1);
    object1.subscribe(observer2);
    object1.unsubscribe(observer1);

    EXPECT_CALL(*observer1, update()).Times(0);
    EXPECT_CALL(*observer2, update()).Times(1);
    
    object1.notifyObservers();
    
    delete observer1;
    delete observer2;
}