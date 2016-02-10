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
	SingletonPtr()						{ m_pSingleton = SingletonImpl<S>::Instance(); }

	template <class ARG1>
	SingletonPtr( const ARG1& arg1 )	{ m_pSingleton = SingletonImpl<S>::Instance( arg1 ); }

	template <class ARG1, class ARG2>
	SingletonPtr( const ARG1& arg1, const ARG2& arg2 )
	{ m_pSingleton = SingletonImpl<S>::Instance( arg1, arg2 ); }

	~SingletonPtr() throw()				{ if( m_pSingleton ) m_pSingleton->Release(); }

	// copy constructor and assignment operator
	SingletonPtr( const SingletonPtr& rSingletonPtr ) throw()
	{
		m_pSingleton = rSingletonPtr.m_pSingleton;
		if( m_pSingleton ) m_pSingleton->AddRef();
	}

	SingletonPtr& operator = ( const SingletonPtr& rSingletonPtr )  throw()
	{
		if( rSingletonPtr.m_pSingleton ) rSingletonPtr.m_pSingleton->AddRef();
		// cleaning up from last pointer
		if( m_pSingleton ) m_pSingleton->Release();
		m_pSingleton = rSingletonPtr.m_pSingleton;
		return *this;
	}

	// accessor functions
	S* operator-> () const throw() { return m_pSingleton; }
	S& operator* ()  const throw() { return *m_pSingleton; }

private:
	SingletonImpl<S> * m_pSingleton;
};


#endif // singletonImpl_h_included
