#include <iostream>
#include <string>
#include <simdjson.h>

std::string serialize_json(simdjson::dom::element element) {
	std::string ret;
  switch (element.type()) {
    case simdjson::dom::element_type::ARRAY:
      ret += "[";
      for (simdjson::dom::element child : simdjson::dom::array(element)) {
        ret += serialize_json(child);
        ret += ",";
      }
      ret += "]";
      break;
    case simdjson::dom::element_type::OBJECT:
      ret += "{";
      for (simdjson::dom::key_value_pair field : simdjson::dom::object(element)) {
        ret += "\"" + std::string(std::string_view(field.key)) + "\":";
        ret += serialize_json(field.value);
      }
      ret += "}";
      break;
    case simdjson::dom::element_type::INT64:
      ret += std::to_string(int64_t(element));
      break;
    case simdjson::dom::element_type::UINT64:
      ret += std::to_string(uint64_t(element));
      break;
    case simdjson::dom::element_type::DOUBLE:
      ret += std::to_string(double(element));
      break;
    case simdjson::dom::element_type::STRING:
      ret += std::string(std::string_view(element));
      break;
    case simdjson::dom::element_type::BOOL:
      ret += std::to_string(bool(element));
      break;
    case simdjson::dom::element_type::NULL_VALUE:
      ret += "null";
      break;
  }
	return ret;
}
