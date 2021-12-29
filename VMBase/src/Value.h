#include <cstdint>

namespace VM {

	enum class ValueType {
		VT_INT		= 0x00,
		VT_DOUBLE	= 0x01,
		VT_BOOL		= 0x02
	};

	struct Value {

		ValueType type;

		union {
			uint32_t	intValue;
			double		doubleValue;
			bool		boolValue;
		};
	};
}