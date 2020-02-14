

#ifndef COMPUTER_SCIENCE_CALENDAR_HPP
#define COMPUTER_SCIENCE_CALENDAR_HPP

#include <algorithm>
#include <cctype>
#include <chrono>
#include <climits>

namespace computer::science
{
    namespace detail
    {
        template <typename R1, typename R2>
        using ratio_multiply = decltype(std::ratio_multiply<R1, R2> {});

        template <typename R1, typename R2>
        using ratio_divide = decltype(std::ratio_divide<R1, R2> {});
    }

    using days = std::chrono::duration
                 <int, detail::ratio_multiply<std::ratio<24>, std::chrono::hours::period> >;

    using weeks = std::chrono::duration
                  <int, detail::ratio_multiply<std::ratio<7>, days::period> >;

    using years = std::chrono::duration
                  <int, detail::ratio_multiply<std::ratio<146097, 400>, days::period> >;

    using months = std::chrono::duration
                   <int, detail::ratio_divide<years::period, std::ratio<12> > >;
    template <class Duration>
    using systemTime = std::chrono::time_point<std::chrono::system_clock, Duration>;
    using systemDays = systemTime<days>;
    using systemSeconds = systemTime<std::chrono::seconds>;

    class Calendar
    {
        public:

            Calendar();
            Calendar(const Calendar&) = default;
            Calendar(Calendar&&) = default;
            Calendar& operator=(const Calendar&) = default;
            Calendar& operator=(Calendar&&) = default;
            virtual ~Calendar() = default;

            bool isLeap(unsigned int year);
            bool isDivisibleBy4(unsigned int year);
            bool isDivisibleBy100(unsigned int year);
            bool isDivisibleBy400(unsigned int year);

        protected:

        private:

            unsigned int m_year;
            unsigned int m_month;
            unsigned int m_day;
    };
}
#endif

