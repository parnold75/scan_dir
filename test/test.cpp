#include <gtest/gtest.h>
#include <scan_dir.hpp>
#include <boost/filesystem.hpp>
#include <functional>
#include <iostream>

/**
 * 
 */
TEST(ScanDirTest, Scan)
{
    using boost::filesystem::path;

    path p("/home");

    scan_dir(
        p,
        [](boost::filesystem::path dp) {},
        [](boost::filesystem::path fp) {},
        [](boost::filesystem::path p, boost::filesystem::filesystem_error e) { std::cout << p << std::endl; });
}

/**
 * Run all tests
 * 
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
