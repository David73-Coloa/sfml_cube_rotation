/*
 * void drawCube( std::vector<sfPoint> &arrayOfPoints, std::vector<sf::Vertex> lines) {
    configurePoints(arrayOfPoints.size(), arrayOfPoints); 
    configureCubeLines();
    window.draw(lines.data(), lines.size(), sf::PrimitiveType::Lines);
    for (int i=0; i<8; i++) {
      window.draw(arrayOfPoints[i]); 
    } 
  } 
 */  

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#define smallRatio 6
#define positionY 700
#define positionX 400

#define positionY2 500
#define positionX2 400 
struct Point {
  float x; 
  float y;
};
PointA {pointA.x, pointA.y};
PointB {pointB.x, pointB.y};
PointC {pointC.x, pointC.y};
PointD {pointD.x, pointD.y};

PointE {pointE.x, pointE.y};
PointF {pointF.x, pointF.y};
PointG {pointG.x, pointG.y};
PointH {pointH.x, pointH.y};
int main() {
  

  auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
  window.setFramerateLimit(144);
  std::array line1 = { // AB
    sf::Vertex{sf::Vector2f(pointAc.x, pointAc.y)},
    sf::Vertex{sf::Vector2f(positionX*2+50, pointAc.y)}
  };
  std::array line2 = { // CD
    sf::Vertex{sf::Vector2f(positionX, positionY)}, // C
    sf::Vertex{sf::Vector2f(positionX*2, positionY)} // D
  };
  std::array line3 = { // EF
    sf::Vertex{sf::Vector2f(positionX2+50, positionY2-50)}, // E
    sf::Vertex{sf::Vector2f(positionX2*2+50, positionY2-50)} // F
  };
  std::array line4 = { // GH
    sf::Vertex{sf::Vector2f(positionX2, positionY2)},
    sf::Vertex{sf::Vector2f(positionX2*2, positionY2)}
  };


  


  sf::CircleShape pointA(smallRatio);
  sf::CircleShape pointB(smallRatio);
  sf::CircleShape pointC(smallRatio);
  sf::CircleShape pointD(smallRatio);
  
  sf::CircleShape pointE(smallRatio);
  sf::CircleShape pointF(smallRatio);
  sf::CircleShape pointG(smallRatio);
  sf::CircleShape pointH(smallRatio);
  
  pointA.setPosition({pointAc.x, pointAc.y});
  pointB.setPosition({positionX*2+50, pointAc.y});
  pointC.setPosition({positionX*2, positionY});
  pointD.setPosition({positionX, positionY});

  pointA.setFillColor(sf::Color::Red);
  pointB.setFillColor(sf::Color::Blue);
  pointC.setFillColor(sf::Color::Yellow);
  pointD.setFillColor(sf::Color::Green);
  
  pointE.setPosition({positionX2+50, positionY2-50});
  pointF.setPosition({positionX2*2+50, positionY2-50});
  pointG.setPosition({positionX2*2, positionY2});
  pointH.setPosition({positionX2, positionY2});

  pointE.setFillColor(sf::Color::Red);
  pointF.setFillColor(sf::Color::Blue); 
  pointG.setFillColor(sf::Color::Yellow);
  pointH.setFillColor(sf::Color::Green);
  
  //window.draw(&point, 1, sf::Points);
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear();
    window.draw(lines.data(), lines.size(), sf::PrimitiveType::Lines);
    //window.draw(line2.data(), line2.size(), sf::PrimitiveType::Lines);
    //window.draw(line3.data(), line3.size(), sf::PrimitiveType::Lines);
    //window.draw(line4.data(), line4.size(), sf::PrimitiveType::Lines);

  /* window.draw(line5.data(), line5.size(), sf::PrimitiveType::Lines);
    window.draw(line6.data(), line6.size(), sf::PrimitiveType::Lines);
   window.draw(line7.data(), line7.size(), sf::PrimitiveType::Lines);
   // window.draw(line8.data(), line8.size(), sf::PrimitiveType::Lines);


    //window.draw(line3.data(), line3.size(), sf::PrimitiveType::Lines);

    //window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);*/



   window.draw(pointA);
    window.draw(pointB);
    window.draw(pointC);
    window.draw(pointD);

    window.draw(pointE);
    window.draw(pointF);
    window.draw(pointG);
    window.draw(pointH);

    window.display();
  }
}
