

#ifndef COMPUTER_SCIENCE_CSQUEUE_HPP
#define COMPUTER_SCIENCE_CSQUEUE_HPP

#include <deque>
#include <computer/science/IContainer.hpp>

namespace computer::science
{
    class CSQueue : public IContainer
    {
        public:

            CSQueue() = default;
            CSQueue(const CSQueue&) = default;
            CSQueue(CSQueue&&) = default;
            CSQueue& operator=(const CSQueue&) = default;
            CSQueue& operator=(CSQueue&&) = default;
            virtual ~CSQueue() = default;

            virtual void add(size_t num) override;
            virtual size_t count() const override;
            virtual void loop(functorIterator funcIt) const override;

        protected:

        private:

            std::deque<std::size_t> m_items;
    };
}
#endif

