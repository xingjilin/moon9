// A few safe zero-init pod types. MIT licensed
// - rlyeh

#pragma once

#include <limits.h>
#include <float.h>

#include <limits>

namespace moon9
{
    template<typename sign, typename T, sign num = 0, sign div = 1 >
    struct pod
    {
        pod() : t( T(((double)num)/div) )
        {}

        pod( const T &_t ) : t(_t)
        {}

        operator const T &() const
        {
            return t;
        }

        operator T &()
        {
            return t;
        }

#       define $pod(OP) \
        template<typename F> \
        pod &operator OP( const F &_t ) \
        { \
            t OP (T)_t; \
            return *this; \
        }
        $pod( =)
        $pod(|=)
        $pod(&=)
        $pod(^=)
        $pod(+=)
        $pod(-=)
        $pod(*=)
        $pod(/=)
        $pod(%=)
#       undef $pod

        pod &operator ++()
        {
            return ++t, *this;
        }
        pod operator ++( int )
        {
            pod other = *this;
            return t++, other;
        }
        pod &operator --()
        {
            return --t, *this;
        }
        pod operator --( int )
        {
            pod other = *this;
            return t--, other;
        }

        T max() const
        {
            return std::numeric_limits<T>::max();
        }
        T min() const
        {
            return std::numeric_limits<T>::min();
        }

        protected: T t;
    };

    typedef moon9::pod< signed, bool, 0 > bool0;
    typedef moon9::pod< signed, bool, 1 > bool1;

// std::numeric_limits<float>::max(), not constexpr! :(
    typedef moon9::pod< signed, float, signed(FLT_MAX) > floatNn;
    typedef moon9::pod< signed, float,  -1 > float1n;
    typedef moon9::pod< signed, float,   0 > float0;
    typedef moon9::pod< signed, float, 1,5 > float020;
    typedef moon9::pod< signed, float, 1,4 > float025;
    typedef moon9::pod< signed, float, 1,3 > float033;
    typedef moon9::pod< signed, float, 1,2 > float050;
    typedef moon9::pod< signed, float, 3,4 > float075;
    typedef moon9::pod< signed, float,   1 > float1;
    typedef moon9::pod< signed, float,   2 > float2;
    typedef moon9::pod< signed, float,   3 > float3;
    typedef moon9::pod< signed, float, signed(-FLT_MAX) > floatN;

// DBL_MAX, precision over :(
    typedef moon9::pod< signed, double, signed(FLT_MAX), 1 > doubleNn;
    typedef moon9::pod< signed, double,  -1 > double1n;
    typedef moon9::pod< signed, double,   0 > double0;
    typedef moon9::pod< signed, double, 1,5 > double020;
    typedef moon9::pod< signed, double, 1,4 > double025;
    typedef moon9::pod< signed, double, 1,3 > double033;
    typedef moon9::pod< signed, double, 1,2 > double050;
    typedef moon9::pod< signed, double, 3,4 > double075;
    typedef moon9::pod< signed, double,   1 > double1;
    typedef moon9::pod< signed, double,   2 > double2;
    typedef moon9::pod< signed, double,   3 > double3;
    typedef moon9::pod< signed, double, signed(-FLT_MAX), 1 > doubleN;

    typedef moon9::pod< signed, signed char, SCHAR_MIN > charNn;
    typedef moon9::pod< signed, signed char,        -1 > char1n;
    typedef moon9::pod< signed, signed char,         0 > char0;
    typedef moon9::pod< signed, signed char,         1 > char1;
    typedef moon9::pod< signed, signed char,         2 > char2;
    typedef moon9::pod< signed, signed char,         3 > char3;
    typedef moon9::pod< signed, signed char, SCHAR_MAX > charN;

    typedef moon9::pod< signed, signed short, SHRT_MIN > shortNn;
    typedef moon9::pod< signed, signed short,       -1 > short1n;
    typedef moon9::pod< signed, signed short,        0 > short0;
    typedef moon9::pod< signed, signed short,        1 > short1;
    typedef moon9::pod< signed, signed short,        2 > short2;
    typedef moon9::pod< signed, signed short,        3 > short3;
    typedef moon9::pod< signed, signed short, SHRT_MAX > shortN;

    typedef moon9::pod< signed, signed int, INT_MIN > intNn;
    typedef moon9::pod< signed, signed int,      -1 > int1n;
    typedef moon9::pod< signed, signed int,       0 > int0;
    typedef moon9::pod< signed, signed int,       1 > int1;
    typedef moon9::pod< signed, signed int,       2 > int2;
    typedef moon9::pod< signed, signed int,       3 > int3;
    typedef moon9::pod< signed, signed int, INT_MAX > intN;


    typedef moon9::pod< unsigned, unsigned char,  0 > uchar0;
    typedef moon9::pod< unsigned, unsigned char,  1 > uchar1;
    typedef moon9::pod< unsigned, unsigned char,  2 > uchar2;
    typedef moon9::pod< unsigned, unsigned char,  3 > uchar3;
    typedef moon9::pod< unsigned, unsigned char, -1 > ucharN;

    typedef moon9::pod< unsigned, unsigned short,  0 > ushort0;
    typedef moon9::pod< unsigned, unsigned short,  1 > ushort1;
    typedef moon9::pod< unsigned, unsigned short,  2 > ushort2;
    typedef moon9::pod< unsigned, unsigned short,  3 > ushort3;
    typedef moon9::pod< unsigned, unsigned short, -1 > ushortN;

    typedef moon9::pod< unsigned, unsigned int,   0 > uint0;
    typedef moon9::pod< unsigned, unsigned int,   1 > uint1;
    typedef moon9::pod< unsigned, unsigned int,   2 > uint2;
    typedef moon9::pod< unsigned, unsigned int,   3 > uint3;
    typedef moon9::pod< unsigned, unsigned int,  -1 > uintN;


    typedef moon9::pod< unsigned, size_t,   0 > sizet0;
    typedef moon9::pod< unsigned, size_t,   1 > sizet1;
    typedef moon9::pod< unsigned, size_t,   2 > sizet2;
    typedef moon9::pod< unsigned, size_t,   3 > sizet3;
    typedef moon9::pod< unsigned, size_t,  -1 > sizetN;

//  typedef moon9::pod<        float, (unsigned)(~0) > floatN;
//  typedef moon9::pod<       double, (unsigned)(~0) > doubleN;

//  typedef moon9::pod<        float, (long long int)(FLT_MAX) > floatN;
//  typedef moon9::pod<       double, (long long int)(DBL_MAX) > doubleN;
}
