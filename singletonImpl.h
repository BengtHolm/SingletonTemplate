#ifndef singletonImpl_h_included
#define singletonImpl_h_included

template <typename T>
class SingletonImpl : public T
{
public: //singleton implementation
	static SingletonImpl<T> * Instance()
	{
		if( m_pInstance == 0 )
		{
			m_pInstance = new SingletonImpl<T>;
		}
		m_pInstance->AddRef();
		return m_pInstance;
	}

private:
	static SingletonImpl<T> * m_pInstance;

public:
	// reference count
	void AddRef()	throw()	{ ++m_reference_count; }
	void Release()	throw()
	{
	   if( --m_reference_count == 0 )
	   {
			delete m_pInstance;
			m_pInstance = 0;
	   }
	}

private:
	// reference count
	SingletonImpl() : m_reference_count( 0 ) { }
	unsigned long m_reference_count;
};


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
