#pragma once

#include "Core.h"
#include <string.h>

//RTTI Å¬·¡½º
class ENGINE_API RTTI
{
public:
	//RTTI(const std::string className)
	//	: className(className)
	//{

	//}

	virtual const size_t& TypeIdInstance() const = 0;

	virtual bool Is(const size_t id) const
	{
		return false;
	}

	template<typename T>
	T* As()
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}
		return nullptr;
	}

	template<typename T>
	const T* As() const
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}
		return nullptr;
	}

	//virtual const std::string& GetTypeName() const { return className; }
	

private:
	//std::string className;
};

#define RTTI_DECLARATIONS(Type, ParentType)															\
public:																								\
	using Super = ParentType;																		\
	virtual const size_t& TypeIdInstance() const { return Type::TypeIdClass(); }					\
	static const size_t TypeIdClass()																\
	{																								\
		static int runTimeTypeId = 0;																\
		return reinterpret_cast<size_t>(&runTimeTypeId);											\
	}																								\
	virtual bool Is(const size_t id) const															\
	{																								\
		if (id == TypeIdClass())																	\
		{																							\
			return true;																			\
		}																							\
		else																						\
		{																							\
			return Super::Is(id);																	\
		}																							\
	}