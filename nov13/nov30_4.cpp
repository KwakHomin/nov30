#include <iostream>

class Shape {		//인터페이스 구현
public:
	virtual void draw() const = 0;
};

class Rectangle : public Shape {		//shape을 상속하여 Rectangle 구현
public:
	void draw() const override {
		std::cout << "Shape: Rectangle" << std::endl;
	}
};

class Circle : public Shape {		//shape을 상속하여 Circle 구현
public:
	void draw() const override {
		std::cout << "Shape: Circle" << std::endl;
	}
};

class ShapeDecorator : public Shape {		//Shape의 데코레이터 구현
protected:
	Shape* decoratedShape;

public:
	ShapeDecorator(Shape* shape) : decoratedShape(shape) {}

	void draw() const override {
		decoratedShape->draw();
	}
};

class RedShapeDecorator : public ShapeDecorator {	//RedShape의 데코레이터 구현
public:
	RedShapeDecorator(Shape* shape) : ShapeDecorator(shape) {}

	void draw() const override {		//draw를 override 하여
		decoratedShape->draw();			//원래의 draw를 호출하고
		setRedBorder();					//Border를 호출
	}

	void setRedBorder() const {
		std::cout << "Border Color: Red" << std::endl;		//Border의 색을 출력
	}
};

int main() {
	Shape* circle = new Circle();							//circle 선언
	std::cout << "Circle with normal border" << std::endl;
	circle->draw();											//circle의 draw() 호출
	std::cout << std::endl;

	Shape* redCircle = new RedShapeDecorator(new Circle());	//redCircle 선언
	std::cout << "Circle with red border" << std::endl;
	redCircle->draw();										//redCircle의 draw() 호출
	std::cout << std::endl;

	Shape* redRectangle = new RedShapeDecorator(new Rectangle());	//redRectangle 선언
	std::cout << "Red Rectangle with red Border:" << std::endl;
	redRectangle->draw();										//redRectangle의 draw() 호출

	delete circle;
	delete redCircle;
	delete redRectangle;

	return 0;
}