

#include <computer/science/Logger.hpp>
#include <unistd.h>
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdlib.h>     /* getenv */

// log4cxx::LoggerPtr loggerPtr __attribute__((init_priority(10)));

using namespace computer::science;

const char * Logger::configEnv = "DIDACTICS_LOG_CONFIG";

log4cxx::LoggerPtr LOG = log4cxx::Logger::getLogger(std::string("computer.science.Logger"));

Logger::Logger(unsigned long delay)
    :   watchPeriod(delay)
{
    //    ::setenv("LOG4CXX_CONFIGURATION_PATH", "/etc/cfg/log4cxx.xml", 1);
    this->initLogger();
    // LOG4CXX_TRACE(LOG,"Logger::Logger");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
}

Logger::Logger(const Logger & orig) {
}

Logger::~Logger() {
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "---- END LOGGING -----");
    }

    log4cxx::LogManager::shutdown();
}

// Logger::Logger(const std::string &name)
// : m_logger(log4cxx::Logger::getLogger(name))
// {
// }

Logger::Logger(const std::string & logFileProperties,
               std::string path)
{
    path.append(logFileProperties);
    ::setenv("LOG4CXX_CONFIGURATION_FILE", path.c_str(), 1);
}

bool Logger::checkLogManagerStatus ()
{
    // LOG4CXX_TRACE(LOG,"Logger::checkLogManagerStatus");
    // Check that we have not accidentally triggered configuration.
    // Paranoia due to "When the LogManager class is loaded into memory the

    // default initialization procedure is initiated" in LogManager Doxygen.
    return (log4cxx::LogManager::getLoggerRepository()->isConfigured());
}

unsigned long Logger::periodicalCheck () const
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);

    return (this->watchPeriod);
}

void Logger::periodicalCheck ( unsigned long delay)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    this->watchPeriod = delay;
}

