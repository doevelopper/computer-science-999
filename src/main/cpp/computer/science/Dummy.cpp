

#include <computer/science/Dummy.hpp>

using namespace computer::science;

log4cxx::LoggerPtr Dummy::logger = log4cxx::Logger::getLogger(std::string("computer.science.Dummy"));

Dummy::Dummy()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Dummy::~Dummy()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Dummy::Dummy (const std::string& hello,  const std::string& world)
    : m_hello{hello}
    , m_world{world}
    , m_speechless{}
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_speechless = (hello.empty() && world.empty());
}

std::string Dummy::speak() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    auto hello = m_hello;
    hello.append(" ");
    hello.append(m_world);

    return (hello);
}

bool Dummy::speechless() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_speechless;
}

