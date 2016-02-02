
#ifndef singletonImpl_h_included
#define singletonImpl_h_included

template <typename S>
class SingletonPtr
{
public:
	SingletonPtr()					{ m_pSingleton = S::Instance(); }
	~SingletonPtr() throw()			{ if( m_pSingleton ) m_pSingleton->Release(); }
	S* operator-> () const throw()	{ return m_pSingleton; }
	S& operator* ()  const throw()	{ return *m_pSingleton; }

private:
	S* m_pSingleton;
};

#endif // singletonImpl_h_included
