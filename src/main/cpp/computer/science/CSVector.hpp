

#ifndef COMPUTER_SCIENCE_CSVECTOR_HPP
#define COMPUTER_SCIENCE_CSVECTOR_HPP

#include <vector>
#include <computer/science/IContainer.hpp>
#include <computer/science/Logger.hpp>
namespace computer::science
{
    class CSVector : public IContainer
    {
        public:

            CSVector() = default;
            CSVector(const CSVector&) = default;
            CSVector(CSVector&&) = default;
            CSVector& operator=(const CSVector&) = default;
            CSVector& operator=(CSVector&&) = default;
            virtual ~CSVector() = default;

            virtual void add(size_t num) override;
            virtual size_t count() const override;
            virtual void loop(functorIterator funcIt) const override;

        protected:

        private:

            std::vector<std::size_t>  m_items;
            static log4cxx::LoggerPtr logger;
    };
}
#endif

