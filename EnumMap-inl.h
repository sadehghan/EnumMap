#ifndef ENUM_MAP_INL_H_
#define ENUM_MAP_INL_H_

#ifndef ENUM_MAP_H_
#error "EnumMap-inl.h" should be included only in "EnumMap.h" file
#endif

#include "EnumMap.h"

template <typename Field, typename... FieldsType>
template <Field field>
auto EnumMap<Field, FieldsType...>::get() const -> FieldType<field>
{
	return boost::any_cast<EnumMap::FieldType<field>>(fields_map.at(field));
}

template <typename Field, typename... FieldsType>
template <Field field>
auto EnumMap<Field, FieldsType...>::get(std::nothrow_t) const noexcept -> FieldTypeOptional<field>
{
	typename FieldsContainer::const_iterator cit = fields_map.find(field);
	if (cit == fields_map.end())
		return boost::none;
	else
		return FieldTypeOptional<field>(boost::any_cast<EnumMap::FieldType<field>>(cit->second));
}

template <typename Field, typename... FieldsType>
template <Field field>
void EnumMap<Field, FieldsType...>::set(FieldType<field> value)
{
	fields_map[field] = static_cast<boost::any>(value);
}

#endif
