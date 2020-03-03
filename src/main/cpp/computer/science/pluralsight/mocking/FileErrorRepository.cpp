

#include <fstream>

#include <computer/science/pluralsight/mocking/FileErrorRepository.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr FileErrorRepository::logger = log4cxx::Logger::getLogger(std::string(
                                                                                "computer.science.pluralsight.mocking.FileErrorRepository"));

FileErrorRepository::FileErrorRepository(std::string fileName)
    : m_fileName(fileName)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FileErrorRepository::logBadMovie(std::string movieName)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::ofstream errorLogFile;
    errorLogFile.open(m_fileName, std::ios::out);
    if(!errorLogFile.is_open())
    {
        LOG4CXX_ERROR(logger, "// TODO: handle error");
        // TODO: handle error
    }

    errorLogFile << movieName << std::endl;
    errorLogFile.close();
}

