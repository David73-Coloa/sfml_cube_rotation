


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <array>
#include <cmath>
#include <ostream>
#include <string>
#include <iostream>
#include <unistd.h>

#define SCREEN_WIDTH 2000
#define SCREEN_HEIGHT 2000 

#define spaceX 200/5
#define spaceY 250/5
#define smallRatio 4
#define positionY 700*2/5
#define positionX 400*2/5
#define positionYg 500*2/5
#define positionX2 400*2/5

struct Point {
  float x;
  float y;
};

float convertDegreeToRadian(float degree) { return (degree*3.14)/180; }
Point rotatePoint(float x, float y, float degree) {
   float theta = convertDegreeToRadian(degree);
   Point rotatedPoint = { // swapped
     (x * float(sin(theta)) + y * float(cos(theta))),
    (x * float(cos(theta)) - y * float(sin(theta))),

   };
   return rotatedPoint;
 }



class sfPoint : public sf::CircleShape {
  public:
    void configure(Point point, float ratio, sf::Color color) {
      setRadius(ratio);
      setPosition({point.x,point.y});
      setFillColor(color);
      /*if (color=="R") { this->setFillColor(sf::Color::Red); }
      if (color=="B")  { this->setFillColor(sf::Color::Blue); }
      if (color=="G") { this->setFillColor(sf::Color::Green); }
      if (color=="Y") { this->setFillColor(sf::Color::Yellow); }*/
    }
    void configure(Point point) {
      this->setPosition({point.x,point.y});
    }
};
class Cube {
  sf::RenderWindow window;
  std::vector<sfPoint> sfCubePoints;
  std::vector<sfPoint> sfCartesianPoints;
  std::vector<sf::Vertex> cubeLines;
  std::vector<sf::Vertex> cartesianLines;
  /*std::vector<Point> cubePoints = {  // Usa point
    Point{b *cos(a),sin(a)},
    Point{b *cos(a+3.14*1/2),sin(a+3.14*1/2)},
    Point{b *cos(a+3.14*2/2),sin(a+3.14*2/2)},
    Point{b *cos(a+3.14*3/2),sin(a+3.14*3/2)},
    Point{b *cos(a+3.14*1/2),sin(a+3.14*1/2)-100},
    Point{b *cos(a+3.14*2/2),sin(a+3.14*2/2)-100},
    Point{b *cos(a+3.14*3/2),sin(a+3.14*3/2)-100},
    Point{b *cos(a+3.14*2/2),sin(a+3.14*2/2)-100},



  };*/
  /*std::vector<Point> cubePoints = {
    Point {positionX+spaceX, positionY-spaceY},
    Point {positionX*2+spaceX, positionY-spaceY},
    Point  {positionX*2, positionY},
    Point   {positionX, positionY},
    Point   {positionX2+spaceX, positionYg-spaceY},
    Point   {positionX2*2+spaceX, positionYg-spaceY},
    Point  {positionX2*2, positionYg},
    Point   {positionX2, positionYg},
  };*/ 
float theta=0;
 std::vector<Point> cubePoints = {
    Point {SCREEN_WIDTH/8, SCREEN_HEIGHT/6},       // A
    Point {0, SCREEN_HEIGHT/3- 0},       // B -- green 
    Point {SCREEN_WIDTH/4, SCREEN_HEIGHT/3},       // C - blue 
    Point {SCREEN_WIDTH/3, SCREEN_HEIGHT/6},       // D - yellow 
              
 Point {SCREEN_WIDTH/8, SCREEN_HEIGHT/6 + SCREEN_HEIGHT/4},       // A
                                                                  //
Point {0, SCREEN_HEIGHT/3 + SCREEN_HEIGHT/4},                    // B -- green 
Point {SCREEN_WIDTH/4, SCREEN_HEIGHT/3 + SCREEN_HEIGHT/4},       // C - blue 
Point {SCREEN_WIDTH/3, SCREEN_HEIGHT/6 + SCREEN_HEIGHT/4},       // D - yellow 
/*
    Point {0 + dx, 0 + dy},   // A + c
    Point {0 + dx, 0 + dy},   // B + c
    Point {0 + dx, 4*0 + dy},   // C + c
    Point {0 + dx, 4*0 + dy},   // D + c*/
};
  std::vector<Point> cartesianPoints = {
    Point{0, SCREEN_HEIGHT/2}, // -x 
    Point{SCREEN_WIDTH, SCREEN_HEIGHT/2},  // x
    Point{SCREEN_WIDTH/2, SCREEN_HEIGHT}, // -y
    Point{SCREEN_WIDTH/2, 0}, // y
    Point{SCREEN_WIDTH/2,SCREEN_HEIGHT/2} // 0
  };
// 0-1 2-3



  
  public:
  Cube() { // Usa point

    for (int i=0; i<8; i++) {
      sfCubePoints.emplace_back();  // Adiciona um sfPoint padrão
      //sfCubePoints[i].setFillColor(sf::Color::Red);
      sfCubePoints[i].setPosition({cubePoints[i].x+700, cubePoints[i].y}); 
    }
   sfCubePoints[0].setFillColor(sf::Color::Red);
   sfCubePoints[1].setFillColor(sf::Color::Green);
   sfCubePoints[2].setFillColor(sf::Color::Blue);
   sfCubePoints[3].setFillColor(sf::Color::Yellow);



    for (int j=0;j<5;j++) {

      sfCartesianPoints.emplace_back();  // Adiciona um sfPoint padrão
      //sfCartesianPoints[j].setFillColor(sf::Color::Red);
      sfCartesianPoints[j].setPosition({cartesianPoints[j].x, cartesianPoints[j].y});
    }
    //sfCubePoints[0].setFillColor(sf::Color::Green) ;
  }
  

