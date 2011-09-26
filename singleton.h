#ifndef SINGLETON_H
#define SINGLETON_H

#include <cstdlib>

template<typename T>
class cSingleton {
public :
    static T& instance();
    static void destroy();

protected :
    inline explicit cSingleton()
    {
        cSingleton::m_poInstance = static_cast<T*>(this);
    }

    inline ~cSingleton()
    {
        cSingleton::m_poInstance = 0;
    }

private :
    static T* m_poInstance;

private :
    inline explicit cSingleton( cSingleton const&) {}
    inline cSingleton& operator =( cSingleton const& ) { return *this; }
};

template<typename T>
T& cSingleton<T>::instance()
{
    if( cSingleton::m_poInstance == 0 )
    {
        cSingleton::m_poInstance = new T();
        std::atexit( cSingleton::destroy );
    }
    return *(cSingleton::m_poInstance);
}

template<typename T>
void cSingleton<T>::destroy()
{
    if ( cSingleton::m_poInstance != 0 )
    {
        delete cSingleton::m_poInstance;
        cSingleton::m_poInstance = 0;
    }
}

template<typename T>
T* cSingleton<T>::m_poInstance = 0;

#endif // SINGLETON_H
