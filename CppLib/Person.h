#pragma once
using json = nlohmann::json;	//to improve!
using std::string;
using std::to_string;
using std::ostream;
using std::unordered_map;
using std::function;
using std::pair;



class Person
{
public:
	int id;
	string first_name;
	string last_name;
	string email;
	string gender;
	string ip_address;

private:
	unordered_map<string, function<void(string const&)>> setValueMap{
		pair("id",[&](string const& value)-> void { id = stoi(value); })
		, pair("first_name",[&](string const& value)-> void { first_name = value; })
		, pair("last_name",[&](string const& value)-> void { last_name = value; })
		, pair("email",[&](string const& value)-> void { email = value; })
		, pair("gender",[&](string const& value)-> void { gender = value; })
		, pair("ip_address",[&](string const& value)-> void { ip_address = value; })
	};

public:
	void setValue(string const& key, string const& value) { setValueMap[key](value); };
private:
	string print() const;
public:
	friend ostream& operator<<(ostream& os, Person const& p);
};