  void configureCartesianLines() {
    cartesianLines = {
        sf::Vertex{sf::Vector2f(sfCartesianPoints[0].getPosition().x, sfCartesianPoints[0].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCartesianPoints[1].getPosition().x, sfCartesianPoints[1].getPosition().y)},

  
      sf::Vertex{sf::Vector2f(sfCartesianPoints[2].getPosition().x, sfCartesianPoints[2].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCartesianPoints[3].getPosition().x, sfCartesianPoints[3].getPosition().y)},

    };
  
  }

  void configureCubeLines() {
      cubeLines = {
      // Linha 1 (A -> B)
      sf::Vertex{sf::Vector2f(sfCubePoints[0].getPosition().x, sfCubePoints[0].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[1].getPosition().x, sfCubePoints[1].getPosition().y)},

      // Linha 2 (C -> D)
      sf::Vertex{sf::Vector2f(sfCubePoints[2].getPosition().x, sfCubePoints[2].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[3].getPosition().x, sfCubePoints[3].getPosition().y)},

      // Linha 3 (E -> F)
      sf::Vertex{sf::Vector2f(sfCubePoints[4].getPosition().x, sfCubePoints[4].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[5].getPosition().x, sfCubePoints[5].getPosition().y)},

      // Linha 4 (G -> H)
      sf::Vertex{sf::Vector2f(sfCubePoints[6].getPosition().x, sfCubePoints[6].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[7].getPosition().x, sfCubePoints[7].getPosition().y)},

      // Linha 5 (A -> D)
      sf::Vertex{sf::Vector2f(sfCubePoints[0].getPosition().x, sfCubePoints[0].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[3].getPosition().x, sfCubePoints[3].getPosition().y)},

      // Linha 6 (B -> C)
      sf::Vertex{sf::Vector2f(sfCubePoints[1].getPosition().x, sfCubePoints[1].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[2].getPosition().x, sfCubePoints[2].getPosition().y)},

      // Linha 7 (E -> H)
      sf::Vertex{sf::Vector2f(sfCubePoints[4].getPosition().x, sfCubePoints[4].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[7].getPosition().x, sfCubePoints[7].getPosition().y)},

      // Linha 8 (F -> G)
      sf::Vertex{sf::Vector2f(sfCubePoints[5].getPosition().x, sfCubePoints[5].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[6].getPosition().x, sfCubePoints[6].getPosition().y)},
///*
      // Linha 9 (A -> E)
      sf::Vertex{sf::Vector2f(sfCubePoints[0].getPosition().x, sfCubePoints[0].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[4].getPosition().x, sfCubePoints[4].getPosition().y)},

      // Linha 5 (F -> B)
      sf::Vertex{sf::Vector2f(sfCubePoints[5].getPosition().x, sfCubePoints[5].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[1].getPosition().x, sfCubePoints[1].getPosition().y)},

      // Linha 11 (H -> D)
      sf::Vertex{sf::Vector2f(sfCubePoints[7].getPosition().x, sfCubePoints[7].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[3].getPosition().x, sfCubePoints[3].getPosition().y)},

      // Linha 12 (C -> G)
      sf::Vertex{sf::Vector2f(sfCubePoints[2].getPosition().x, sfCubePoints[2].getPosition().y)},
      sf::Vertex{sf::Vector2f(sfCubePoints[6].getPosition().x, sfCubePoints[6].getPosition().y)}//*/
      };
  }


