#pragma once

#include <string>

class Particles {

  enum class ParticleType : char {
    EMPTY = '.',
    SOME_PARTICLE = 'X',
    LEFT = 'L',
    RIGHT = 'R',
    TWO_PARTICLES = 'T'
  };
  public:
    Particles(std::string init, int speed);
    Particles(const Particles& obj) = delete;
    Particles(Particles&& obj) = delete;
    ~Particles() = default;

    void Animate();
    bool IsAnimationFinished() const;
    void MoveParticlesCycle();
    void PrintParticles() const;
    std::string GetParticles() const;

  private:
    void MoveParticleLeft(std::string& dest, int index);
    void MoveParticleRight(std::string& dest, int index);

    std::string m_Chamber;
    int m_Speed;
};