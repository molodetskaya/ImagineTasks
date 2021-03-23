#include <Rotation.hpp>

int MaxSimilarSequenceFromBegin(const std::string & first, const std::string & second, std::string & res) {
  auto stringSize = first.size();
  auto firstSymbol = first[0];
  auto lastSymbol = first[stringSize - 1];
  uint32_t pos = 0;

  while (pos < stringSize) {
    pos = second.find(firstSymbol, pos+1);
    if (pos >= stringSize) {
      return -1;
    }
    if ((pos != 0 && lastSymbol == second[pos-1]) || lastSymbol == second[stringSize-1]) {
      auto size = 0;
      for (uint32_t i = pos; first[i - pos] == second[i] && i < stringSize; ++i) {
        ++size;
      }
      res = second.substr(pos, size);
      return pos;
    }
  };
  return -1;
}

bool IsRotationStrings(const std::string& first, const std::string& second) {

  if (first.size() != second.size()) {
    return false;
  }

  if (first == second) {
    return true;
  }

  std::string similarSequence;
  auto similarSequenceStart1 = 0;
  auto similarSequenceStart2 = MaxSimilarSequenceFromBegin(first, second, similarSequence);

  if (similarSequenceStart2 < 0) {
    return false;
  }

  auto similarSequenceEnd1 = similarSequenceStart1 + similarSequence.size();
  auto result1 = first.substr(similarSequenceEnd1, first.size() - similarSequenceEnd1);

  auto similarSequenceEnd2 = similarSequenceStart2 + similarSequence.size();
  auto beforeIntersection = second.substr(similarSequenceEnd2, second.size() - similarSequenceEnd2);
  auto afterIntersection = second.substr(0, similarSequenceStart2);
  auto result2 = beforeIntersection + afterIntersection;

  return result1 == result2;

}