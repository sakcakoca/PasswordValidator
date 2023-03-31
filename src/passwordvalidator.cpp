#include <sstream>
#include "passwordvalidator.hpp"

bool PasswordValidator::isValid(std::string_view password)
{
    std::ostringstream errorText;

    if(!isLengthValid(password))
        errorText << "Password must be at least " << minPasswordLength << " characters\n";

    if(!isNumberCountValid(password))
        errorText << "The password must contain at least " << minNumberCountInPassword << " numbers\n";

    if(!isCapitalLetterCountValid(password))
        errorText << "The password must contain at least " << minCapitalLetterCount << " capital letter\n";

    if(!isSpecialCharacterCountValid(password))
        errorText << "The password must contain at least " << minSpecialCharacterCount << " special character\n";

    if(!errorText.str().empty())
        throw InvalidPasswordException(errorText.str());

    return true;
}

bool PasswordValidator::isLengthValid(std::string_view password)
{
    return password.length() >= minPasswordLength;
}

bool PasswordValidator::isNumberCountValid(std::string_view password)
{
    int numberCount = 0;
    for (const char character : password)
    {
        if(CharacterChecker::isNumeric(character))
            numberCount++;
    }
    
    return numberCount >= minNumberCountInPassword;
}

bool PasswordValidator::isCapitalLetterCountValid(std::string_view password)
{
    int capitalLetterCount = 0;
    for (const char character : password)
    {
        if(CharacterChecker::isCapitalLetter(character))
            capitalLetterCount++;
    }
    
    return capitalLetterCount >= minCapitalLetterCount;
}

bool PasswordValidator::isSpecialCharacterCountValid(std::string_view password)
{
    int specialCharacterCount = 0;
    for (const char character : password)
    {
        if(CharacterChecker::isSpecialCharacter(character))
            specialCharacterCount++;
    }

    return specialCharacterCount >= minSpecialCharacterCount;
}
