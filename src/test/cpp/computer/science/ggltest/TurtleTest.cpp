#include  <cppbdd101/lectures/ggltest/TurtleTest.hpp>

// MockTurtle * TurtleTest::objectUnderTest = nullptr;
log4cxx::LoggerPtr TurtleTest::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.TurtleTest"));


TurtleTest::TurtleTest()
        : objectUnderTest(nullptr)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TurtleTest::TurtleTest(const TurtleTest & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TurtleTest::~TurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void TurtleTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    objectUnderTest = new MockTurtle();
}

void TurtleTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // Verifies and removes the expectations on mock_obj; // returns true iff successful
    ::testing::Mock::VerifyAndClearExpectations(objectUnderTest);
    // Verifies and removes the expectations on mock_obj; also removes the default actions set by ON_CALL();
    ::testing::Mock::VerifyAndClear(objectUnderTest);
    delete objectUnderTest;
}

TEST_F(TurtleTest , testIsActive)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest , IsActive()).Times(AnyNumber());
    objectUnderTest->IsActive();
    /*
        MockTurtle object;
        EXPECT_CALL(object, IsActive()).Times(AnyNumber());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Unexpected key !"
                , false
                , object.IsActive());
     */

}

TEST_F(TurtleTest , testName)
{
    /*Default Values for Custom Types*/
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest , name()).WillRepeatedly(Return(std::string("someDefaultValue")));

    ASSERT_STREQ(std::string("someDefaultValue").c_str() , objectUnderTest->name().c_str());
}

TEST_F(TurtleTest , testNameDefault)
{
    /*Default Values for Custom Types*/
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    ::testing::DefaultValue<std::string>::Set(std::string("Some Default Value for Test"));

    EXPECT_CALL(*objectUnderTest , name()).Times(AnyNumber());

    ASSERT_STREQ(std::string("Some Default Value for Test").c_str() , objectUnderTest->name().c_str());

    std::string value = "Hello World!";

    EXPECT_CALL(*objectUnderTest , name())
            .Times(1)
            .WillOnce(Return(value));

    //    LOG4CXX_DEBUG(logger,"objectUnderTest->name()" <<objectUnderTest->name());

    ASSERT_STREQ(std::string("Hello World!").c_str()
    , objectUnderTest->name().c_str())<< "diagnostic message";
}

TEST_F(TurtleTest , testGetY)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_CALL(*objectUnderTest , GetY())
            .WillOnce(Return(300))
            .WillOnce(Return(400))
            .WillOnce(Return(500));

    ASSERT_EQ(300 , objectUnderTest->GetY());

    ASSERT_EQ(400 , objectUnderTest->GetY());

    ASSERT_EQ(500 , objectUnderTest->GetY());

    int n = 10;

    for (int i = n; i > 0; i--)
    {
        EXPECT_CALL(*objectUnderTest , GetY())
                .WillOnce(Return(10*i));

        LOG4CXX_DEBUG(logger , "Y is: " <<objectUnderTest->GetY());
    }

    /*
        EXPECT_CALL (*objectUnderTest, GetX ())
         .Times (5)
         .WillOnce (Return (100))
         .WillOnce (Return (150))
         .WillRepeatedly (Return (200));
        EXPECT_CALL(*objectUnderTest, GetY())
            .Times(4)
            .WillOnce(Return(100))
            .WillRepeatedly (Return(20));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(
            "Value mismatch !",
            100, objectUnderTest->GetY());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(
            "Value mismatch !",
            100, objectUnderTest->GetY());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(
            "Value mismatch !",
            100, objectUnderTest->GetY());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(
            "Value mismatch !",
            100, objectUnderTest->GetY());
       //*/

}

TEST_F(TurtleTest , testGetX)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_CALL(*objectUnderTest , GetX())
            .WillOnce(Return(100))
            .WillOnce(Return(200))
            .WillOnce(Return(300));

    ASSERT_EQ(100 , objectUnderTest->GetX());

    ASSERT_EQ(200 , objectUnderTest->GetX());

    ASSERT_EQ(300 , objectUnderTest->GetX());

    int n = 10;
    EXPECT_CALL(*objectUnderTest , GetX())
            .Times(2)
            .WillRepeatedly(Return(n++));

    LOG4CXX_DEBUG(logger , "objectUnderTest->name()" <<objectUnderTest->GetX());
    LOG4CXX_DEBUG(logger , "objectUnderTest->name()" <<objectUnderTest->GetX());

    {
        InSequence s;

        for (int i = 1; i <= n; i++)
        {
            EXPECT_CALL(*objectUnderTest , GetX())
                    .WillOnce(Return(10*i))
                    .RetiresOnSaturation();
            LOG4CXX_DEBUG(logger , "X is: " <<objectUnderTest->GetX());
        }
    }
}

TEST_F(TurtleTest , testGoTo)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest , GoTo(_ , _))
            .Times(AnyNumber());

    objectUnderTest->GoTo(10 , 10);

    EXPECT_CALL(*objectUnderTest , GoTo(0 , 0))
            .Times(2);
    objectUnderTest->GoTo(0 , 0);
    objectUnderTest->GoTo(0 , 0);
}

TEST_F(TurtleTest , testForward)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    /*
        EXPECT_CALL (*objectUnderTest, Forward (_));
        EXPECT_CALL (*objectUnderTest, Forward (10))
            .Times (2);
     */

}

TEST_F(TurtleTest , testGooglePenUp)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // EXPECT_CALL(&this->objectUnderTest, PenUp()).Times(AnyNumber());
    /*
        MockTurtle object;
        EXPECT_CALL(object, PenUp()).Times(AnyNumber());
        CPPUNIT_ASSERT_ASSERTION_PASS_MESSAGE("object",
                object.PenUp());
     */
    /*
       std::shared_ptr<Turtle> mockt(new MockTurtle);
       EXPECT_CALL(*std::static_pointer_cast<MockTurtle>(mockt),
              PenUp()).Times(testing::AtLeast(1));
       EXPECT_CALL(MockTurtle.PenUp())
        .With(...) ?
        .Times(...) ?
        .InSequence(...) *
        .WillOnce(...) *
        .WillRepeatedly(...) ?
        .RetiresOnSaturation() ? ;
         //this->objectUnderTest->PenUp();
     */
    // CPPUNIT_ASSERT(true);
}

TEST_F(TurtleTest , testCpy)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    /*
       MockTurtle  mock;
       MockTurtle  mock2 = mock;
       MockTurtle * mock = new MockTurtle(*this->objectUnderTest);
       mock = this->objectUnderTest;
       EXPECT_CALL(*mock , GetY())
       .WillOnce(Return(37));
       CPPUNIT_ASSERT_EQUAL_MESSAGE(
        "Value mismatch !" ,
        37 , objectUnderTest->GetY());
       delete mock;
     */

}