bool Logger::initLogger ()
{
    std::string configurationPath("");

    if (checkLogManagerStatus())
    {
        throw std::logic_error("log4cxx configuration detected");
    }
    else
    {
        char * filePath;
        try
        {
            if ((filePath = getenv("LOG4CXX_CONFIGURATION")) == NULL)
            {
                //std::cerr << "Failed to get loggger cnfiguratin file" << std::endl;
            }
            else
            {
                configurationPath.assign(filePath);
            }
        }
        catch ( log4cxx::helpers::Exception & e )
        {
            std::cout << typeid (e).name( ) << ": " << e.what( ) << std::endl;
        }
        catch (std::exception & e)
        {
            std::cout << typeid (e).name () << ": " << e.what () << std::endl;
        }
        catch (...)
        {
            std::cerr << "Mein Gott Vas den loss ??? " << std::endl;
        }

        if (configurationPath.empty() /*&& getenv(log4cxx.properties)*/)
        {
            // log4cxx::BasicConfigurator::configure();
            // log4cxx::LayoutPtr sbcLayout( new log4cxx::PatternLayout("[%d{yyyy-MM-ddTHH:mm:ss}] %p: %c: %m [%t]%n"));
            // log4cxx::PatternLayoutPtr   layout   (new log4cxx::PatternLayout ("%d{HH:mm:ss} %p %c{1} - %m%n"));
            // log4cxx::PatternLayoutPtr   layout   (new log4cxx::PatternLayout  ("\%-5p [\%t] [\%F:\%L]: \%m\%n"));

            // log4cxx::PatternLayoutPtr   layout   (new log4cxx::PatternLayout  ("%d{yyyy-MM-dd HH:mm:ss.SSS} (%-6c)
            // [%-6p] [%-5t] -- %m%n"));

            // log4cxx::PatternLayoutPtr   layout   (new log4cxx::PatternLayout  ("%d{yyyy-MM-dd HH:mm:ss.SSS} (%-6c)
            // [%-6p] [%-5t] [%r] (%-10.20l:%L) -- %m%n"));

            // log4cxx::PatternLayoutPtr   layout   (new log4cxx::PatternLayout  ("%d{yyyy-MM-dd HH:mm:ss.SSS} (%-6c)
            // [%-6p] [%15.15t] [%-6r] (%-10.20l) -- %m%n"));

            //log4cxx::PatternLayoutPtr layout   (new log4cxx::PatternLayout  (
            //                                        "%d{yyyy-MM-dd HH:mm:ss.SSS} (%-6c) [%-6p] [%15.15t] (%-10.20l) --
            // %m%n"));

            log4cxx::PatternLayoutPtr layout( new log4cxx::PatternLayout(
                                                  "[%-6.6p] %d{HH:mm:ss.SSS} [%15.15t] (%20.20c)  (%-10.20l) - %-20.20M - %m%n"
                                                  ) );

            // log4cxx::rolling::RollingFileAppender * rollingFileAppender (new
            // log4cxx::rolling::RollingFileAppender(layout
            // ,
            // "arkhe-gcs.log" ,
            // true));
            // rollingFileAppender->setMaxFileSize("10MB");
            // rollingFileAppender->setMaxBackupIndex(10);


            log4cxx::ConsoleAppenderPtr consoleAppender (new log4cxx::ConsoleAppender (layout));
            //            log4cxx::FileAppender * fileAppender = new log4cxx::FileAppender( log4cxx::LayoutPtr(layout
            // ),"cfs.log",
            //                                                                         false );

            log4cxx::helpers::Pool pool;
            consoleAppender->activateOptions(pool);
            log4cxx::BasicConfigurator::configure( consoleAppender );
            //        log4cxx::BasicConfigurator::configure( log4cxx::AppenderPtr( fileAppender ) );
            log4cxx::Logger::getRootLogger()->setLevel (log4cxx::Level::getTrace ());

            //       log4cxx::LogManager::getLoggerRepository()->setConfigured(true);
            log4cxx::Logger::getRootLogger( )->setLevel( /*DEFINED_LOG_ALL*/ true ? log4cxx::Level::getTrace( ) :
                                                         log4cxx::Level::getInfo() );
            log4cxx::LogManager::getLoggerRepository()->getRootLogger()->info(
                "Starting the nternal configured logging system.");
            LOG4CXX_TRACE(LOG, "Log4cxx file Path " << filePath);
        }
        else
        {
            if (::access(configurationPath.c_str(), R_OK) == 0)
            {
#if APR_HAS_THREADS
                this->loadConfigAndWatch(log4cxx::File( configurationPath.c_str( )).getPath( ));
#else
                this->loadConfig(log4cxx::File( configurationPath.c_str( )).getPath( ));
#endif

                /*
                                if (configurationPath.substr(configurationPath.find_last_of(".") + 1).compare("xml") ==
                                   0)
                                {
                 #if APR_HAS_THREADS
                                    log4cxx::xml::DOMConfigurator::configureAndWatch(configurationPath,
                                       this->periodicalCheck());
                 #else
                                    cfgRootPath.append(logFileProperties);
                                    log4cxx::xml::DOMConfigurator::configure(log4cxx::File(cfgRootPath).getPath());
                 #endif
                                }
                                else
                                {
                 #if APR_HAS_THREADS
                                    log4cxx::PropertyConfigurator::configureAndWatch(configurationPath,
                                       this->periodicalCheck());
                 #else
                                    log4cxx::PropertyConfigurator::configure(cfgRootPath);
                 #endif
                                }
                 */
                // loggerPtr->trace("Logger initialized");
            }

            log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getAll());
            log4cxx::LogManager::getLoggerRepository()->setConfigured(true);
            // log4cxx::LogManager::getLoggerRepository()->getRootLogger()->trace("Starting the logging system" +
            // configurationPath );
            // LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),"Logger initialized. Appenders sise:" <<
            // log4cxx::Logger::getRootLogger()->getAllAppenders().size() );
        }
    }

    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "----START LOGGING-----" );
    LOG4CXX_TRACE(
        log4cxx::Logger::getRootLogger(),
        "Logger initialized. Appenders sise:" << log4cxx::Logger::getRootLogger()->getAllAppenders().size() );
    // log4cxx::AppenderList listOfQppenders = log4cxx::Logger::getRootLogger()->getAllAppenders();
    /*for (size_t i = 0; i < listOfQppenders.size(); ++i)
       {
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), log4cxx::Logger::getRootLogger().operator ->().);
       }*/

    return (this->checkLogManagerStatus());
}

void Logger::loggerConfigure (std::string const & filename)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    // TODO: does resetConfiguration() remove existing appenders?
    log4cxx::BasicConfigurator::resetConfiguration();

    if (getFileExtension(filename).compare(".xml") == 0)
    {
        log4cxx::xml::DOMConfigurator::configure(filename);
    }
    else
    {
        log4cxx::PropertyConfigurator::configure(filename);
    }
}

bool Logger::loggerReset ()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    log4cxx::LogManager::resetConfiguration();
    log4cxx::BasicConfigurator::resetConfiguration();

    return (true);
}

