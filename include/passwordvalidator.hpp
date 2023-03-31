#include <string_view>
#include <string>
#include <exception>

class PasswordValidator
{
public:
    /// @brief Checks if given password is valid or not. If given password is not appropriate, function will throw exception.
    /// @param password is the string argument which is a password candidate.
    /// @return Given password string is valid or not.
    static bool isValid(std::string_view password);

private:
    static bool isLengthValid(std::string_view password);
    static bool isNumberCountValid(std::string_view password);
    static bool isCapitalLetterCountValid(std::string_view password);
    static bool isSpecialCharacterCountValid(std::string_view password);
   
    static constexpr size_t minPasswordLength = 8;
    static constexpr size_t minNumberCountInPassword = 2;
    static constexpr size_t minCapitalLetterCount = 1;
    static constexpr size_t minSpecialCharacterCount = 1;
};

class InvalidPasswordException : public std::exception 
{
public:
    explicit InvalidPasswordException(std::string msg) : message(std::move(msg)) {}

    [[nodiscard]] const char *what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;
};

class CharacterChecker
{
public:
    static bool isNumeric(char character){ 
        return (character >= '0') && (character <= '9'); 
    }
    
    static bool isCapitalLetter(char character){ 
        return (character >= 'A') && (character <= 'Z'); 
    }

    static bool isLowerCaseLetter(char character){ 
        return (character >= 'a') && (character <= 'z'); 
    }

    static bool isSpecialCharacter(char character){
        return !isCapitalLetter(character) && !isLowerCaseLetter(character) && !isNumeric(character);
    }
};