#include <iostream>

class Shape {		//�������̽� ����
public:
	virtual void draw() const = 0;
};

class Rectangle : public Shape {		//shape�� ����Ͽ� Rectangle ����
public:
	void draw() const override {
		std::cout << "Shape: Rectangle" << std::endl;
	}
};

class Circle : public Shape {		//shape�� ����Ͽ� Circle ����
public:
	void draw() const override {
		std::cout << "Shape: Circle" << std::endl;
	}
};

class ShapeDecorator : public Shape {		//Shape�� ���ڷ����� ����
protected:
	Shape* decoratedShape;

public:
	ShapeDecorator(Shape* shape) : decoratedShape(shape) {}

	void draw() const override {
		decoratedShape->draw();
	}
};

class RedShapeDecorator : public ShapeDecorator {	//RedShape�� ���ڷ����� ����
public:
	RedShapeDecorator(Shape* shape) : ShapeDecorator(shape) {}

	void draw() const override {		//draw�� override �Ͽ�
		decoratedShape->draw();			//������ draw�� ȣ���ϰ�
		setRedBorder();					//Border�� ȣ��
	}

	void setRedBorder() const {
		std::cout << "Border Color: Red" << std::endl;		//Border�� ���� ���
	}
};

int main() {
	Shape* circle = new Circle();							//circle ����
	std::cout << "Circle with normal border" << std::endl;
	circle->draw();											//circle�� draw() ȣ��
	std::cout << std::endl;

	Shape* redCircle = new RedShapeDecorator(new Circle());	//redCircle ����
	std::cout << "Circle with red border" << std::endl;
	redCircle->draw();										//redCircle�� draw() ȣ��
	std::cout << std::endl;

	Shape* redRectangle = new RedShapeDecorator(new Rectangle());	//redRectangle ����
	std::cout << "Red Rectangle with red Border:" << std::endl;
	redRectangle->draw();										//redRectangle�� draw() ȣ��

	delete circle;
	delete redCircle;
	delete redRectangle;

	return 0;
}