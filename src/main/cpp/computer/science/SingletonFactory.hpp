

#ifndef CPPBDD101_SINGLETONFACTORY_HPP
#define CPPBDD101_SINGLETONFACTORY_HPP

template <typename TS>
class SingletonFactory
{
    public:

        virtual ~SingletonFactory() {
        }

        TS* create()
        {
            if (isCreated)
            {
                return TS::mp_Instance.get();
            }

            isCreated = true;
            TS* pTmp = new TS();
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TParam>
        TS* create(_TParam param)
        {
            if (isCreated)
            {
                return TS::mp_Instance.get();
            }

            isCreated = true;
            TS* pTmp = new TS(param);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2>
        TS* create(_TP1 p1, _TP2 p2)
        {
            if (isCreated)
            {
                return TS::mp_Instance.get();
            }

            isCreated = true;
            TS* pTmp = new TS(p1, p2);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2, typename _TP3>
        TS* create(_TP1 p1, _TP2 p2, _TP3 p3)
        {
            if (isCreated)
            {
                return TS::mp_Instance.get();
            }

            isCreated = true;
            TS* pTmp = new TS(p1, p2, p3);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2, typename _TP3, typename _TP4>
        TS* create(_TP1 p1, _TP2 p2, _TP3 p3, _TP4 p4)
        {
            if (isCreated)
            {
                return TS::mp_Instance.get();
            }

            isCreated = true;
            TS* pTmp = new TS(p1, p2, p3, p4);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2, typename _TP3, typename _TP4, typename _TP5>
        TS* create(_TP1 p1, _TP2 p2, _TP3 p3, _TP4 p4, _TP5 p5)
        {
            if (isCreated)
            {
                return TS::mp_Instance.get();
            }

            isCreated = true;
            TS* pTmp = new TS(p1, p2, p3, p4, p5);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2, typename _TP3, typename _TP4, typename _TP5, typename _TP6>
        TS* create(_TP1 p1, _TP2 p2, _TP3 p3, _TP4 p4, _TP5 p5, _TP6 p6)
        {
            if (isCreated)
                return TS::mp_Instance.get();

            isCreated = true;
            TS* pTmp = new TS(p1, p2, p3, p4, p5, p6);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2, typename _TP3, typename _TP4, typename _TP5, typename _TP6, typename
                  _TP7>
        TS* create(_TP1 p1, _TP2 p2, _TP3 p3, _TP4 p4, _TP5 p5, _TP6 p6, _TP7 p7)
        {
            if (isCreated)
                return TS::mp_Instance.get();

            isCreated = true;
            TS* pTmp = new TS(p1, p2, p3, p4, p5, p6, p7);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        template <typename _TP1, typename _TP2, typename _TP3, typename _TP4, typename _TP5, typename _TP6, typename
                  _TP7, typename _TP8>
        TS* create(_TP1 p1, _TP2 p2, _TP3 p3, _TP4 p4, _TP5 p5, _TP6 p6, _TP7 p7, _TP8 p8)
        {
            if (isCreated)
                return TS::mp_Instance.get();

            isCreated = true;
            TS* pTmp = new TS(p1, p2, p3, p4, p5, p6, p7, p8);
            TS::mp_Instance.reset(pTmp);

            return TS::mp_Instance.get();
        }

        void destroy()
        {
            TS::mp_Instance.reset();
            isCreated = false;
        }

    private:

        static bool isCreated;
};

template <typename TS> bool SingletonFactory<TS>::isCreated = false;

#endif

