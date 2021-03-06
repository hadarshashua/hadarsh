#include "User.h"

static bool checkLettersAndNumbersOnly(const char* str);
static bool userNameAboveMinSize(const char* name);
static bool passwordInCorrectLength(const char* pass);

User::User(char* userName, const char* password, Address* address)//constructor
{
	strcpy(this->userName, userName);
	strcpy(this->password, password);
	this->address = new Address(*address);
}

User::User(const User& other)//copy c'tor
{
	strcpy(this->userName, other.userName);//copying Other username
	strcpy(this->password, other.password);//copying Other password
	this->address = new Address(*other.address);//copy c'tor 
}

User::User(User&& other)//move c'tor
{
	strcpy(this->userName, other.userName);
	other.setUserName(NULL);
	strcpy(this->password, other.password);
	other.setPassword(NULL);

	this->address = other.address;//will point to other.address -by pointer 
	other.address = NULL;
}

User::~User()//destructor
{
	delete address;
}


bool User::setUserName(const char* name) 
{
	if (checkLettersAndNumbersOnly(name) && userNameAboveMinSize(name)) //checks that the name is right by the rules
	{
		strcpy(userName, name);
		return true;
	}
	return false; //Didnt pass the check (and the dinamic string (TempPassWord) will be released)
}

bool User::setPassword(const char* password)
{
	if (checkLettersAndNumbersOnly(password) && passwordInCorrectLength(password)) //checks that the password is right by the rules
	{
		strcpy(this->password, password);
		return true;
	}
	return false; //Didnt pass the check (and the dinamic string (TempPassWord) will be released afterwards)
}

void User::setAddress(Address& address)
{
	this->address = new Address(address);//will point to the new address
}

const char* User::getUserName() const
{
	return userName;
}

const char* User::getPassword() const
{
	return password;
}

Address* User::getAddress() const
{
	return address;
}


static bool checkLettersAndNumbersOnly(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 48) || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122))//checking if there is any char that dosent contain a digit or letter 
			return false;
	}
	return true;
}

static bool userNameAboveMinSize(const char* name)//Check if user name is not longer than 20 letters
{
	int size = strlen(name);
	if (size >= 6)
		return true;
	return false;
}

static bool passwordInCorrectLength(const char* pass)//Check if password has exactly 8 characters
{
	int size = strlen(pass);
	if (size == PASSWORD_LENGTH-1)
		return true;
	return false;
}