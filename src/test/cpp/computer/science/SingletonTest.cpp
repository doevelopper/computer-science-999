
#include <cppbdd101/SingletonTest.hpp>

SingletonTest::SingletonTest()
{

}

SingletonTest::~SingletonTest()
{

}

void SingletonTest::SetUp ()
{

}

void SingletonTest::TearDown ()
{

}


TEST_F(SingletonTest, instance_BasicType)
{
    //ASSERT_NE(nullptr, grb::Singleton<int>::instance());
    //ASSERT_EQ((int) 0, *grb::Singleton<int>::instance());
    //*grb::Singleton<int>::instance() = -1;
    //ASSERT_EQ((int) -1, *grb::Singleton<int>::instance());
}

TEST_F(SingletonTest, instance_StdClassType)
{
    //ASSERT_NE(nullptr, grb::Singleton<std::string>::instance());
    //ASSERT_STREQ("", grb::Singleton<std::string>::instance()->c_str());
    //*grb::Singleton<std::string>::instance() = "string";
    //ASSERT_STREQ("string", grb::Singleton<std::string>::instance()->c_str());
}

TEST_F(SingletonTest, instance_UserType)
{
    //ASSERT_NE(nullptr, grb::Singleton<TestClass>::instance());
    //ASSERT_EQ((int) 0, grb::Singleton<TestClass>::instance()->get());
    //grb::Singleton<TestClass>::instance()->set(-1);
    //ASSERT_EQ((int) -1, grb::Singleton<TestClass>::instance()->get());
}


TEST_F(SingletonTest, EngineAbortState )
{
    //EXPECT_TRUE(NULL != Singleton<int>::get());
    //(*Singleton<int>::get()) = 1;
    //EXPECT_EQ(1, *Singleton<int>::get());
}

TEST_F(SingletonTest, EngineAbortState ) 
{
    //ASSERT_NE( nullptr, pyralis::EngineAbortState::instance() );
}

TEST_F(SingletonTest, EngineCutoffState ) 
{
    //ASSERT_NE( nullptr, pyralis::EngineCutoffState::instance() );
}

TEST_F(SingletonTest, EnginePassiveState ) 
{
   // ASSERT_NE( nullptr, pyralis::EnginePassiveState::instance() );
}

TEST_F(SingletonTest, EngineStartupState ) 
{
    //ASSERT_NE( nullptr, pyralis::EngineStartupState::instance() );
}

TEST_F(SingletonTest, EngineThrustState ) 
{
   // ASSERT_NE( nullptr, pyralis::EngineThrustState::instance() );
}


