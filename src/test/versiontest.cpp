#include <selfupdate/version/version.hpp>
#include <gtest/gtest.h>

class VersionTest : public::testing::Test
{
protected:
    virtual void SetUp()
    {
        versionDataFromInts_ = SelfUpdate::Version::VersionData(1,2,3);
        versionDataFromStr_ = SelfUpdate::Version::VersionData(
            "ThisIsATest_2.3.4.exe");    
    }

    SelfUpdate::Version::VersionData versionDataFromInts_;
    SelfUpdate::Version::VersionData versionDataFromStr_;
    SelfUpdate::Version::VersionData version100_;

};

TEST_F(VersionTest, Constructor)
{

    EXPECT_EQ(versionDataFromInts_.getMajor(), 1);
    EXPECT_EQ(versionDataFromInts_.getMinor(), 2);
    EXPECT_EQ(versionDataFromInts_.getMinor(), 3);

    EXPECT_EQ(versionDataFromStr_.getMajor(), 2);
    EXPECT_EQ(versionDataFromStr_.getMinor(), 3);
    EXPECT_EQ(versionDataFromStr_.getMinor(), 4);

}

TEST_F(VersionTest, GetterSetter)
{
    
    version100_.setMajor(1);
    version100_.setMinor(0);
    version100_.setPatch(0);

    EXPECT_EQ(version100_.getMajor(), 1);
    EXPECT_EQ(version100_.getMinor(), 0);
    EXPECT_EQ(version100_.getMinor(), 0);

}

TEST_F(VersionTest, Equality)
{

    EXPECT_TRUE(version100_ == version100_);

    EXPECT_TRUE(version100_ != versionDataFromInts_);
    
    EXPECT_TRUE(version100_ < versionDataFromInts_);
    EXPECT_TRUE(version100_ < versionDataFromStr_);

    EXPECT_TRUE(versionDataFromInts_ >= version100_);
    EXPECT_TRUE(versionDataFromStr_ >= version100_);

}