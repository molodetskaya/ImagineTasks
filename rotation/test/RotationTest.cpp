#include <gtest/gtest.h>

#include <Rotation.hpp>


struct RotationStringParam {
  bool result;
  std::string first;
  std::string second;
};

class RotationTest : public ::testing::TestWithParam<RotationStringParam> {

};


TEST_P(RotationTest, RotationParamsTest) {
  const auto param = GetParam();
  ASSERT_EQ(param.result, IsRotationStrings(param.first, param.second));
}

INSTANTIATE_TEST_CASE_P(
  RotationTest, RotationTest, ::testing::Values(

    RotationStringParam{ true, "helloworld", "worldhello" },
    RotationStringParam{ false, "helloworld", "hellwoorld" },
    RotationStringParam{ true, "helloworld", "elloworldh" },
    RotationStringParam{ true, "helloworld", "lloworldhe" },
    RotationStringParam{ true, "helloworld", "loworldhel" },
    RotationStringParam{ true, "helloworld", "oworldhell" },
    RotationStringParam{ true, "loworldhel", "helloworld" },
    RotationStringParam{ true, "hellohelworld", "helworldhello" },
    RotationStringParam{ true, "helworldhello", "hellohelworld" }
  )
);


struct MaxSequenceParam {
  std::string result;
  std::string first;
  std::string second;
};

class MaxSequenceTest : public ::testing::TestWithParam<MaxSequenceParam> {

};


TEST_P(MaxSequenceTest, MaxSequenceParamsTest) {
  const auto param = GetParam();
  std::string res;
  MaxSimilarSequenceFromBegin(param.first, param.second, res);
  ASSERT_EQ(param.result, res);
}

INSTANTIATE_TEST_CASE_P(
  MaxSequenceTest, MaxSequenceTest, ::testing::Values(

    MaxSequenceParam{ "hello", "helloworld", "worldhello" },
    MaxSequenceParam{ "", "helloworld", "hellwoorld" },
    MaxSequenceParam{ "h", "helloworld", "elloworldh" },
    MaxSequenceParam{ "he", "helloworld", "lloworldhe" },
    MaxSequenceParam{ "hel", "helloworld", "loworldhel" },
    MaxSequenceParam{ "hell", "helloworld", "oworldhell" },
    MaxSequenceParam{ "loworld", "loworldhel", "helloworld" },
    MaxSequenceParam{ "hello", "hellohelworld", "helworldhello" },
    MaxSequenceParam{ "helworld", "helworldhello", "hellohelworld" }
  )
);
