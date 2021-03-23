#include <gtest/gtest.h>
#include <Pangrams.hpp>

struct PangramsParam {
  std::string result;
  std::string input;
};

class PangramsTest : public ::testing::TestWithParam<PangramsParam> {

};

TEST_P(PangramsTest, PangramsParamsTest) {
  const auto param = GetParam();
  std::string res = GeneratePangramsDifference(param.input);
  ASSERT_EQ(param.result, res);
}

INSTANTIATE_TEST_CASE_P(
  PangramsTest, PangramsTest, ::testing::Values(

    PangramsParam{ "", "A quick brown fox jumps over the lazy dog" },
    PangramsParam{ "W", "A quick bron fox jumps over the lazy dog" },
    PangramsParam{ "CIKQ", "A brown fox jumps over the lazy dog" },
    PangramsParam{ "A", "quick brown fox jumps over the lzy dog" },
    PangramsParam{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "" }
  )
);