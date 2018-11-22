#ifndef ENUM_MAP_H_
#define ENUM_MAP_H_

#include <map>
#include <tuple>

#include <boost/any.hpp>
#include <boost/optional.hpp>

/**
 * Data structure for storing variables and corresponding values together, Note that this structure needs memory for
 * variables with values, not all of them.
 */
template <typename Field, typename... FieldsType>
class EnumMap
{
public:
	/// TODO: Implement all requirements for standard container

	/// Tuple for storing type of variables
	typedef std::tuple<FieldsType...> TypesContainer;

	/// Type declaration for storing type of variables
	template <Field field>
	using FieldType = typename std::tuple_element<field, TypesContainer>::type;

	/// TODO: Will change to std::optional in C++14
	template <Field field>
	using FieldTypeOptional = boost::optional<FieldType<field>>;

	/// Default action for constructor is appropriate
	EnumMap() = default;

	/// Default action in copy situation is appropriate
	EnumMap(const EnumMap&) = default;

	/// Default action in move situation is appropriate
	EnumMap(EnumMap&&) = default;

	/// Default action for destructor is appropriate
	~EnumMap() = default;

	/// @return Corresponding value for given field
	template <Field field>
	FieldType<field> get() const;

	/**
	 * Gets the given field value if exists and will not throw exception if not found.
	 *
	 * @tparam Determines which field of enum map is needed
	 * @param nothrow Is not used in the function definition and just seperates the function signature from the one
	 * with exception support.
	 *
	 * @return An optional corresponding value for given field. Returned value could be considered as a boolean to see
	 * if value exists and real value could be got with '*' operator.
	 */
	template <Field field>
	FieldTypeOptional<field> get(std::nothrow_t nothrow) const noexcept;

	/// TODO: For non primitive type make reference input.
	// @value Value of field to be stored
	template <Field field>
	void set(FieldType<field> value);

private:
	/// Type declaration for storing Types and their corresponding values
	typedef std::map<Field, boost::any> FieldsContainer;

	/// Key-value data storing place
	FieldsContainer fields_map;
};

#include "EnumMap-inl.h"

#endif
