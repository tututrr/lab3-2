#include <gtest/gtest.h>
#include "hashtable.cpp"

TEST(hashtable, test1)
{
    HashTable<int, int> hash_table(5);
    hash_table.insert(1, 2);
    hash_table.insert(1, 3);
    hash_table.insert(2, 8);
    hash_table.insert(4, 9);
    hash_table.search(1);
    hash_table.remove(8);
    hash_table.remove(5);

    bool expected = true;
    bool actual = hash_table.search(4);
    GTEST_ASSERT_EQ(expected, actual);
}

TEST(hashtable, test2)
{
    HashTable<int, int> hash_table(5);
    hash_table.insert(1, 2);
    hash_table.insert(1, 3);
    hash_table.insert(2, 8);
    hash_table.insert(4, 9);
    hash_table.search(1);
    hash_table.remove(8);
    hash_table.remove(1);

    bool expected = false;
    bool actual = hash_table.search(1);
    GTEST_ASSERT_EQ(expected, actual);
}

TEST(hashtable, test3)
{
    HashTable<int, int> hash_table(2);
    hash_table.insert(1, 2);
    hash_table.insert(2, 3);
    hash_table.insert(2, 8);
    hash_table.insert(4, 9);
    hash_table.search(1);
    hash_table.remove(8);
    hash_table.remove(5);

    bool expected = true;
    bool actual = hash_table.search(4);
    GTEST_ASSERT_EQ(expected, actual);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
