

#ifndef COMPUTER_SCIENCE_ICONTAINER_HPP
#define COMPUTER_SCIENCE_ICONTAINER_HPP

#include <cstddef>
#include <functional>

namespace computer::science
{
    class IContainer
    {
        public:

            using functorIterator = std::function<void (const std::size_t num)>;
            IContainer() = default;
            IContainer(const IContainer&) = default;
            IContainer(IContainer&&) = default;
            IContainer& operator=(const IContainer&) = default;
            IContainer& operator=(IContainer&&) = default;
            virtual ~IContainer() = default;

            virtual void add(size_t num) = 0;
            virtual size_t count() const = 0;
            virtual void loop(functorIterator closure) const = 0;

        protected:

        private:
    };
}
#endif

