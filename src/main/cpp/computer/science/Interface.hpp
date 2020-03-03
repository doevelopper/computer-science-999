

#ifndef COMPUTER_SCIENCE_INTERFACE_HPP
#define COMPUTER_SCIENCE_INTERFACE_HPP

#include <cstddef>

namespace computer::science
{
    class Interface
    {
        public:

            using functor = std::function<void (const size_t num)>;

            Interface(const Interface&) = default;
            Interface(Interface&&) = default;
            Interface& operator=(const Interface&) = default;
            Interface& operator=(Interface&&) = default;
            virtual ~Interface() = default;

        public:

            virtual void add(size_t num) = 0;
            virtual size_t count() const = 0;
            virtual void loop(functor closure) const = 0;
    };

    class Container : public Interface
    {
        private:

            std::vector<size_t> items;

        public:

            void add(size_t num) override
            {
                items.push_back(num);
            }

            size_t count() const override
            {
                return items.size();
            }

            void forEach(functor closure) const override
            {
                for(const size_t item: items)
                {
                    closure(item);
                }
            }
    };
}


#endif