std::string Logger::getFileExtension (const std::string & s)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    size_t i = s.rfind('.', s.length());

    if (i != std::string::npos)
    {
        return (s.substr(i + 1, s.length() - i));
    }

    return ("");
}

log4cxx::LoggerPtr Logger::getLoggerByName (const char * loggerName)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);

    return (log4cxx::LogManager::getLoggerRepository()->getLogger(std::string(loggerName)));
}

void Logger::setLoggerLevel (const std::string &loggerId,
                             const std::string &level)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    log4cxx::Logger::getLogger(loggerId)->setLevel(log4cxx::Level::toLevel(level, log4cxx::Level::getInfo()));
}

void Logger::setRootDefaultLevel (const std::string &level)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::toLevel(level, log4cxx::Level::getInfo()));
}

void Logger::loadConfig( const std::string & configFilename )
{
    if( log4cxx::LogManager::getLoggerRepository( )->isConfigured( ) )
    {
        if( !configFilename.empty( ) )
        {
            if( configFilename.find( ".xml" ) != std::string::npos )
            {
                log4cxx::xml::DOMConfigurator::configure( configFilename );
                // log4cxx::xml::DOMConfigurator::configure( log4cxx::File( configFilename ).getPath( ) );
            }
            else
            {
                log4cxx::PropertyConfigurator::configure( configFilename );
            }
        }
    }
    else
    {
        LOG4CXX_WARN( log4cxx::Logger::getRootLogger( ), "log4cxx configuration detected." );
    }
}

void Logger::loadConfigAndWatch( const std::string & configFilename )
{
    if( log4cxx::LogManager::getLoggerRepository( )->isConfigured( ) )
    {
        if( !configFilename.empty( ) )
        {
            if( configFilename.find( ".xml" ) != std::string::npos )
            {
                log4cxx::xml::DOMConfigurator::configureAndWatch( configFilename,
                                                                  static_cast< long >(this->periodicalCheck( ) ));
            }
            else
            {
                log4cxx::PropertyConfigurator::configureAndWatch( configFilename,
                                                                  static_cast< long >(this->periodicalCheck( ) ));
            }
        }
    }
    else
    {
        LOG4CXX_WARN( log4cxx::Logger::getRootLogger( ), "log4cxx configuration detected." );
    }
}

void
Logger::loggerNames( std::vector<std::string> & names )
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger( ), __LOG4CXX_FUNC__);
    log4cxx::LoggerList list = log4cxx::LogManager::getCurrentLoggers( );
    log4cxx::LoggerList::iterator logger = list.begin( );
    names.clear( );

    for(; logger != list.end( ); logger++ )
    {
        LOG4CXX_TRACE( log4cxx::Logger::getRootLogger( ), "Logger "
                       << std::distance(list.begin(), logger) << (*logger)->getName( ) );
        names.push_back( (*logger)->getName( ) );
    }
}

/*
   void addConsoleAppender(log4cxx::LoggerPtr logger, std::string layout,  std::string target)
   {
    log4cxx::PatternLayout *playout = new log4cxx::PatternLayout(layout);
    log4cxx::ConsoleAppender *appender = new log4cxx::ConsoleAppender(log4cxx::LayoutPtr(playout), target);
    log4cxx::helpers::Pool pool;
    appender->activateOptions(pool);
    logger->addAppender(appender);
   }

   void addFileAppender(log4cxx::LoggerPtr logger, std::string layout, std::string filename, bool append)
   {
   log4cxx::PatternLayout *playout = new log4cxx::PatternLayout(layout);
   log4cxx::FileAppender *appender = new log4cxx::FileAppender(log4cxx::LayoutPtr(playout), filename, append);
   log4cxx::helpers::Pool pool;
   appender->activateOptions(pool);
   logger->addAppender(appender);
   }

   void
   addRollingfileAppender(log4cxx::LoggerPtr logger, std::string layout, std::string filename, bool append, int
      bkup_index
    , std::string filesize)
   {
    log4cxx::PatternLayout *playout = new log4cxx::PatternLayout(layout);
    log4cxx::RollingFileAppender *appender = new log4cxx::RollingFileAppender(log4cxx::LayoutPtr(playout), filename,
       append);
    appender->setMaxBackupIndex(bkup_index);
    appender->setMaxFileSize(filesize);
    log4cxx::helpers::Pool pool;
    appender->activateOptions(pool);
    logger->addAppender(appender);
   }
   //*/

