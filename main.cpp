#include <Pangrams.hpp>
#include <Rotation.hpp>
#include <Particles.hpp>

#include <iostream>

int main()
{
  std::string res;
  auto str1 = "helloworld";
  auto str2 = "elloworldh";
  if (IsRotationStrings(str1, str2)) {
    std::cout << str1 << " and " << str2 << " are rotated strings" <<std::endl;
  }
  else {
    std::cout << str1 << " and " << str2 << " are not rotated strings" << std::endl;
  }

  std::string test = "A quick bron fox jumps over the lazy dog";
  std::cout << "\nIs Pangram :"<< test << std::endl;
  std::cout << "PangramsDifference " << GeneratePangramsDifference(test)<< test <<std::endl;

  std::string init = "LRRL.LR.LRR.R.LRRL.";
  std::cout << "\nParticles input = \"" << init << "\"" << std::endl;
  Particles particles(std::move(init), 1);
  particles.Animate();

  return 0;
}