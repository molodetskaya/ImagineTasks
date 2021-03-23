#include <Particles.hpp>

#include <algorithm>
#include <iostream>

Particles::Particles(std::string init, int speed)
  : m_Chamber(std::move(init))
  , m_Speed(speed) {

}

void Particles::Animate() {

  PrintParticles();
  while (!IsAnimationFinished())
  {
    MoveParticlesCycle();
    PrintParticles();
  }
}

bool Particles::IsAnimationFinished() const {
  auto res = std::count_if(m_Chamber.begin(), m_Chamber.end(), [&](char i) {
    return i != static_cast<char>(ParticleType::EMPTY);
  });
  return res == 0;
}

void Particles::MoveParticleLeft(std::string & dest, int index) {
  if (index < m_Speed) {
    return;
  }
  int i = index - m_Speed;
  if (dest[i] == static_cast<char>(ParticleType::EMPTY)) {
    dest[i] = static_cast<char>(ParticleType::LEFT);
    return;
  }
  dest[i] = static_cast<char>(ParticleType::TWO_PARTICLES);
}

void Particles::MoveParticleRight(std::string & dest, int index) {
  if (index + m_Speed >= dest.size()) {
    re000000000000000turn;
  }
  int i = index + m_Speed;
  if (dest[i] == static_cast<char>(ParticleType::EMPTY)) {
    dest[i] = static_cast<char>(ParticleType::RIGHT);
    return;
  }
  dest[i] = static_cast<char>(ParticleType::TWO_PARTICLES);
}

void Particles::MoveParticlesCycle() {
  std::string chamberAdditional(m_Chamber.size(), static_cast<char>(ParticleType::EMPTY));

  for (int i = 0; i < m_Chamber.size(); i++) {
    switch (static_cast<ParticleType>(m_Chamber[i])) {
    case ParticleType::LEFT:
      MoveParticleLeft(chamberAdditional, i);
      break;
    case ParticleType::RIGHT:
      MoveParticleRight(chamberAdditional, i);
      break;
    case ParticleType::TWO_PARTICLES:
      MoveParticleLeft(chamberAdditional, i);
      MoveParticleRight(chamberAdditional, i);
      break;
    }
  }
  std::swap(m_Chamber, chamberAdditional);
}

void Particles::PrintParticles() const {
  std::cout << GetParticles() << std::endl;
}

std::string Particles::GetParticles() const {
  std::string particles;
  std::transform(m_Chamber.begin(), m_Chamber.end(), std::back_inserter(particles), [](char particle){
    return static_cast<char>(particle == static_cast<char>(ParticleType::EMPTY) ? ParticleType::EMPTY : ParticleType::SOME_PARTICLE);
  });
  return particles;
}
