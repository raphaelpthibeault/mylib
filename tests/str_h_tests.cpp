#include <gtest/gtest.h>
#include <str.h>
#include <cstring>

TEST(init, When_ShouldInitString) {
    // Arrange
    char a_val[] = "abc";

    // Act
    String *a = init(a_val);

    // Assert
    ASSERT_STREQ(a->data, a_val);
    uninit(a);
}

TEST(s_equals_c, WhenEmptyStrings_ShouldReturnAsExpected) {
    // Arrange
    char a_val[] = "";
    char b_val[] = "";
    String *a = init(a_val);

    // Act and Assert
    ASSERT_TRUE(s_equals_c(a, b_val));
    uninit(a);
}

TEST(s_equals_s, WhenEmptyStrings_ShouldReturnAsExpected) {
    // Arrange
    char a_val[] = "";
    char b_val[] = "";
    String *a = init(a_val);
    String *b = init(b_val);

    // Act and Assert
    ASSERT_TRUE(s_equals_s(a, b));
    uninit(a);
    uninit(b);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
