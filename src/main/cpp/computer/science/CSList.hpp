

#ifndef COMPUTER_SCIENCE_CSList_HPP
#define COMPUTER_SCIENCE_CSList_HPP

#include <list>
#include <computer/science/IContainer.hpp>

namespace computer::science
{
    class CSList : public IContainer
    {
        public:

            CSList() = default;
            CSList(const CSList&) = default;
            CSList(CSList&&) = default;
            CSList& operator=(const CSList&) = default;
            CSList& operator=(CSList&&) = default;
            virtual ~CSList() = default;

            virtual void add(size_t num) override;
            virtual size_t count() const override;
            virtual void loop(functorIterator funcIt) const override;

        protected:

        private:

            std::list<std::size_t> m_items;
    };
}
#endif

