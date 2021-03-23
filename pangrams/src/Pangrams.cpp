#include <Pangrams.hpp>

#include <algorithm>
#include <vector>


std::string GeneratePangramsDifference(const std::string& input) {
  std::vector<bool> counter('Z'-'A'+1, false);

  for_each(input.begin(), input.end(), [&](unsigned char c) {
    int index = std::toupper(c) - 'A';
    if (index>=0 && index < counter.size() && !counter[index]) {
      counter[index] = true;
    }
  });

  std::string diff;
  for( int i=0; i < counter.size(); i++) {
    if (!counter[i]) {
      diff += i + 'A';
    }
  }

  return diff;
}