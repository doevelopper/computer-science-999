

#ifndef LINE_H
#define LINE_H
#include <cstddef>

template <std::size_t N>
class Line
{
    public:

        static constexpr std::size_t capacity()
        {
            return N;
        }

        explicit Line(std::size_t n)
            : _length{n < N ? n : N} {
        };

        std::size_t length() const
        {
            return _length;
        }

    private:

        std::size_t _length = 0;
};

struct paramList
{
    bool out;
    int in;
};

#endif

#include <gtest/gtest.h>
#include <type_traits>


template <typename T>
class line_tester : public ::testing::Test
{
};

using test_types = ::testing::Types<
    std::integral_constant<std::size_t,2>,
    std::integral_constant<std::size_t,3>,
    std::integral_constant<std::size_t,5> >;

TYPED_TEST_CASE(line_tester, test_types);

TYPED_TEST(line_tester, get_capacity)
{
    static constexpr std::size_t n = TypeParam::value;
    ASSERT_EQ(n,Line<n>::capacity());
}

TYPED_TEST(line_tester, set_length_preserved)
{
    Line<TypeParam::value> line{1};
    ASSERT_EQ(line.length(),1);
}

TYPED_TEST(line_tester, set_length_trunctated)
{
    static constexpr std::size_t n = TypeParam::value;
    Line<n> line{999};
    ASSERT_EQ(line.length(),Line<n>::capacity());
}


class IsPrimeParamTest : public ::testing::TestWithParam<struct paramList>
{
};

TEST_P(IsPrimeParamTest, IsPrime)
{
    bool out = GetParam().out;
    int in = GetParam().in;
    EXPECT_EQ(out, IsPrime(in));
}

INSTANTIATE_TEST_CASE_P(IsPrimeParamTest,
                        IsPrimeParamTest,
                        Values(paramList{false, 10}, paramList{true, 3}));

