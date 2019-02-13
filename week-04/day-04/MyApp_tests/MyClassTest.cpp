#include <gtest/gtest.h>
#include "MyClass.h"

TEST(MyClass, TestCharacters)
{
    // Arrange
    std::string apple = "appl";
    MyClass checker;

    // Act
    std::string result = checker.getApple();

    // Assert
    ASSERT_EQ(result, "apple");
}