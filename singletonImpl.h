#ifndef singletonImpl_h_included
#define singletonImpl_h_included

template <typename T>
class SingletonImpl : public T
{
public: //singleton implementation
	static SingletonImpl<T> * Instance()
	{
		if( internal_singleton_reference() == 0 )
		{
			internal_singleton_reference() = new SingletonImpl<T>;
		}
		internal_singleton_reference()->AddRef();
		return internal_singleton_reference();
	}

private:
	static SingletonImpl<T> * & internal_singleton_reference()  throw()
	{
		static SingletonImpl<T> * m_pSingletonInstance = 0;
		return m_pSingletonInstance;
	}



public:
	// reference count
	void AddRef()	throw()	{ ++m_reference_count; }
	void Release()	throw()
	{
	   if( --m_reference_count == 0 )
	   {
			delete internal_singleton_reference();
			internal_singleton_reference() = 0;
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
	SingletonPtr()					{ m_pSingleton = SingletonImpl<S>::Instance(); }
	~SingletonPtr() throw()			{ if( m_pSingleton ) m_pSingleton->Release(); }
	S* operator-> () const throw()	{ return m_pSingleton; }
	S& operator* ()  const throw()	{ return *m_pSingleton; }

private:
	SingletonImpl<S> * m_pSingleton;
};

#endif // singletonImpl_h_included
