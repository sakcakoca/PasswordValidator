#include "gtest/gtest.h"
#include "passwordvalidator.hpp"

TEST(PasswordValidatorTest, ReturnsErrorForPasswordsShorterThan8Chars)
{
    ASSERT_THROW(PasswordValidator::isValid(""), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("1"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("12"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("123"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("1234"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("12345"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("123456"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("1234567"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("ABCDEFG"), InvalidPasswordException);
}

TEST(PasswordValidatorTest, ReturnsErrorForPasswordsDoNotIncludeAtLeast2Numbers)
{
    ASSERT_THROW(PasswordValidator::isValid("ABCDEFGH"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("ABCDEFG1"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("1BCDEFGH"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("AB1DEFGH"), InvalidPasswordException);

}

TEST(PasswordValidatorTest, ReturnsErrorForPasswordsDoNotIncludeAtLeast1CapitalLetter)
{
    ASSERT_THROW(PasswordValidator::isValid("abcdefgh12"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("ab1cdefgh2"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("aaaaaaaaaa"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("zzzzzzzzzz"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("1111111111"), InvalidPasswordException);
}

TEST(PasswordValidatorTest, ReturnsErrorForPasswordsDoNotIncludeAtLeast1SpecialCharacter)
{
    ASSERT_THROW(PasswordValidator::isValid("Abcdefgh12"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("AB1CDEFGH2"), InvalidPasswordException);
    ASSERT_THROW(PasswordValidator::isValid("AB1CDEFG23"), InvalidPasswordException);
}

TEST(PasswordValidatorTest, ReturnTrueForValidPasswords)
{
    ASSERT_TRUE(PasswordValidator::isValid("Abcdefgh12_"));
    ASSERT_TRUE(PasswordValidator::isValid("*Abcdefgh12"));
    ASSERT_TRUE(PasswordValidator::isValid("Abc.defgh12"));
    ASSERT_TRUE(PasswordValidator::isValid("1Abcd,efgh2"));
    ASSERT_TRUE(PasswordValidator::isValid("12Abcdef<gh"));
    ASSERT_TRUE(PasswordValidator::isValid("12AbcDef<gh>"));
}