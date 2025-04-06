#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <iterator>
#include <ostream>
#include <unistd.h>
#include <vector>
#include <iostream>
float smallRatio=6, SCREEN_WIDTH=2000, SCREEN_HEIGHT=2000;
struct Point {
  float x;
  float y;
};

class sfPoint : public sf::CircleShape { };
class Cube {
  float theta = 0; 
  sf::RenderWindow window;
  std::vector<sfPoint> sfCubeVector = std::vector<sfPoint>(8);
  std::vector<sfPoint> sfCartesianPoints = std::vector<sfPoint>(5);
  std::vector<sf::Vertex> cubeLines;
  std::vector<sf::Vertex> cartesianLines;
  std::vector<Point> cubePoints = {
    Point {SCREEN_WIDTH/8, SCREEN_HEIGHT/6},       // A
    Point {0, SCREEN_HEIGHT/3- 0},       // B -- green 
    Point {SCREEN_WIDTH/4, SCREEN_HEIGHT/3},       // C - blue 
    Point {SCREEN_WIDTH/3, SCREEN_HEIGHT/6},       // D - yellow 
    Point {SCREEN_WIDTH/8, SCREEN_HEIGHT/6 + SCREEN_HEIGHT/4},       // A
    Point {0, SCREEN_HEIGHT/3 + SCREEN_HEIGHT/4},                    // B -- green 
    Point {SCREEN_WIDTH/4, SCREEN_HEIGHT/3 + SCREEN_HEIGHT/4},       // C - blue 
    Point {SCREEN_WIDTH/3, SCREEN_HEIGHT/6 + SCREEN_HEIGHT/4},       // D - yellow 

  };
  std::vector<Point> cartesianPoints = {
    Point{0, SCREEN_HEIGHT/2}, // -x 
    Point{SCREEN_WIDTH, SCREEN_HEIGHT/2},  // x
    Point{SCREEN_WIDTH/2, SCREEN_HEIGHT}, // -y
    Point{SCREEN_WIDTH/2, 0}, // y
    Point{SCREEN_WIDTH/2,SCREEN_HEIGHT/2} // 0
  };

  public:
  Cube() { 
    setSfPoints(sfCubeVector, cubePoints);
    setSfPoints(sfCartesianPoints,cartesianPoints);
  }
  void setSfPoints(std::vector<sfPoint> &sfPoints, std::vector<Point> &points) {
    for (int i=0;i<sfPoints.size();i++) { 
      sfPoints[i].setPosition({points[i].x, points[i].y});
    }
  }

  void rotate() { 
    std::vector <sfPoint> rotatedPoints = std::vector <sfPoint>(8);
    for (int i=0;i<8;i++) {
      float x = (SCREEN_WIDTH/4)+(sfCubeVector[i].getPosition().x - SCREEN_WIDTH/2);
      float y = (SCREEN_WIDTH/4)+(sfCubeVector[i].getPosition().y - SCREEN_HEIGHT/2);
      Point rotatedPoint =  {
        (SCREEN_HEIGHT/2)+ (x * float(cos(theta)) - y * float(sin(theta))), // x
        (SCREEN_WIDTH/2) + (x * float(sin(theta)) + y * float(cos(theta))), // y
      };
      rotatedPoints[i].setPosition({rotatedPoint.x, rotatedPoint.y});
      rotatedPoints[i].setFillColor(sf::Color::Cyan);
      rotatedPoints[i].setRadius(smallRatio);
      window.draw(rotatedPoints[i]); 
    }
    auto lines = configureCubeLines(rotatedPoints);
    window.draw(lines.data(), lines.size(), sf::PrimitiveType::Lines);
    auto lines2 = configureCartesianLines(sfCartesianPoints);
    window.draw(lines2.data(), lines2.size(), sf::PrimitiveType::Lines);
    theta -=0.005; 
  }

  std::vector <sf::Vertex> configureCartesianLines(std::vector <sfPoint> sfCartesianVector) {
    return {
        sf::Vertex{sf::Vector2f(sfCartesianVector[0].getPosition().x, sfCartesianVector[0].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCartesianVector[1].getPosition().x, sfCartesianVector[1].getPosition().y)},

  
      sf::Vertex{sf::Vector2f(sfCartesianVector[2].getPosition().x, sfCartesianVector[2].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCartesianVector[3].getPosition().x, sfCartesianVector[3].getPosition().y)},

    }; 
  }
  std::vector <sf::Vertex> configureCubeLines(std::vector <sfPoint> sfCubeVector) {
  return {
    // Linha 1 (A -> B)
    sf::Vertex{sf::Vector2f(sfCubeVector[0].getPosition().x, sfCubeVector[0].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[1].getPosition().x, sfCubeVector[1].getPosition().y)},

    // Linha 2 (C -> D)
    sf::Vertex{sf::Vector2f(sfCubeVector[2].getPosition().x, sfCubeVector[2].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[3].getPosition().x, sfCubeVector[3].getPosition().y)},

    // Linha 3 (E -> F)
    sf::Vertex{sf::Vector2f(sfCubeVector[4].getPosition().x, sfCubeVector[4].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[5].getPosition().x, sfCubeVector[5].getPosition().y)},

    // Linha 4 (G -> H)
    sf::Vertex{sf::Vector2f(sfCubeVector[6].getPosition().x, sfCubeVector[6].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[7].getPosition().x, sfCubeVector[7].getPosition().y)},

    // Linha 5 (A -> D)
    sf::Vertex{sf::Vector2f(sfCubeVector[0].getPosition().x, sfCubeVector[0].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[3].getPosition().x, sfCubeVector[3].getPosition().y)},

    // Linha 6 (B -> C)
    sf::Vertex{sf::Vector2f(sfCubeVector[1].getPosition().x, sfCubeVector[1].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[2].getPosition().x, sfCubeVector[2].getPosition().y)},

    // Linha 7 (E -> H)
    sf::Vertex{sf::Vector2f(sfCubeVector[4].getPosition().x, sfCubeVector[4].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[7].getPosition().x, sfCubeVector[7].getPosition().y)},

    // Linha 8 (F -> G)
    sf::Vertex{sf::Vector2f(sfCubeVector[5].getPosition().x, sfCubeVector[5].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[6].getPosition().x, sfCubeVector[6].getPosition().y)},

    // Linha 9 (A -> E)
    sf::Vertex{sf::Vector2f(sfCubeVector[0].getPosition().x, sfCubeVector[0].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[4].getPosition().x, sfCubeVector[4].getPosition().y)},

    // Linha 5 (F -> B)
    sf::Vertex{sf::Vector2f(sfCubeVector[5].getPosition().x, sfCubeVector[5].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[1].getPosition().x, sfCubeVector[1].getPosition().y)},

    // Linha 11 (H -> D)
    sf::Vertex{sf::Vector2f(sfCubeVector[7].getPosition().x, sfCubeVector[7].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[3].getPosition().x, sfCubeVector[3].getPosition().y)},

    // Linha 12 (C -> G)
    sf::Vertex{sf::Vector2f(sfCubeVector[2].getPosition().x, sfCubeVector[2].getPosition().y)},
    sf::Vertex{sf::Vector2f(sfCubeVector[6].getPosition().x, sfCubeVector[6].getPosition().y)}  
    };
  }


 


  void start() {
    window = sf::RenderWindow(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "CMake SFML Project");
    window.setFramerateLimit(144);
    while (window.isOpen()) {
      while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
          window.close();
        }
      }    
      window.clear(); 
      rotate();
      window.display();
    }
  }

};



int main() {
  auto cube = new Cube;
  cube->start();
  return 0;

   
}
