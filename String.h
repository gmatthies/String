#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
    public:
        // Constructors
        String();
        String( const String& aStr );
        String( const char* aStr );

        // Destructor
        virtual ~String();

        // Overloaded Operators
        String& operator=( const String& other );
        String& operator=( const char* rhs );
        String& operator+=( const String& rhs );
        String& operator+=( const char* rhs );

        friend String operator+( const String& lhs, const String& rhs );
        friend String operator+( const String& lhs, const char* rhs   );
        friend String operator+( const char* lhs  , const String& rhs );

        friend std::ostream& operator<<( std::ostream& stream, const String& val );

        friend bool operator==( const String& lhs, const String& rhs );
        friend bool operator!=( const String& lhs, const String& rhs );

        const char* cString();

        inline int length()
        {
            return mLength;
        }

    protected:
    private:
        int  getStrLength( const char* aStr );

        // Members
        int     mLength;
        char*   mString;
};

#endif // STRING_H
