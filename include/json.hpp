#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <stdlib.h>
#include <typeinfo>
#include <stdexcept>
class Json {
public:
	std::vector <std::string> keys;
	std::vector <std::any> meanings;
	std::vector <std::any> array;
	class Error {};
	Json(const std::string& s);
	bool is_array() const;
	bool is_object() const;
	std::any& operator[](const std::string& key);
	std::any& operator[](int index);
	static Json parse(const std::string& s) {
		std::string str;
		int count = 0;
		while (count != s.length()) {
			if (s[count] != '\n') {
				str += s[count];
			}
			count++;
		}
		std::cout << str << std::endl;
		Json json1(str);
		return json1;
	}
};
