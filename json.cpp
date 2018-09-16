#include "Json.hpp"


Json::Json(const std::string& s) {
	int string_counter = 0;
	std::string onekey;
	std::string onemeaning;
	std::string onearray;
	std::string onejson;
	while ((s[string_counter] != '{') && (s[string_counter] != '['))
		string_counter++;
	if (s[string_counter] == '[') {
		while (true) {
			string_counter++;
			while (s[string_counter] == ' ')
				string_counter++;
			switch (s[string_counter]) {
			case '"': {
				string_counter++;
				while (s[string_counter] != '"')
				{
					onearray += s[string_counter];
					string_counter++;
				}
				array.push_back(onearray);
				onearray = "";
				string_counter++;
				while ((s[string_counter] != ',') && (s[string_counter] != ']'))
					string_counter++;
				if (s[string_counter] == ']') return;
			}
					  break;
			case '{': {
				while (s[string_counter] != '}') {
					onejson += s[string_counter];
					string_counter++;
				}
				onejson += s[string_counter];
				string_counter++;
				Json json1(onejson);
				array.push_back(json1);
				onejson = "";
				while ((s[string_counter] != ',') && (s[string_counter] != ']')) {
					string_counter++;
				}
				if (s[string_counter] == ']') return;
			}
					  break;

			case 'f': {
				array.push_back(false);
				while ((s[string_counter] != ',') && (s[string_counter] != ']'))
					string_counter++;
				if (s[string_counter] == ']') return;
			}
					  break;
			case 't': {
				array.push_back(true);
				while ((s[string_counter] != ',') && (s[string_counter] != ']'))
					string_counter++;
				if (s[string_counter] == ']') return;
			}
					  break;

			case '[': {
				while (s[string_counter] != ']') {
					onejson += s[string_counter];
					string_counter++;
				}
				onejson += s[string_counter];
				string_counter++;
				Json json1(onejson);
				array.push_back(json1);
				onejson = "";
				while ((s[string_counter] != ',') && (s[string_counter] != ']')) {
					string_counter++;
				}
				if (s[string_counter] == ']') return;
			}
					  break;
			default: {
				std::string onenumber;
				while (s[string_counter] != ',') {
					if (s[string_counter] == ']') break;
					onenumber += s[string_counter];
					string_counter++;
				}
				array.push_back(atof(onenumber.c_str()));
				while ((s[string_counter] != ',') && (s[string_counter] != ']')) {
					string_counter++;
				}
				if (s[string_counter] == ']') return;
			}
					 break;
			}
		}
	}
	if (s[string_counter] == '{') {
		while (true) {
			while (s[string_counter] != '"') string_counter++;
			string_counter++;
			int i = 0;
			while (s[string_counter] != '"') {
				onekey += s[string_counter];
				string_counter++;
			}
			keys.push_back(onekey);
			onekey = "";
			while (s[string_counter] != ':') string_counter++;
			string_counter++;
			while (s[string_counter] == ' ') string_counter++;
			switch (s[string_counter]) {
			case '"': {
				string_counter++;
				while (s[string_counter] != '"') {
					onemeaning += s[string_counter];
					string_counter++;
				}
				meanings.push_back(onemeaning);
				onemeaning = "";
				while ((s[string_counter] != ',') && (s[string_counter] != '}')) {
					string_counter++;
				}
				if (s[string_counter] == '}') return;
				string_counter++;
			};
					  break;
			case '[': {
				while (s[string_counter] != ']') {
					onearray += s[string_counter];
					string_counter++;
				}
				onearray += s[string_counter];
				Json json1(onearray);
				meanings.push_back(json1);
				onearray = "";
				while ((s[string_counter] != ',') && (s[string_counter] != '}')) {
					string_counter++;
				}
				if (s[string_counter] == '}') return;
				string_counter++;
			};
					  break;
			case '{': {
				while (s[string_counter] != '}') {
					onejson += s[string_counter];
					string_counter++;
				}
				onejson += s[string_counter];
				string_counter++;
				Json json1(onejson);
				meanings.push_back(json1);
				onejson = "";
				while ((s[string_counter] != ',') && (s[string_counter] != '}')) {
					string_counter++;
				}
				if (s[string_counter] == '}') return;
				string_counter++;
			};
					  break;
			case 'f': {
				bool meaning = false;
				meanings.push_back(meaning);
				while ((s[string_counter] != ',') && (s[string_counter] != '}')) {
					string_counter++;
				}
				if (s[string_counter] == '}') return;
				string_counter++;
			};
					  break;
			case 't': {
				bool meaning = true;
				meanings.push_back(meaning);
				while ((s[string_counter] != ',') && (s[string_counter] != '}')) {
					string_counter++;
				}
				if (s[string_counter] == '}') return;
				string_counter++;
			};
					  break;
			default: {
				std::string onenumber;
				while (s[string_counter] != ',') {
					if (s[string_counter] == '}') break;
					onenumber += s[string_counter];
					string_counter++;
				}
				meanings.push_back(atof(onenumber.c_str()));
				while ((s[string_counter] != ',') && (s[string_counter] != '}')) {
					string_counter++;
				}
				if (s[string_counter] == '}') return;
				string_counter++;
			};
					 break;
			}
		}
	}
};

bool Json::is_array() const {
	if (array.size() != 0) return true;
	for (int i = 0; i < meanings.size(); i++) {
		if (meanings[i].type() == typeid(Json)) {
			Json json1 = std::any_cast<Json>(meanings[i]);
			if (json1.is_array()) return true;
		}
	}
	return false;
};

bool Json::is_object() const {
	if (keys.size() != 0) return true;
	for (int i = 0; i < array.size(); i++) {
		if (array[i].type() == typeid(Json)) {
			Json json1 = std::any_cast<Json>(array[i]);
			if (json1.is_object()) return true;
		}
	}
	return false;
};

std::any& Json::operator[](const std::string& key) {
	if (keys.size() == 0) throw Error();
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == key)
			return meanings[i];
	}
}
std::any& Json::operator[](int index) {
	if (array.size() == 0) throw Error();
	return array[index];
}