  void configurePoints(int size, std::vector<sfPoint> &arrayOfPoints) {
    float ratio=0;
    if (size==8) ratio = smallRatio;

    for (int i=0; i<size; i++) {
       arrayOfPoints[i].configure({
          arrayOfPoints[i].getPosition().x,
          arrayOfPoints[i].getPosition().y}, 
          ratio, 
          arrayOfPoints[i].getFillColor()
      ); 
    }
  } 

 void drawPoints( std::vector<sfPoint> &arrayOfPoints, std::vector<sf::Vertex> lines) {
    configurePoints(arrayOfPoints.size(), arrayOfPoints); 
    if (arrayOfPoints.size() == 8) { configureCubeLines(); 
    } else { configureCartesianLines(); }
    window.draw(lines.data(), lines.size(), sf::PrimitiveType::Lines);
    for (int i=0; i<arrayOfPoints.size(); i++) {
      //std::cout << "OI:I" << std::endl;
      window.draw(arrayOfPoints[i]); 
    } 
  } 
  void drawCube() {
    drawPoints(sfCubePoints, cubeLines);   
  }
  
  void debug() {
 //drawCube();

  for (int i=0; i < 8;i++) {
  sfCubePoints[i].configure({
          sfCubePoints[i].getPosition().x,
          sfCubePoints[i].getPosition().y}, 
          smallRatio, 
          sfCubePoints[i].getFillColor()
      ); 

    sf::Transform transform;
    sf::Angle angle = sf::degrees(theta);
    transform.rotate(angle, {SCREEN_WIDTH/2, SCREEN_HEIGHT/2} );
    

    //transform.rotate()
    configureCubeLines();
    window.draw(cubeLines.data(), cubeLines.size(), sf::PrimitiveType::Lines, transform);

   theta = theta+0.005;

  }

  //window.draw(c, transform);  
   
  }
  void drawCartesianPlane() {
    drawPoints(sfCartesianPoints, cartesianLines);
  }
  void start() {
    // Tentar rotacionar o paralelogramo das bases (ABCD,EFGH), e nao o cubo em si
int count = 0;
    window = sf::RenderWindow(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "CMake SFML Project");
    window.setFramerateLimit(144);
 sf::Clock clock;
    while (window.isOpen()) {
      while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
          window.close();
        }
      }
            
        window.clear();
      //drawCube();
      //rotate();
        drawCartesianPlane();
            debug();
           /*sf::Transform transform;
//float theta = sf::Angle; // graus
sf::Angle theta = sf::degrees(0.0005);

//tsf::Angle theta = sf::Angle::
transform.rotate(theta, {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});

sf::Vector2f original = {100.f, 100.f}; // ponto que você quer rotacionar
sf::Vector2f rotated = transform.transformPoint(original);

// Agora `rotated` tem o valor do ponto rotacionado
std::cout << "Rotated x: " << rotated.x << ", y: " << rotated.y << "\n"; 
std::cout << "Rotated x: " << rotatePoint(100, 100, 0.0005).x << ", y: " << rotatePoint(100, 100, 0.0005).y << "\n"; 
*/

        window.display();
    }
  }

};



int main() {
  auto cube = new Cube;
  cube->start();
  return 0;

   
}
