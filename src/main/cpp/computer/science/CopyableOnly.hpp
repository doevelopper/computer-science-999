

#ifndef COMPUTER_SCIENCE_COPYABLEONLY_HPP
#define COMPUTER_SCIENCE_COPYABLEONLY_HPP

namespace computer::science
{
    class CopyableOnly
    {
        public:

            CopyableOnly();
            CopyableOnly(const CopyableOnly& orig);
            CopyableOnly(CopyableOnly&& orig) = delete;
            CopyableOnly & operator=(const CopyableOnly& orig);
            CopyableOnly & operator=(CopyableOnly && orig) = delete;
            virtual ~CopyableOnly();

        private:
    };
}
#endif

