

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>
#include <cmath>
#include <ostream>
#include <string>
#include <iostream>
#include <unistd.h>
#define spaceX 200
#define spaceY 250
#define smallRatio 4
#define positionY 700
#define positionX 400
#define positionYg 500
#define positionX2 400

struct Point {
  float x;
  float y;
};


class sfPoint : public sf::CircleShape {
  public:
    void configure(Point point, float ratio, std::string color) {
      this->setRadius(ratio);
      this->setPosition({point.x,point.y});
      if (color=="R") { this->setFillColor(sf::Color::Red); }
      if (color=="B")  { this->setFillColor(sf::Color::Blue); }
      if (color=="G") { this->setFillColor(sf::Color::Green); }
      if (color=="Y") { this->setFillColor(sf::Color::Yellow); }
    }
    void configure(Point point) {
      this->setPosition({point.x,point.y});
    }
};

class Cube {
  sf::RenderWindow window;
  std::array<sfPoint,8> sfPoints;
  std::array<sf::Vertex, 24> lines;
  sfPoint sfPointA;
  sfPoint sfPointB;
  sfPoint sfPointC;
  sfPoint sfPointD;
  sfPoint sfPointE;
  sfPoint sfPointF;
  sfPoint sfPointG;
  sfPoint sfPointH;

  public:
  void rotate() {
   float theta = 30;
    //rotatedPoint;
    for (int i=0;i<8;i++) {
      float x = sfPoints[i].getPosition().x;
      float y = sfPoints[i].getPosition().y;
      std::cout << "X:" << x;
      std::cout << "  Y:" << y;
      std::cout << "\n";
      Point rotatedPoint =  {
        x * float(cos(theta)) - y * float(sin(theta)),
        x * float(sin(theta)) + y * float(cos(theta)),
      };
      sfPoints[i].configure(rotatedPoint);
    } 
    //configureLines();
  }
  void configureLines() {
      lines = {
      // Linha 1 (A -> B)
      sf::Vertex{sf::Vector2f(sfPointA.getPosition().x, sfPointA.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointB.getPosition().x, sfPointB.getPosition().y)},

      // Linha 2 (C -> D)
      sf::Vertex{sf::Vector2f(sfPointC.getPosition().x, sfPointC.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointD.getPosition().x, sfPointD.getPosition().y)},

      // Linha 3 (E -> F)
      sf::Vertex{sf::Vector2f(sfPointE.getPosition().x, sfPointE.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointF.getPosition().x, sfPointF.getPosition().y)},

      // Linha 4 (G -> H)
      sf::Vertex{sf::Vector2f(sfPointG.getPosition().x, sfPointG.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointH.getPosition().x, sfPointH.getPosition().y)},

      // Linha 5 (A -> D)
      sf::Vertex{sf::Vector2f(sfPointA.getPosition().x, sfPointA.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointD.getPosition().x, sfPointD.getPosition().y)},

      // Linha 6 (B -> C)
      sf::Vertex{sf::Vector2f(sfPointB.getPosition().x, sfPointB.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointC.getPosition().x, sfPointC.getPosition().y)},

      // Linha 7 (E -> H)
      sf::Vertex{sf::Vector2f(sfPointE.getPosition().x, sfPointE.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointH.getPosition().x, sfPointH.getPosition().y)},

      // Linha 8 (F -> G)
      sf::Vertex{sf::Vector2f(sfPointF.getPosition().x, sfPointF.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointG.getPosition().x, sfPointG.getPosition().y)},

      // Linha 9 (A -> E)
      sf::Vertex{sf::Vector2f(sfPointA.getPosition().x, sfPointA.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointE.getPosition().x, sfPointE.getPosition().y)},

      // Linha 10 (F -> B)
      sf::Vertex{sf::Vector2f(sfPointF.getPosition().x, sfPointF.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointB.getPosition().x, sfPointB.getPosition().y)},

      // Linha 11 (H -> D)
      sf::Vertex{sf::Vector2f(sfPointH.getPosition().x, sfPointH.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointD.getPosition().x, sfPointD.getPosition().y)},

      // Linha 12 (C -> G)
      sf::Vertex{sf::Vector2f(sfPointC.getPosition().x, sfPointC.getPosition().y)},
      sf::Vertex{sf::Vector2f(sfPointG.getPosition().x, sfPointG.getPosition().y)}
      };
  }
  void configurePoints() {
    Point pointA =  {positionX+spaceX, positionY-spaceY};
    Point pointB {positionX*2+spaceX, positionY-spaceY};
    Point pointC  {positionX*2, positionY};
    Point pointD  {positionX, positionY};
    Point pointE  {positionX2+spaceX, positionYg-spaceY};
    Point pointF  {positionX2*2+spaceX, positionYg-spaceY};
    Point pointG  {positionX2*2, positionYg};
    Point pointH  {positionX2, positionYg};
     
    sfPointA.configure(pointA, smallRatio,"R");
    sfPointB.configure(pointB, smallRatio, "B");
    sfPointC.configure(pointC, smallRatio, "G");
    sfPointD.configure(pointD, smallRatio, "Y");

    sfPointE.configure(pointE, smallRatio, "R");
    sfPointF.configure(pointF, smallRatio, "B");
    sfPointG.configure(pointG, smallRatio, "G");
    sfPointH.configure(pointH, smallRatio, "Y");
    sfPoints = {
    sfPointA, sfPointB, sfPointC, sfPointD,
    sfPointE, sfPointF, sfPointG, sfPointH };
  }

  void draw() {
    configurePoints(); 
    configureLines();
    window.draw(lines.data(), lines.size(), sf::PrimitiveType::Lines);
    for (int i=0; i<8; i++) {
      window.draw(sfPoints[i]); 
    }
    
  } 

  void start() {
    window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
 sf::Clock clock;
    while (window.isOpen()) {
      while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
          window.close();
        }
      }
      float elapsedTime = clock.getElapsedTime().asSeconds();
        if (elapsedTime >= 2.0f) {
            sfPoints[0].setFillColor(sf::Color::Magenta); // Altera a cor após 2 segundos
        }

      window.clear();
std::cout << "Tempo: " << elapsedTime << "s - Cor do ponto A: " 
                  << (sfPoints[0].getFillColor() == sf::Color::Magenta? "Azul" : "Outro") 
                  << std::endl;
      draw();
      window.display();
    }
  }

};



int main() {
  auto cube = new Cube;
  cube->start();
  return 0;

   
}
