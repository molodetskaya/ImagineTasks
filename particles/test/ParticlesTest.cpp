#include <gtest/gtest.h>
#include <Particles.hpp>

struct ParticlesParam {
  std::string input;
  int speed;
  std::vector<std::string> result;
};

class ParticlesTest : public ::testing::TestWithParam<ParticlesParam> {

};

TEST_P(ParticlesTest, OneParticleMoveTest) {
  auto param = GetParam();
  Particles part(param.input, param.speed);
  for (std::string result : param.result) {
    ASSERT_EQ(result, part.GetParticles());
    part.MoveParticlesCycle();
  }
  ASSERT_TRUE(part.IsAnimationFinished());
}

INSTANTIATE_TEST_CASE_P(
  ParticlesTest, ParticlesTest, ::testing::Values(

    ParticlesParam{ "..R.......", 2, std::vector<std::string>{ "..X.......", "....X.....", "......X...", "........X.", ".........." } },
    ParticlesParam{ "RR..LRL", 3, std::vector<std::string>{ "XX..XXX", ".X.XX..", "X.....X", "......."} },
    ParticlesParam{ "LRLR.LRLR", 2, std::vector<std::string>{ "XXXX.XXXX", "X..X.X..X", ".X.X.X.X.", ".X.....X.", "........." } },
    ParticlesParam{ "RLRLRLRLRL", 10, std::vector<std::string>{"XXXXXXXXXX", ".........."} },
    ParticlesParam{ "...", 1, std::vector<std::string>{"..."} },

    ParticlesParam{ "LRRL.LR.LRR.R.LRRL.", 1,
      std::vector<std::string> {
        "XXXX.XX.XXX.X.XXXX.",
        "..XXX..X..XX.X..XX.",
        ".X.XX.X.X..XX.XX.XX",
        "X.X.XX...X.XXXXX..X",
        ".X..XXX...X..XX.X..",
        "X..X..XX.X.XX.XX.X.",
        "..X....XX..XX..XX.X",
        ".X.....XXXX..X..XX.",
        "X.....X..XX...X..XX",
        ".....X..X.XX...X..X",
        "....X..X...XX...X..",
        "...X..X.....XX...X.",
        "..X..X.......XX...X",
        ".X..X.........XX...",
        "X..X...........XX..",
        "..X.............XX.",
        ".X...............XX",
        "X.................X",
        "..................."
      }
    }
  )
);