#include "String.h"
#include <iostream>


// Public Functions
String::String()
{
    mString     = new char[1];
    mString[0]  = '\0';
    mLength     = 0;
}

String::String( const String& aStr )
{
    mLength = aStr.mLength;
    mString = new char[ mLength + 1 ];

    for( int i = 0; i < mLength; i++ )
    {
        mString[i] = aStr.mString[i];
    }

    mString[mLength] = '\0';
}

String::String( const char* aStr )
{
    mLength = getStrLength( aStr );

    mString = new char[ mLength + 1 ];

    for( int i = 0; i < mLength; i++ )
    {
        mString[i] = aStr[i];
    }

    mString[mLength] = '\0';
}

String::~String()
{
    if( mString )
    {
        delete [] mString;
        mString = NULL;
    }
}

/*-------------------------------------------
        Overloaded Operators
-------------------------------------------*/
String& String::operator=( const char* rhs )
{
    mLength = getStrLength( rhs );

    if( mString )
    {
        delete [] mString;
    }

    mString = new char[ mLength + 1 ];

    for( int i = 0; i < mLength; i++ )
    {
        mString[i] = rhs[i];
    }

    mString[mLength] = '\0';

    return *this;
}

String& String::operator=( const String& rhs )
{
    if( this == &rhs )
    {
        return *this; // handle self assignment
    }
    String rtnVal( rhs.mString );
    return rtnVal;
}

String& String::operator+=( const String& rhs )
{
    return( *this += rhs.mString );
}

String& String::operator+=( const char* rhs )
{
    int rhsLen = getStrLength( rhs );
    int newStrLen = mLength + rhsLen;
    char* temp = new char[ newStrLen + 1 ];

    for( int i = 0; i < mLength; i++ )
    {
        temp[i] = mString[i];
    }

    for( int i = 0; i < rhsLen; i++ )
    {
        temp[mLength + i] = rhs[i];
    }

    temp[ newStrLen ] = '\0';

    if( mString )
    {
        delete [] mString;
    }

    mString = temp;
    mLength = newStrLen;

    return *this;
}

String operator+( const String& lhs, const String& rhs )
{
    String result( lhs.mString );
    result += rhs.mString;
    return result;
}

String operator+( const String& lhs, const char* rhs )
{
    String result( lhs.mString );
    result += rhs;
    return result;
}

std::ostream& operator<<( std::ostream& stream, const String& val )
{
    return stream << val.mString;
}

bool operator==( const String& lhs, const String& rhs )
{
    bool rtnVal = false;
    if( lhs.mLength == rhs.mLength )
    {
        rtnVal = true;
        for( int i = 0; i < lhs.mLength; i++ )
        {
            if( lhs.mString[i] != rhs.mString[i] )
            {
                rtnVal = false;
                break;
            }
        }
    }

    return rtnVal;
}

bool operator!=( const String& lhs, const String& rhs )
{
    return !(lhs == rhs);
}

const char* String::cString()
{
    char* rtnVal = new char[mLength + 1];

    for( int i = 0; i < mLength; i++ )
    {
        rtnVal[i] = mString[i];
    }

    rtnVal[mLength] = '\0';

    return const_cast<char*> (rtnVal);
}

int  String::getStrLength( const char* aStr )
{
    int rtnLen = 0;

    if( aStr )
    {
        for( int i = 0; aStr[i] != '\0'; i++ )
        {
            rtnLen++;
        }
    }

    return rtnLen;
}
